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

int		main(void) {
	t_problem							pb;
	set<pair<uint32_t, uint32_t>>		dots;
	set<pair<uint32_t, uint32_t>>		next_dots;
	uint32_t							cut_along;

	pb = loadInput();

	// for (const auto &p: pb.points) {
	// 	cout << p.first << " " << p.second << endl;
	// }
	// for (const auto &p: pb.folds) {
	// 	cout << p.first << " " << p.second << endl;
	// }

	for (const auto &p: pb.points) {
		dots.insert(p);
	}

	if (pb.folds.front().first == CUT_ALONG_Y) {
		cut_along = pb.folds.front().second;
		for (const auto &p: dots) {
			if (p.second > cut_along) {
				next_dots.insert(make_pair(p.first, (cut_along - (p.second - cut_along))));
			} else {
				next_dots.insert(p);
			}
		}
	} else {
		cut_along = pb.folds.front().second;
		for (const auto &p: dots) {
			if (p.first > cut_along) {
				next_dots.insert(make_pair((cut_along - (p.first - cut_along)), p.second));
			} else {
				next_dots.insert(p);
			}
		}
	}

	cout << "answer: " << next_dots.size() << endl;

	return 0;
}