#include <fstream>
#include <iostream>
#include <array>
#include <vector>

using namespace std;

using Image = vector<vector<char>>;

struct		Problem
{
	array<char, 512>		lookup;
	Image					image;
};

void		image_print(const Image &im) {
	for (const auto &l: im) {
		for (const auto &c: l) {
			cout << c;
		}
		cout << endl;
	}
}

Image		image_extend(const Image &im, size_t offset) {
	Image			res;
	size_t			width;
	vector<char>	lineEmpty;
	vector<char>	lineIm;

	width = im[0].size();

	for (size_t i = 0; i < width + 2 * offset; ++i) {
		lineEmpty.push_back('.');
	}

	for (size_t i = 0; i < offset; ++i) {
		res.push_back(lineEmpty);
	}

	for (const auto &l: im) {
		lineIm.clear();
		for (size_t i = 0; i < offset; ++i)
			lineIm.push_back('.');
		for (const char &c: l)
			lineIm.push_back(c);
		for (size_t i = 0; i < offset; ++i)
			lineIm.push_back('.');
		res.push_back(lineIm);
	}

	for (size_t i = 0; i < offset; ++i) {
		res.push_back(lineEmpty);
	}

	return res;
}

static const pair<int, int> FILTER_CASES[9] = {
	{-1, -1}, {-1, 0}, {-1, 1},
	{0, -1}, {0, 0}, {0, 1},
	{1, -1}, {1, 0}, {1, 1}
};

#include <bitset>

Image		image_enhance(const Image &im, const Problem &pb, char outAssumed) {
	Image			res;
	vector<char>	lineRes;
	uint16_t		bin;

	for (int i = 0; i < im.size(); ++i) {
		lineRes.clear();
		for (int j = 0; j < im[0].size(); ++j) {
			bin = 0;

			for (const auto &p: FILTER_CASES) {
				bin = bin << 1;
				int ii = i + p.first;
				int jj = j + p.second;

				if (ii >= 0 && ii < im.size() && jj >= 0 && jj < im[0].size()) {
					if (im[ii][jj] == '#') bin += 1;
				} else {
					if (outAssumed == '#') bin += 1;
				}
			}

			lineRes.push_back(pb.lookup[bin]);
		}
		res.push_back(lineRes);
	}

	return res;
}

Problem		loadInput(void) {
	Problem			pb;
	fstream			input;
	string			line;
	vector<char>	lineIm;

	input.open("../input.txt");

	getline(input, line);

	for (size_t i = 0; i < 512; ++i) {
		pb.lookup[i] = line[i];
	}

	getline(input, line);
	while (getline(input, line)) {
		lineIm.clear();
		for (const char &c: line) {
			lineIm.push_back(c);
		}
		pb.image.push_back(lineIm);
	}

	input.close();

	return pb;
}

int		main(void) {
	Problem		pb;
	Image		im;
	uint64_t	answer = 0;

	pb = loadInput();

	im = pb.image;
	im = image_extend(im, 4);
	im = image_enhance(im, pb, '.');
	im = image_enhance(im, pb, pb.lookup[0]);

	for (const auto &l: im) {
		for (const auto &c: l) {
			if (c == '#') answer++;
		}
	}

	cout << "answer: " << answer << endl;

	return 0;
}
