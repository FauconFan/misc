#include <iostream>
#include <fstream>

using namespace std;

int	main(void) {
	fstream		input;
	int			depth    = 0;
	int			position = 0;

	string		instruction;
	int			operand;

	input.open("../input.txt");

	while (true) {
		instruction = "";
		operand = 0;

		input >> instruction >> operand;

		if (input.fail()) {
			break;
		}

		if (instruction == "forward") {
			position += operand;
		} else if (instruction == "down") {
			depth += operand;
		} else if (instruction == "up") {
			depth -= operand;
		} else {
			cerr << "Unseen instruction: " << instruction << endl;
		}

		if (input.eof()) {
			break;
		}
	}

	cerr << "position: " << position << endl;
	cerr << "depth: " << depth << endl;

	cout << "answer: " << (position * depth) << endl;

	return 0;
}