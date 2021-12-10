#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

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
	vector<vector<int>>				vec;
	vector<pair<size_t, size_t>>	lowestPicks;
	vector<size_t>					sizes;
	uint32_t						answer = 0;

	vec = loadInput();

	for (size_t i = 0; i < vec.size(); ++i) {
		for (size_t j = 0; j < vec[0].size(); ++j) {
			if (!(	(i != 0					&& vec[i][j] >= vec[i - 1][j]) ||
					(j != 0					&& vec[i][j] >= vec[i][j - 1]) ||
					(i != vec.size() - 1	&& vec[i][j] >= vec[i + 1][j]) ||
					(j != vec[0].size() - 1	&& vec[i][j] >= vec[i][j + 1]))) {
				lowestPicks.push_back(make_pair(i, j));
			}
		}
	}

	for (const auto &lpick: lowestPicks) {
		queue<pair<size_t, size_t>>		queue;
		set<pair<size_t, size_t>>		set;

		queue.push(lpick);
		while (!queue.empty()) {
			pair<size_t, size_t> pt = queue.front();
			queue.pop();

			if (set.find(pt) != set.end()) continue;
			if (vec[pt.first][pt.second] == 9) continue;

			set.insert(pt);
			if (pt.first != 0)					queue.push(make_pair(pt.first - 1, pt.second));
			if (pt.second != 0) 				queue.push(make_pair(pt.first, pt.second - 1));
			if (pt.first != vec.size() - 1)		queue.push(make_pair(pt.first + 1, pt.second));
			if (pt.second != vec[0].size() - 1)	queue.push(make_pair(pt.first, pt.second + 1));
		}
		sizes.push_back(set.size());
	}

	sort(sizes.begin(), sizes.end());
	answer = sizes[sizes.size() - 1] * sizes[sizes.size() - 2] * sizes[sizes.size() - 3];

	cout << "answer: " << answer << endl;

	return 0;
}