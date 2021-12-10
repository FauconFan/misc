#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <optional>

using namespace std;

typedef struct		s_line
{
	uint32_t	x1;
	uint32_t	y1;
	uint32_t	x2;
	uint32_t	y2;
}					t_line;

ostream&	operator <<(ostream & os, const t_line &line) {
	return os
			<< line.x1 << "," << line.y1 << " -> "
			<< line.x2 << "," << line.y2;
}

vector<t_line>	loadInput(void) {
	fstream				input;
	t_line				line;
	char				useless[4];
	vector<t_line>		vec;

	input.open("../input.txt");

	while (true) {
		input >> line.x1 >> useless[0] >> line.y1 >> useless[1] >> useless[2] >> line.x2 >> useless[3] >> line.y2;

		if (input.fail()) break;

		if (line.x1 == line.x2 || line.y1 == line.y2)
			vec.push_back(line);

		if (input.eof()) break;
	}
	input.close();

	return vec;
}

int				main(void) {
	vector<t_line>		vec;
	uint8_t				map[1000][1000];
	uint16_t			dir[2]; // dx dy
	uint16_t			actu[2]; // x y
	uint32_t			res;

	vec = loadInput();

	for (size_t i = 0; i < 1000; ++i) {
		for (size_t j = 0; j < 1000; ++j) {
			map[i][j] = 0;
		}
	}

	for (const auto &line: vec) {
		actu[0] = line.x1;
		actu[1] = line.y1;

		dir[0] = 0;
		dir[1] = 0;

		if (line.x1 != line.x2) dir[0] = (line.x1 < line.x2) ? 1 : -1;
		if (line.y1 != line.y2) dir[1] = (line.y1 < line.y2) ? 1 : -1;

		while (true) {
			map[actu[0]][actu[1]] += 1;
			if (actu[0] == line.x2 && actu[1] == line.y2) break;

			actu[0] += dir[0];
			actu[1] += dir[1];
		}
	}

	res = 0;

	for (size_t i = 0; i < 1000; ++i) {
		for (size_t j = 0; j < 1000; ++j) {
			if (map[i][j] > 1) res++;
		}
	}

	cout << "answer: " << res << endl;

	return 0;
}
