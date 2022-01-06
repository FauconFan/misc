#include <iostream>
#include <fstream>
#include <array>

using namespace std;

array<uint32_t, 9>	loadInput(void) {
	fstream				input;
	array<uint32_t, 9>	timeValues;
	uint32_t			cand;
	char				useless;

	input.open("../input.txt");

	while (true) {
		input >> cand;

		if (input.fail()) break;

		timeValues[cand]++;

		input >> useless;

		if (input.eof() || input.fail()) break;
	}

	input.close();

	return timeValues;
}

int main(void) {
	array<uint32_t, 9>	timeValues = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	array<uint32_t, 9>	nextTimeValues = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	uint32_t			res = 0;

	timeValues = loadInput();

	for (int days = 0; days < 80; ++days) {
		for (size_t i = 8; i > 0; --i) {
			nextTimeValues[i - 1] = timeValues[i];
		}
		nextTimeValues[6] += timeValues[0];
		nextTimeValues[8] = timeValues[0];

		// cout << "Day: " << days << endl;

		// for (size_t i = 0; i < 9; ++i) {
		// 	cout << i << ": " << timeValues[i] << " -> " << nextTimeValues[i] << endl;
		// }
		// cout << endl;

		timeValues.swap(nextTimeValues);
	}

	for (size_t i = 0; i < 9; ++i) {
		res += timeValues[i];
	}

	cout << "answer: " << res << endl;

	return 0;
}
