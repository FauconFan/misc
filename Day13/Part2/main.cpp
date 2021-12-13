#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

typedef enum		e_cut_along
{
	CUT_ALONG_X,
	CUT_ALONG_Y
}					t_cut_along;

ostream		&operator<<(ostream &os, const t_cut_along &cut) {
	switch (cut) {
		case CUT_ALONG_X:
			os << "Fold along X";
			break;
		case CUT_ALONG_Y:
			os << "Fold along Y";
			break;
	}
	return os;
}

typedef struct		s_problem
{
	vector<pair<uint32_t, uint32_t>>	points;
	vector<pair<t_cut_along, uint32_t>>	folds;
}					t_problem;

t_problem		loadInput()
{
	t_problem			pb;
	fstream				input;
	string				line;
	uint32_t			buffers[2];
	size_t				pos;
	t_cut_along			buffer_cut;

	input.open("../input.txt");

	while (getline(input, line)) {
		if (line.length() == 0) break;

		pos = line.find(',');
		buffers[0] = stoi(line.substr(0, pos));
		buffers[1] = stoi(line.substr(pos + 1));
		pb.points.push_back(make_pair(buffers[0], buffers[1]));
	}

	while (getline(input, line)) {
		pos = line.find('=');

		buffer_cut = CUT_ALONG_X;
		if (line[pos - 1] == 'y') buffer_cut = CUT_ALONG_Y;
		buffers[0] = stoi(line.substr(pos + 1));
		pb.folds.push_back(make_pair(buffer_cut, buffers[0]));
	}

	input.close();
	return pb;
}

void	print_dots(const set<pair<uint32_t, uint32_t>> &dots) {
	vector<vector<char>>	map;
	size_t					bounds[2];

	bounds[0] = 0;
	bounds[1] = 0;

	for (const auto &dot: dots) {
		bounds[0] = max(bounds[0], static_cast<size_t>(dot.first));
		bounds[1] = max(bounds[1], static_cast<size_t>(dot.second));
	}

	bounds[0]++;
	bounds[1]++;

	for (size_t j = 0; j < bounds[1]; ++j) {
		vector<char>		line;
		for (size_t i = 0; i < bounds[0]; ++i) {
			line.push_back(' ');
		}
		map.push_back(line);
	}


	for (const auto &dot: dots) {
		map[dot.second][dot.first] = '#';
	}

	cout << "answer: " << endl;
	for (size_t j = 0; j < bounds[1]; ++j) {
		for (size_t i = 0; i < bounds[0]; ++i) {
			cout << map[j][i];
		}
		cout << endl;
	}
}

int		main(void) {
	t_problem							pb;
	set<pair<uint32_t, uint32_t>>		dots;
	set<pair<uint32_t, uint32_t>>		next_dots;
	uint32_t							cut_along;

	pb = loadInput();

	for (const auto &p: pb.points) {
		dots.insert(p);
	}

	for (const auto &cut: pb.folds) {
		cut_along = cut.second;
		if (cut.first == CUT_ALONG_Y) {
			for (const auto &p: dots) {
				if (p.second > cut_along) {
					next_dots.insert(make_pair(p.first, (cut_along - (p.second - cut_along))));
				} else {
					next_dots.insert(p);
				}
			}
		} else {
			for (const auto &p: dots) {
				if (p.first > cut_along) {
					next_dots.insert(make_pair((cut_along - (p.first - cut_along)), p.second));
				} else {
					next_dots.insert(p);
				}
			}
		}

		dots.swap(next_dots);
		next_dots.clear();
	}

	print_dots(dots);

	return 0;
}