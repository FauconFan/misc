#include <fstream>
#include <iostream>

using namespace std;

int main() {
	fstream		input;
	int			history_depths[4];
	int			counter;

	counter = 0;

	input.open("../input.txt");

	for (size_t i = 0; i <= 2; ++i) {
		input >> history_depths[i];
	}

	while (input >> history_depths[3]) {
		if (history_depths[3] > history_depths[0]) {
			counter += 1;
		}

		for (size_t i = 0; i <= 2; ++i) {
			history_depths[i] = history_depths[i + 1];
		}
	}

	cout << "counter: " << counter << endl;
	return 0;
}