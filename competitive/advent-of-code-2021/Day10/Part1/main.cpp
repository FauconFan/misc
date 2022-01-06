#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

static const string PAIRS[] = {
	"()", "[]", "{}", "<>"
};

static const pair<char, uint32_t> POINTS[] = {
	make_pair(')', 3),
	make_pair(']', 57),
	make_pair('}', 1197),
	make_pair('>', 25137)
};

vector<string>	loadInput(void) {
	fstream			input;
	vector<string>	vec;
	string			line;

	input.open("../input.txt");

	while (getline(input, line)) {
		vec.push_back(line);
	}

	input.close();
	return vec;
}

int		main(void) {
	vector<string>		vec;
	uint32_t			answer = 0;

	vec = loadInput();

	for (const auto &line: vec) {
		stack<char>		expectedCharacters;
		bool			earlyStop = false;

		for (const char &c: line) {
			for (const auto &pair: PAIRS) {
				if (pair[0] == c) {
					expectedCharacters.push(pair[1]);
					break;
				} else if (pair[1] == c) {
					if (expectedCharacters.top() == c) {
						expectedCharacters.pop();
						break;
					} else {
						for (const auto &point: POINTS) {
							if (point.first == c) {
								answer += point.second;
								break;
							}
						}
						earlyStop = true;
					}
				}
			}
			if (earlyStop) break;
		}
		
	}

	cout << "answer: " << answer << endl;

	return 0;
}