#include <iostream>
#include <fstream>

#include <vector>
#include <array>
#include <set>
#include <map>
#include <queue>

using namespace std;

enum		E_Amph
{
	NONE,
	AMPH_A,
	AMPH_B,
	AMPH_C,
	AMPH_D
};

E_Amph		getAmphFromChar(const char &c) {
	if (c == 'A') return AMPH_A;
	else if (c == 'B') return AMPH_B;
	else if (c == 'C') return AMPH_C;
	else if (c == 'D') return AMPH_D;
	return NONE;
}

char		getCharFromAmph(const E_Amph &amph) {
	switch (amph) {
		case NONE: return '.';
		case AMPH_A: return 'A';
		case AMPH_B: return 'B';
		case AMPH_C: return 'C';
		case AMPH_D: return 'D';
	}
}

size_t		getPosHallwayFromRoom(const size_t &amphRoom) {
	switch (amphRoom) {
		case 0: return 2;
		case 1: return 4;
		case 2: return 6;
		case 3: return 8;
		default: return 0;
	}
}

size_t		getRoomFromAmph(const E_Amph &amph) {
	switch (amph) {
		case AMPH_A: return 0;
		case AMPH_B: return 1;
		case AMPH_C: return 2;
		case AMPH_D: return 3;
		default: return -1;
	}
}

E_Amph		getAmphFromRoom(const size_t &amphRoom) {
	switch (amphRoom) {
		case 0: return AMPH_A;
		case 1: return AMPH_B;
		case 2: return AMPH_C;
		case 3: return AMPH_D;
		default: return NONE;
	}
}

size_t		getPosHallwayFromAmph(const E_Amph &amph) {
	return getPosHallwayFromRoom(getRoomFromAmph(amph));
}

uint64_t	getCostFromAmph(const E_Amph &amph) {
	switch (amph) {
		case AMPH_A: return 1;
		case AMPH_B: return 10;
		case AMPH_C: return 100;
		case AMPH_D: return 1000;
		default: return 0;
	}
}

using Signature = array<E_Amph, 27>;

struct		State
{
	array<E_Amph, 11>			hallway;
	array<array<E_Amph, 4>, 4>	rooms;
	uint64_t					cost = 0;

	State() {
		hallway = {NONE, NONE, NONE, NONE, NONE,
			NONE, NONE, NONE, NONE, NONE, NONE};
		rooms = {{
			{NONE, NONE, NONE, NONE},
			{NONE, NONE, NONE, NONE},
			{NONE, NONE, NONE, NONE},
			{NONE, NONE, NONE, NONE}
		}};
		cost = 0;
	}

	State(const State &rhs) {
		hallway = rhs.hallway;
		rooms = rhs.rooms;
		cost = rhs.cost;
	}

	State	&operator=(const State &rhs) {
		if (this != &rhs) {
			hallway = rhs.hallway;
			rooms = rhs.rooms;
			cost = rhs.cost;
		}
		return *this;
	}

	bool	operator<(const State &rhs) const {
		if (hallway == rhs.hallway) {
			if (rooms == rhs.rooms) return cost < rhs.cost;
			return rooms < rhs.rooms;
		}
		return hallway < rhs.hallway;
	}

	Signature	getSignature() const {
		Signature res = {
			hallway[0], hallway[1], hallway[2], hallway[3], hallway[4], hallway[5],
			hallway[6], hallway[7], hallway[8], hallway[9], hallway[10],
			rooms[0][0], rooms[0][1], rooms[0][2], rooms[0][3],
			rooms[1][0], rooms[1][1], rooms[1][2], rooms[1][3],
			rooms[2][0], rooms[2][1], rooms[2][2], rooms[2][3],
			rooms[3][0], rooms[3][1], rooms[3][2], rooms[3][3]
		};

		return res;
	}

	bool	isFinished() const {
		for (const auto &amph: hallway) {
			if (amph != NONE) return false;
		}

		for (size_t i = 0; i < 4; ++i) {
			if (rooms[0][i] != AMPH_A) return false;
			if (rooms[1][i] != AMPH_B) return false;
			if (rooms[2][i] != AMPH_C) return false;
			if (rooms[3][i] != AMPH_D) return false;
		}

		return true;
	}

	void	dump(ostream &os) const {
		os << "#############" << endl
			<< "#";

		for (const E_Amph &amph: hallway) {
			os << getCharFromAmph(amph);
		}
		os << "#" << endl;

		os << "###";
		for (size_t i = 0; i < 4; ++i) {
			os << getCharFromAmph(rooms[i][0]) << "#";
		}
		os << "##" << endl;

		for (size_t j = 1; j < 4; ++j) {
			os << "  #";
			for (size_t i = 0; i < 4; ++i) {
				os << getCharFromAmph(rooms[i][j]) << "#";
			}
			os << endl;
		}

		os << "  #########" << endl;
		os << "    cost: " << cost << endl;
	}
};

class		StateCmpCostGreater
{
	public:
		bool	operator() (const State &lhs, const State &rhs) {
			return lhs.cost > rhs.cost;
		}
};

vector<State>	computeNextStatesForHallway(const State &s) {
	vector<State>		res;
	vector<size_t>		liPos;

	for (size_t i = 0; i < s.hallway.size(); ++i) {
		if (s.hallway[i] != NONE) {
			liPos.push_back(i);
		}
	}

	for (const size_t pos: liPos) {
		E_Amph		amph = s.hallway[pos];
		size_t		posRoom = getRoomFromAmph(amph);
		size_t		endPos = getPosHallwayFromAmph(amph);
		bool		isRoomFree = true;
		bool		isWayFree = true;

		for (const E_Amph &amphRoom: s.rooms[posRoom]) {
			if (amphRoom != NONE && amphRoom != amph) {
				isRoomFree = false;
			}
		}
		if (!isRoomFree) continue;

		if (pos < endPos) {
			for (size_t posOnWay = pos + 1; posOnWay <= endPos; ++posOnWay) {
				if (s.hallway[posOnWay] != NONE) {
					isWayFree = false;
				}
			}
		} else {
			for (size_t posOnWay = pos - 1; posOnWay >= endPos; --posOnWay) {
				if (s.hallway[posOnWay] != NONE) {
					isWayFree = false;
				}
			}
		}
		if (!isWayFree) continue;

		uint64_t	cost = 0;
		State		current(s);

		if (pos < endPos) cost += endPos - pos;
		else cost += pos - endPos;

		cost += 1;
		current.hallway[pos] = NONE;

		if (s.rooms[posRoom][3] == NONE) {
			current.rooms[posRoom][3] = amph;
			cost += 3;
		} else if (s.rooms[posRoom][2] == NONE) {
			current.rooms[posRoom][2] = amph;
			cost += 2;
		} else if (s.rooms[posRoom][1] == NONE) {
			current.rooms[posRoom][1] = amph;
			cost += 1;
		} else {
			current.rooms[posRoom][0] = amph;
		}

		cost *= getCostFromAmph(amph);

		current.cost += cost;
		res.push_back(current);
	}

	return res;
}

vector<State>	computeNextStatesForRooms(const State &s) {
	vector<State>					res;
	vector<pair<size_t, size_t>>	liPos;

	for (size_t i = 0; i < s.rooms.size(); ++i) {
		E_Amph		expectedAmph = getAmphFromRoom(i);

		if (s.rooms[i][0] == expectedAmph && s.rooms[i][1] == expectedAmph &&
			s.rooms[i][2] == expectedAmph && s.rooms[i][3] == expectedAmph) continue;
		if (s.rooms[i][0] == NONE && s.rooms[i][1] == expectedAmph &&
			s.rooms[i][2] == expectedAmph && s.rooms[i][3] == expectedAmph) continue;
		if (s.rooms[i][0] == NONE && s.rooms[i][1] == NONE &&
			s.rooms[i][2] == expectedAmph && s.rooms[i][3] == expectedAmph) continue;
		if (s.rooms[i][0] == NONE && s.rooms[i][1] == NONE &&
			s.rooms[i][2] == NONE && s.rooms[i][3] == expectedAmph) continue;
		if (s.rooms[i][0] == NONE && s.rooms[i][1] == NONE &&
			s.rooms[i][2] == NONE && s.rooms[i][3] == NONE) continue;

		for (size_t j = 0; j < 4; ++j) {
			if (s.rooms[i][j] != NONE) {
				liPos.push_back({i, j});
				break;
			}
		}
	}

	for (const auto &p: liPos) {
		E_Amph			amph;
		size_t			startPos;
		vector<size_t>	availablePos;

		amph = s.rooms[p.first][p.second];
		startPos = getPosHallwayFromRoom(p.first);

		for (int pos = startPos - 1; pos >= 0 && s.hallway[pos] == NONE; --pos) {
			if (pos % 2 == 0 && pos != 0 && pos != 10) continue;
			availablePos.push_back(pos);
		}

		for (int pos = startPos + 1; pos < s.hallway.size() && s.hallway[pos] == NONE; ++pos) {
			if (pos % 2 == 0 && pos != 0 && pos != 10) continue;
			availablePos.push_back(pos);
		}

		for (const size_t &endPos: availablePos) {
			State		current(s);
			uint64_t	cost = 0;

			cost = 1 + p.second;
			cost += endPos < startPos ? startPos - endPos: endPos - startPos;
			cost *= getCostFromAmph(amph);

			current.hallway[endPos] = amph;
			current.rooms[p.first][p.second] = NONE;

			current.cost += cost;

			res.push_back(current);
		}
	}

	return res;
}

vector<State>	nextStates(const State &s) {
	vector<State>		res;

	res = computeNextStatesForRooms(s);

	for (const auto &p: computeNextStatesForHallway(s)) {
		res.push_back(p);
	}

	return res;
}

bool			earlyPrune(const State &s) {
	vector<size_t>		liPos;
	map<size_t, size_t>	goTo;

	for (size_t i = 0; i < s.hallway.size(); ++i) {
		if (s.hallway[i] != NONE) {
			liPos.push_back(i);
		}
	}

	for (size_t pos: liPos) {
		E_Amph		amph = s.hallway[pos];
		size_t		endPos = getPosHallwayFromAmph(amph);

		goTo[pos] = endPos;
	}

	for (size_t pos1: liPos) {
		for (size_t pos2: liPos) {
			if (pos1 != pos2) {
				if (pos1 < pos2) {
					if (goTo[pos1] > pos2 && goTo[pos2] < pos1) {
						return true;
					}
				} else {
					if (goTo[pos1] < pos2 && goTo[pos2] > pos1) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

State			loadInput(void) {
	State		pb;
	fstream		input;
	string		line;

	input.open("../input.txt");

	getline(input, line);
	getline(input, line);

	for (size_t i = 0; i < pb.hallway.size(); ++i) {
		pb.hallway[i] = getAmphFromChar(line[i + 1]);
	}

	getline(input, line);

	for (size_t i = 0; i < 4; ++i) {
		pb.rooms[i][0] = getAmphFromChar(line[getPosHallwayFromRoom(i) + 1]);
	}

	pb.rooms[0][1] = AMPH_D;
	pb.rooms[0][2] = AMPH_D;

	pb.rooms[1][1] = AMPH_C;
	pb.rooms[1][2] = AMPH_B;

	pb.rooms[2][1] = AMPH_B;
	pb.rooms[2][2] = AMPH_A;

	pb.rooms[3][1] = AMPH_A;
	pb.rooms[3][2] = AMPH_C;

	getline(input, line);

	for (size_t i = 0; i < 4; ++i) {
		pb.rooms[i][3] = getAmphFromChar(line[getPosHallwayFromRoom(i) + 1]);
	}

	input.close();

	return pb;
}

State			findOptimal(const State &s) {
	priority_queue<
		State,
		vector<State>,
		StateCmpCostGreater
	>						pq;
	set<Signature>			visited;
	State					res;
	bool					hasFoundOne = false;
	map<State, State>		prev;

	pq.push(s);

	while (!pq.empty()) {
		State		current = pq.top();
		Signature	sig;

		pq.pop();
		if (hasFoundOne && current.cost > res.cost) continue;
		if (earlyPrune(s)) continue;
		sig = current.getSignature();
		if (visited.find(sig) != visited.end()) continue;
		visited.insert(sig);

		if (current.isFinished()) {
			res = current;
			hasFoundOne = true;
		}

		for (State nextState: nextStates(current)) {
			pq.push(nextState);
			prev[nextState] = current;
		}
	}

	return res;
}

int		main(void) {
	State		pb;
	State		final;
	
	pb = loadInput();
	final = findOptimal(pb);

	final.dump(cout);
	return 0;
}
