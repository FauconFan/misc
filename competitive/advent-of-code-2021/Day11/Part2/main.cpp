#include <fstream>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<uint8_t>>		loadInput(void) {
	fstream					input;
	vector<vector<uint8_t>>	vec;
	vector<uint8_t>			lineVec;
	string					line;

	input.open("../input.txt");

	while (getline(input, line)) {
		lineVec.clear();

		for (const auto &c: line) {
			lineVec.push_back(c - '0');
		}
		vec.push_back(lineVec);
	}

	input.close();
	return vec;
}

bool	inBounds(int i, int j, const vector<vector<uint8_t>> &vec) {
	if (i < 0 || i >= vec.size()) return false;
	if (j < 0 || j >= vec[0].size()) return false;
	return true;
}

static const pair<int, int> ADJACENT_COORDS[] = {
	make_pair(-1, -1),
	make_pair(-1, 0),
	make_pair(-1, 1),
	make_pair(0, -1),
	make_pair(0, 1),
	make_pair(1, -1),
	make_pair(1, 0),
	make_pair(1, 1)
};

int		main(void) {
	vector<vector<uint8_t>>			vec;
	stack<pair<int, int>>			flashed;
	int								step = 1;
	bool							synchronized = false;

	vec = loadInput();

	// cout << "Before any steps:" << endl;
	// for (const auto &line: vec) {
	// 	for (const auto &i: line) {
	// 		cout << static_cast<int>(i);
	// 	}
	// 	cout << endl;
	// }

	for (; ; ++step) {

		for (int i = 0; i < vec.size(); ++i) {
			for (int j = 0; j < vec[0].size(); ++j) {
				if (vec[i][j] == 9) {
					flashed.push(make_pair(i, j));
					vec[i][j] = 0;
				} else {
					vec[i][j] += 1;
				}
			}
		}

		while (!flashed.empty()) {
			int		i, j, ii, jj;

			i = flashed.top().first;
			j = flashed.top().second;
			flashed.pop();

			for (const auto &adjacent: ADJACENT_COORDS) {
				ii = i + adjacent.first;
				jj = j + adjacent.second;

				if (inBounds(ii, jj, vec) && vec[ii][jj] != 0) {
					if (vec[ii][jj] == 9) {
						flashed.push(make_pair(ii, jj));
						vec[ii][jj] = 0;
					} else {
						vec[ii][jj] += 1;
					}
				}
			}
		}

		synchronized = true;

		for (int i = 0; i < vec.size(); ++i) {
			for (int j = 0; j < vec[0].size(); ++j) {
				if (vec[i][j] != 0) {
					synchronized = false;
					break;
				}
			}
			if (!synchronized) break;
		}

		if (synchronized) break;

		// cout << endl;
		// cout << "After step " << step << ":" << endl;
		// for (const auto &line: vec) {
		// 	for (const auto &i: line) {
		// 		cout << static_cast<int>(i);
		// 	}
		// 	cout << endl;
		// }
	}

	cout << "answer: " << step << endl;

	return 0;
}