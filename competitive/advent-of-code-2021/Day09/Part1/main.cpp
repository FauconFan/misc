#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>>		loadInput(void) {
	fstream					input;
	vector<vector<int>>		vec;
	vector<int>				lineInt;
	string					line;

	input.open("../input.txt");

	while (getline(input, line)) {
		lineInt.clear();
		for (const auto &c: line) {
			lineInt.push_back(c - '0');
		}

		vec.push_back(lineInt);
	}

	input.close();
	return vec;
}

int						main(void) {
	vector<vector<int>>		vec;
	uint32_t				answer = 0;

	vec = loadInput();

	for (size_t i = 0; i < vec.size(); ++i) {
		for (size_t j = 0; j < vec[0].size(); ++j) {
			if (!(	(i != 0					&& vec[i][j] >= vec[i - 1][j]) ||
					(j != 0					&& vec[i][j] >= vec[i][j - 1]) ||
					(i != vec.size() - 1	&& vec[i][j] >= vec[i + 1][j]) ||
					(j != vec[0].size() - 1	&& vec[i][j] >= vec[i][j + 1]))) {
				answer += 1 + vec[i][j];
			}
		}
	}

	cout << "answer: " << answer << endl;

	return 0;
}