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
	uint32_t	tmp = 0;

	for (const auto &v: vec) {
		tmp = (v < target) ? target - v: v - target;
		res += tmp * (tmp + 1) / 2;
	}
	return res;
}

int	main(void) {
	vector<uint32_t>			vec;
	vector<uint32_t>			fuel;
	uint32_t					bounds[2];
	uint32_t					answer;

	vec = loadInput();

	bounds[0] = vec[0];
	bounds[1] = vec[0];

	for (const auto &v: vec) {
		bounds[0] = min(bounds[0], v);
		bounds[1] = max(bounds[1], v);
	}

	for (uint32_t cand = bounds[0]; cand < bounds[1]; ++cand) {
		fuel.push_back(getSumDistance(vec, cand));
	}

	answer = fuel[0];

	for (auto const &f: fuel) {
		answer = min(answer, f);
	}

	cout << "answer: " << answer << endl;

	return 0;
}