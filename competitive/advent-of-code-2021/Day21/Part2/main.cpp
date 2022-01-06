#include <iostream>
#include <fstream>
#include <vector>
#include <map>

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

struct		resCounter {
	uint64_t	nb_wins_player1;
	uint64_t	nb_wins_player2;

	resCounter() {
		nb_wins_player1 = 0;
		nb_wins_player2 = 0;
	}

	resCounter	&operator=(const resCounter &rhs) {

		if (this != &rhs) {
			nb_wins_player1 = rhs.nb_wins_player1;
			nb_wins_player2 = rhs.nb_wins_player2;
		}

		return *this;
	}

	resCounter	operator+(const resCounter &rhs) {
		resCounter	res;

		res.nb_wins_player1 = nb_wins_player1 + rhs.nb_wins_player1;
		res.nb_wins_player2 = nb_wins_player2 + rhs.nb_wins_player2;

		return res;
	}

	resCounter	operator*(uint16_t mult) {
		resCounter	res;

		res.nb_wins_player1 = nb_wins_player1 * static_cast<uint64_t>(mult);
		res.nb_wins_player2 = nb_wins_player2 * static_cast<uint64_t>(mult);
		return res;
	}
};

ostream	&operator<<(ostream &os, const resCounter &res) {
	return os << "(" << res.nb_wins_player1 << ", " << res.nb_wins_player2 << ")";
}

struct		state {
	uint16_t	score1;
	uint16_t	pos1;
	uint16_t	score2;
	uint16_t	pos2;
	bool		turnPlayer1;

	state() {
		score1 = 0;
		score2 = 0;
		pos1 = 0;
		pos2 = 0;
		turnPlayer1 = true;
	}

	state(const state &rhs) {
		score1 = rhs.score1;
		score2 = rhs.score2;
		pos1 = rhs.pos1;
		pos2 = rhs.pos2;
		turnPlayer1 = rhs.turnPlayer1;
	}

	void		switchTurn(void) {
		turnPlayer1 = !turnPlayer1;
	}

	bool		addPos(uint16_t dpos) {
		if (turnPlayer1) {
			pos1 += dpos;
			while (pos1 > 10) pos1 -= 10;
			score1 += pos1;
			if (score1 >= 21) return true;
			return false;
		}
		pos2 += dpos;
		while (pos2 > 10) pos2 -= 10;
		score2 += pos2;
		if (score2 >= 21) return true;
		return false;
	}
};

ostream		&operator<<(ostream &os, const state &s) {
	return os << "Player" << (s.turnPlayer1 ? "1" : "2")
			<< " (p1: score: " << s.score1 << ", pos: " << s.pos1 << ") "
			<< " (p2: score: " << s.score2 << ", pos: " << s.pos2 << ")";
}

vector<pair<uint16_t, uint16_t>> generateOutcomeUniverse() {
	vector<pair<uint16_t, uint16_t>>	res;
	map<uint16_t, uint16_t>				tmp;

	for (uint16_t i = 3; i <= 9; ++i)
		tmp[i] = 0;

	for (uint16_t i = 1; i <= 3; ++i) {
		for (uint16_t j = 1; j <= 3; ++j) {
			for (uint16_t k = 1; k <= 3; ++k) {
				tmp[i + j + k]++;
			}
		}
	}

	for (const auto &p: tmp) {
		res.push_back(p);
	}

	return res;
}

resCounter		count(
		const vector<pair<uint16_t, uint16_t>> &outcomesDiracDice,
		const state &init_state,
		uint16_t depth = 0) {
	resCounter		res;

	for (const auto &p: outcomesDiracDice) {
		state	currentState = init_state;

		if (currentState.addPos(p.first)) {
			if (init_state.turnPlayer1) res.nb_wins_player1 += p.second;
			else res.nb_wins_player2 += p.second;
		} else {
			currentState.switchTurn();
			auto mm = count(outcomesDiracDice, currentState, depth + 1);
			auto m = mm * p.second;
			res = res + m;
		}
	}

	return res;
}

int			main(void) {
	Problem		pb;
	state		state;
	resCounter	resCounter;
	uint64_t	answer;

	vector<pair<uint16_t, uint16_t>> outcomesDiracDice;

	pb = loadInput();

	state.pos1 = pb.start_position_1;
	state.pos2 = pb.start_position_2;
	state.score1 = 0;
	state.score2 = 0;
	state.turnPlayer1 = true;

	outcomesDiracDice = generateOutcomeUniverse();
	resCounter = count(outcomesDiracDice, state);

	answer = max(resCounter.nb_wins_player1, resCounter.nb_wins_player2);

	cout << "answer: " << answer << endl;

	return 0;
}
