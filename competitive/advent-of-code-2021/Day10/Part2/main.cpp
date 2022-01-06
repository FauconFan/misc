#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

static const string PAIRS[] = {
	"()", "[]", "{}", "<>"
};

static const pair<char, uint64_t> POINTS[] = {
	make_pair(')', 1),
	make_pair(']', 2),
	make_pair('}', 3),
	make_pair('>', 4)
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
	uint64_t			answer = 0;
	vector<uint64_t>	allScores;

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
						earlyStop = true;
					}
				}
			}
			if (earlyStop) break;
		}

		if (!earlyStop) {
			uint64_t	currentAnswer = 0;

			while (!expectedCharacters.empty()) {
				currentAnswer *= 5;
				for (const auto &pt: POINTS) {
					if (expectedCharacters.top() == pt.first) {
						currentAnswer += pt.second;
						break;
					}
				}
				expectedCharacters.pop();
			}
			allScores.push_back(currentAnswer);
		}
	}

	sort(allScores.begin(), allScores.end());

	answer = allScores[allScores.size() / 2];

	cout << "answer: " << answer << endl;

	return 0;
}