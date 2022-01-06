#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

vector<uint32_t>		loadInput(void) {
	fstream				input;
	vector<uint32_t>	vec;
	uint32_t			cand;
	char				useless;

	input.open("../input.txt");

	while (true) {
		input >> cand;

		if (input.fail()) break;

		vec.push_back(cand);

		input >> useless;

		if (input.eof() || input.fail()) break;
	}

	input.close();
	return vec;
}

uint32_t	getSumDistance(const vector<uint32_t> &vec, uint32_t target) {
	uint32_t	res = 0;

	for (const auto &v: vec) {
		res += (v < target) ? target - v: v - target;
	}
	return res;
}

int	main(void) {
	vector<uint32_t>			vec;
	uint32_t					guess = 0;
	map<uint32_t, uint32_t>		dict;

	vec = loadInput();

	for (const auto &v: vec) {
		guess += v;
	}

	guess /= vec.size();

	cout << "guess (begin): " << guess << endl;
	dict[guess] = getSumDistance(vec, guess);

	while (true) {
		uint32_t left, right, actual;
		auto searchLeft = dict.find(guess - 1);
		auto searchRight = dict.find(guess + 1);

		if (searchLeft == dict.end()) {
			left = getSumDistance(vec, guess - 1);
			dict[guess - 1] = left;
		} else {
			left = searchLeft->second;
		}

		if (searchRight == dict.end()) {
			right = getSumDistance(vec, guess + 1);
			dict[guess + 1] = right;
		} else {
			right = searchRight->second;
		}

		actual = dict[guess];

		if (actual < left && actual < right) break;
		if (left < actual) guess--;
		else guess++;
	}

	cout << "answer: " << dict[guess] << endl;
	return 0;
}