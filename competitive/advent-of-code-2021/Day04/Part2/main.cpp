#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef		struct	s_board
{
	int			board[5][5];
	bool		marked[5][5];
}					t_board;

vector<int>							eatNumbers(fstream &input) {
	vector<int>			numbers;
	string				firstLine;
	size_t				pos;

	getline(input, firstLine);

	while ((pos = firstLine.find(',')) != string::npos) {
		numbers.push_back(stoi(firstLine.substr(0, pos)));
		firstLine.erase(0, pos + 1);
	}

	numbers.push_back(stoi(firstLine));

	return numbers;
}

vector<t_board>						eatBoards(fstream &input) {
	vector<t_board>		boards;
	t_board				board;
	int					index;
	int					actu;

	for (size_t ii = 0; ii < 5; ++ii) {
		for (size_t jj = 0; jj < 5; ++jj) {
			board.board[ii][jj] = 0;
			board.marked[ii][jj] = false;
		}
	}

	index = 0;

	while (true) {
		if (index == 25) {
			index = 0;
			boards.push_back(board);
		}

		input >> actu;

		if (input.fail()) {
			break;
		}

		board.board[index / 5][index % 5] = actu;

		index++;
	}
	return boards;
}

pair<vector<int>, vector<t_board>>	loadInput() {
	fstream				input;
	vector<int>			numbers;
	vector<t_board>		boards;
	int					test;

	input.open("../input.txt");

	numbers = eatNumbers(input);
	boards = eatBoards(input);

	input.close();

	return pair<vector<int>, vector<t_board>>(numbers, boards);
}

void	printBoard(const t_board & board) {
	string	rep;

	for (size_t i = 0; i < 5; i++) {
		for (size_t j = 0; j < 5; j++) {
			rep = to_string(board.board[i][j]);
			if (rep.length() == 1) {
				rep = " " + rep;
			}
			if (board.marked[i][j]) {
				rep = "<" + rep + ">";
			} else {
				rep = " " + rep + " ";
			}
			cout << rep << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int		main(void) {
	vector<int>			numbers;
	vector<t_board>		boards;
	auto 				input = loadInput();
	int					numWhenBingo = -1;
	int					result = 0;
	bool				found = false;

	numbers = input.first;
	boards = input.second;

	for (auto &num: numbers) {
		numWhenBingo = num;

		// Mark Boards
		for (auto &board: boards) {
			for (size_t i = 0; i < 5; ++i) {
				for (size_t j = 0; j < 5; ++j) {
					if (board.board[i][j] == num) {
						board.marked[i][j] = true;
					}
				}
			}
		}

		// Check Bingo
		bool hasBingo = false;
		for (auto it = boards.begin(); it != boards.end(); ) {
			for (size_t i = 0; i < 5; ++i) {
				hasBingo = true;
				for (size_t j = 0; j < 5; ++j) {
					if (!(*it).marked[i][j]) {
						hasBingo = false;
						break;
					}
				}
				if (hasBingo) break;
				hasBingo = true;
				for (size_t j = 0; j < 5; ++j) {
					if (!(*it).marked[j][i]) {
						hasBingo = false;
						break;
					}
				}
				if (hasBingo) break;
			}
			if (hasBingo) {
				if (boards.size() == 1) {
					found = true;
					break;
				}
				it = boards.erase(it);
			} else {
				it++;
			}
		}

		if (found) break;

		cout << "num: " << num << "; size remains boards: " << boards.size() << endl;
	}

	printBoard(*boards.begin());

	// Compute result
	for (size_t i = 0; i < 5; i++) {
		for (size_t j = 0; j < 5; j++) {
			if (!(*boards.begin()).marked[i][j]) {
				result += (*boards.begin()).board[i][j];
			}
		}
	}
	cout << "sum unmarked: " << result << endl;
	cout << "num drawn when bingo: " << numWhenBingo << endl;
	result *= numWhenBingo;
	cout << "answer: " << result << endl;

	return 0;
}
