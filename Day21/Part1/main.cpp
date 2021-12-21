#include <iostream>
#include <fstream>

using namespace std;

struct		Problem
{
	uint8_t		start_position_1;
	uint8_t		start_position_2;
};

Problem		loadInput(void) {
	Problem		pb;
	fstream		input;
	string		line;

	input.open("../input.txt");

	getline(input, line);
	pb.start_position_1 = stoi(line.substr(28));
	getline(input, line);
	pb.start_position_2 = stoi(line.substr(28));

	input.close();
	return pb;
}

uint16_t	DETERMINISTIC_DICE = 0;
uint16_t	NB_DICE_ROLLED = 0;

uint16_t		valueDeterministicDice(void) {
	DETERMINISTIC_DICE++;
	if (DETERMINISTIC_DICE > 100)
		DETERMINISTIC_DICE = 1;
	NB_DICE_ROLLED++;
	return DETERMINISTIC_DICE;
}

int			main(void) {
	Problem		pb;
	uint16_t	score1 = 0;
	uint16_t	score2 = 0;
	uint16_t	pos1;
	uint16_t	pos2;
	uint64_t	answer;

	pb = loadInput();

	pos1 = pb.start_position_1;
	pos2 = pb.start_position_2;

	while (true) {
		uint16_t	value1 = valueDeterministicDice() + valueDeterministicDice() + valueDeterministicDice();

		pos1 += value1;
		while (pos1 > 10) pos1 -= 10;
		score1 += pos1;

		if (score1 >= 1000) break;
		uint16_t	value2 = valueDeterministicDice() + valueDeterministicDice() + valueDeterministicDice();
	
		pos2 += value2;
		while (pos2 > 10) pos2 -= 10;
		score2 += pos2;

		if (score2 >= 1000) break;
	}

	answer = min(score1, score2) * NB_DICE_ROLLED;

	cout << "answer: " << answer << endl;

	return 0;
}
