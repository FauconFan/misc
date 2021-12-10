#include <fstream>
#include <iostream>
#include <array>
#include <vector>

using namespace std;

typedef struct		s_line
{
	string				patterns[10];
	string				digits[4];
}					t_line;

ostream &operator<<(ostream &os, const t_line & line) {
	for (const auto &s: line.patterns) {
		os << " " << s;
	}
	os << " |";
	for (const auto &s: line.digits) {
		os << " " << s;
	}
	return os;
}

vector<t_line> loadInput() {
	fstream				input;
	vector<t_line>		res;
	t_line				tmp;
	string				useless;

	input.open("../input.txt");

	while (true) {
		for (size_t i = 0; i < 10; ++i) input >> tmp.patterns[i];
		input >> useless;
		for (size_t i = 0; i < 4; ++i) input >> tmp.digits[i];

		if (input.fail()) break;

		res.push_back(tmp);

		if (input.eof()) break;
	}

	input.close();

	return res;
}

int		main(void) {
	vector<t_line>	vec;
	uint32_t		answer = 0;

	vec = loadInput();

	for (const auto &line: vec) {
		for (const auto &d: line.digits) {
			if (d.size() == 2 || d.size() == 3 || d.size() == 4 || d.size() == 7) {
				answer++;
			}
		}
	}

	cout << "answer: " << answer << endl;
	return 0;
}
