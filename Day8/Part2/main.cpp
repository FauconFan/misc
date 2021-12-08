#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct		s_line
{
	string				patterns[10];
	string				digits[4];

	void		normalize(void) {
		for (size_t i = 0; i < 10; ++i) {
			sort(patterns[i].begin(), patterns[i].end());
		}
		for (size_t i = 0; i < 4; ++i) {
			sort(digits[i].begin(), digits[i].end());
		}
	}
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

		tmp.normalize();
		res.push_back(tmp);

		if (input.eof()) break;
	}

	input.close();

	return res;
}

bool		str_contains(const string &str, const char &c) {
	for (const auto &alpha : str) {
		if (alpha == c) return true;
	}
	return false;
}

bool		str_is_included(const string &lhs, const string &rhs) {
	for (const auto &c: lhs) {
		if (!str_contains(rhs, c)) return false;
	}
	return true;
}

uint32_t	decode(const t_line &line) {
	uint32_t				res = 0;
	map<size_t, uint8_t>	indexToNum;
	size_t					numToIndex[10] = { };

	// Filling basic knowledge
	for (size_t index = 0; index < 10; ++index) {
		if (line.patterns[index].size() == 2) {
			indexToNum[index] = 1;
			numToIndex[1] = index;
		}
		else if (line.patterns[index].size() == 3) {
			indexToNum[index] = 7;
			numToIndex[7] = index;
		}
		else if (line.patterns[index].size() == 4) {
			indexToNum[index] = 4;
			numToIndex[4] = index;
		}
		else if (line.patterns[index].size() == 7) {
			indexToNum[index] = 8;
			numToIndex[8] = index;
		}
	}

	// finding three
	for (size_t index = 0; index < 10; ++index) {
		if (line.patterns[index].size() == 5) {
			bool found = true;

			for (const auto &c: line.patterns[numToIndex[1]]) {
				if (!str_contains(line.patterns[index], c)) {
					found = false;
					break;
				}
			}

			if (found) {
				indexToNum[index] = 3;
				numToIndex[3] = index;
				break;
			}
		}
	}

	// finding nine
	for (size_t index = 0; index < 10; ++index) {
		if (line.patterns[index].size() == 6) {
			if (str_is_included(line.patterns[numToIndex[3]], line.patterns[index])) {
				indexToNum[index] = 9;
				numToIndex[9] = index;
			}
		}
	}

	// finding two and five
	char e = 0;
	for (auto const &c: "abcdefg") {
		if (!str_contains(line.patterns[numToIndex[9]], c)) {
			e = c;
			break;
		}
	}
	for (size_t index = 0; index < 10; ++index) {
		if (line.patterns[index].size() == 5) {
			if (str_contains(line.patterns[index], e)) {
				indexToNum[index] = 2;
				numToIndex[2] = index;
				break;
			}
		}
	}
	for (size_t index = 0; index < 10; ++index) {
		if (line.patterns[index].size() == 5) {
			if (indexToNum.find(index) == indexToNum.end()) {
				indexToNum[index] = 5;
				numToIndex[5] = index;
				break;
			}
		}
	}

	// finding zero and six
	for (size_t index = 0; index < 10; ++index) {
		if (line.patterns[index].size() == 6 &&
				indexToNum.find(index) == indexToNum.end()) {
			if (str_is_included(line.patterns[numToIndex[5]], line.patterns[index])) {
				indexToNum[index] = 6;
				numToIndex[6] = index;
				break;
			}
		}
	}
	for (size_t index = 0; index < 10; ++index) {
		if (indexToNum.find(index) == indexToNum.end()) {
			indexToNum[index] = 0;
			numToIndex[0] = index;
			break;
		}
	}

	// cout << "------------" << endl;

	// cout << line << endl;

	// for (const auto &elem: indexToNum) {
	// 	cout << "indexToNum: " << elem.first << " " << static_cast<int>(elem.second) << endl;
	// }

	// for (int i = 0; i < 10; ++i) {
	// 	cout << "numToIndex: " << i << " " << numToIndex[i] << endl;
	// }

	for (const auto &digit: line.digits) {
		for (size_t index = 0; index < 10; ++index) {
			if (digit == line.patterns[index]) {
				res = 10 * res + indexToNum[index];
				break;
			}
		}
	}

	// cout << res << endl;

	return res;
}

int			main(void) {
	vector<t_line>	vec;
	uint32_t		answer = 0;

	vec = loadInput();

	for (const auto &line: vec) {
		answer += decode(line);
	}

	cout << "answer: " << answer << endl;
	return 0;
}
