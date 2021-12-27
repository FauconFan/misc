#include <fstream>
#include <iostream>

#include <vector>

using namespace std;

enum	E_Cocumber
{
	NONE,
	EAST,
	SOUTH
};

struct	State
{
	vector<vector<E_Cocumber>>	map;
	size_t						width;
	size_t						height;

	State() = default;

	State(const State &rhs) {
		map = rhs.map;
		width = rhs.width;
		height = rhs.height;
	}

	bool	operator==(const State &rhs) const {
		if (width != rhs.width) return false;
		if (height != rhs.height) return false;

		for (size_t i = 0; i < height; ++i) {
			for (size_t j = 0; j < width; ++j) {
				if (map[i][j] != rhs.map[i][j]) return false;
			}
		}
		return true;
	}

	State	oneTurn(void) const {
		State	nextState(*this);
		State	stateMiddle;

		for (size_t i = 0; i < height; ++i) {
			for (size_t j = 0; j < width; ++j) {
				if (map[i][j] == EAST) {
					size_t		nextJ = j + 1;

					if (nextJ == width) nextJ = 0;
					if (map[i][nextJ] == NONE) {
						nextState.map[i][nextJ] = EAST;
						nextState.map[i][j] = NONE;
					}
				}
			}
		}

		stateMiddle = nextState;

		for (size_t i = 0; i < height; ++i) {
			for (size_t j = 0; j < width; ++j) {
				if (stateMiddle.map[i][j] == SOUTH) {
					size_t		nextI = i + 1;

					if (nextI == height) nextI = 0;
					if (stateMiddle.map[nextI][j] == NONE) {
						nextState.map[nextI][j] = SOUTH;
						nextState.map[i][j] = NONE;
					}
				}
			}
		}

		return nextState;
	}

	void	dump(ostream &os) const {
		for (size_t i = 0; i < height; ++i) {
			for (size_t j = 0; j < width; ++j) {
				switch (map[i][j]) {
					case NONE: os << '.'; break;
					case SOUTH: os << 'v'; break;
					case EAST: os << '>'; break;
				}
			}
			os << endl;
		}
	}
};

State		loadInput(void) {
	fstream				input;
	State				pb;
	string				line;
	vector<E_Cocumber>	lineCocumber;

	input.open("../input.txt");

	while (getline(input, line)) {
		lineCocumber.clear();

		for (const char &c: line) {
			if (c == '.') lineCocumber.push_back(NONE);
			else if (c == 'v') lineCocumber.push_back(SOUTH);
			else lineCocumber.push_back(EAST);
		}
		pb.map.push_back(lineCocumber);
	}

	input.close();

	pb.height = pb.map.size();
	pb.width = pb.map[0].size();

	return pb;
}

int			main(void) {
	State		pb;
	uint64_t	answer = 0;

	pb = loadInput();
	// pb.dump(cout);

	while (true) {
		State	previous(pb);

		answer++;
		pb = pb.oneTurn();
		if (pb == previous) break;
	}

	// pb.dump(cout);
	cout << "answer: " << answer << endl;
	
	return 0;
}
