#include <iostream>
#include <fstream>
#include <vector>

#include <optional>

#include <cstdlib>

using namespace std;

enum	InstructionType
{
	INST_INP,
	INST_ADD,
	INST_MUL,
	INST_DIV,
	INST_MOD,
	INST_EQL
};

const static pair<InstructionType, string> INSTRUCTION_COMMANDS[] = {
	{ INST_INP, "inp" },
	{ INST_ADD, "add" },
	{ INST_MUL, "mul" },
	{ INST_DIV, "div" },
	{ INST_MOD, "mod" },
	{ INST_EQL, "eql" }
};

enum	RegisterNum
{
	REG_W,
	REG_X,
	REG_Y,
	REG_Z
};

string	getStringOfRegisterNum(const RegisterNum &regNum) {
	switch (regNum) {
		case REG_W: return "w";
		case REG_X: return "x";
		case REG_Y: return "y";
		case REG_Z: return "z";
	}
}

struct	Instruction
{
	InstructionType		type;
	RegisterNum			lhs;
	bool				isRhsNum;
	union {
		int				rhsNum;
		RegisterNum		rhsReg;
	}					u;
};

ostream &operator<<(ostream &os, const Instruction &instr) {
	string		command;

	for (const auto &p: INSTRUCTION_COMMANDS) {
		if (instr.type == p.first) {
			command = p.second;
			break;
		}
	}

	os << command << " ";
	os << getStringOfRegisterNum(instr.lhs);
	if (instr.type != INST_INP) {
		os << " ";
		if (instr.isRhsNum) os << instr.u.rhsNum;
		else os << getStringOfRegisterNum(instr.u.rhsReg);
	}
	return os;
}

struct	Prog
{
	vector<Instruction>	instrs;

	vector<Prog>	split(const InstructionType &type) {
		vector<Prog>	res;
		Prog			prog;

		for (size_t i = 0; i < instrs.size(); ++i) {
			if (instrs[i].type == INST_INP) {
				if (prog.instrs.size() != 0) {
					res.push_back(prog);
					prog.instrs.clear();
				}
			}
			prog.instrs.push_back(instrs[i]);
		}
		if (prog.instrs.size() != 0) res.push_back(prog);
		return res;
	}

	void			dump(ostream &os) const {
		os << "Prog:" << endl;
		for (size_t i = 0; i < instrs.size(); ++i) {
			os << "  " << i << ": " << instrs[i] << endl;
		}
	}
};

Prog	loadInput(void) {
	Prog			prog;
	fstream			input;
	string			line;
	Instruction		instr;
	size_t			pos[2];
	string			command;
	string			lhs;
	string			rhs;

	input.open("../input.txt");

	while (getline(input, line)) {
		command = line.substr(0, 3);

		for (const auto &p: INSTRUCTION_COMMANDS) {
			if (command == p.second) {
				instr.type = p.first;
				break;
			}
		}

		pos[0] = line.find(' ') + 1;
		pos[1] = line.find(' ', pos[0]);

		lhs = line.substr(pos[0], pos[1] - pos[0]);

		if (lhs == "w") instr.lhs = REG_W;
		else if (lhs == "x") instr.lhs = REG_X;
		else if (lhs == "y") instr.lhs = REG_Y;
		else if (lhs == "z") instr.lhs = REG_Z;

		if (pos[1] != string::npos) {
			pos[1]++;
			rhs = line.substr(pos[1]);

			instr.isRhsNum = false;
			if (rhs == "w") instr.u.rhsReg = REG_W;
			else if (rhs == "x") instr.u.rhsReg = REG_X;
			else if (rhs == "y") instr.u.rhsReg = REG_Y;
			else if (rhs == "z") instr.u.rhsReg = REG_Z;
			else {
				instr.isRhsNum = true;
				instr.u.rhsNum = stoi(rhs);
			}
		}

		prog.instrs.push_back(instr);
	}

	input.close();
	return prog;
}

struct	State {
	int		regW = 0;
	int		regX = 0;
	int		regY = 0;
	int		regZ = 0;

	State	&operator=(const State &rhs) {
		if (this != &rhs) {
			regW = rhs.regW;
			regX = rhs.regX;
			regY = rhs.regY;
			regZ = rhs.regZ;
		}
		return *this;
	}

	int		get(const RegisterNum &reg) {
		switch (reg) {
			case REG_W: return regW;
			case REG_X: return regX;
			case REG_Y: return regY;
			case REG_Z: return regZ;
		}
	}

	void	set(const RegisterNum &reg, int value) {
		switch (reg) {
			case REG_W: regW = value; break;
			case REG_X: regX = value; break;
			case REG_Y: regY = value; break;
			case REG_Z: regZ = value; break;
		}
	}

	void	dump(ostream &os) const {
		os << "State:" << endl
			<< "  W: " << regW << endl
			<< "  X: " << regX << endl
			<< "  Y: " << regY << endl
			<< "  Z: " << regZ << endl;
	}
};

State	runProg(
			const Prog &prog,
			vector<int> inputLines,
			State state = State()) {
	int		lhs;
	int		rhs;

	for (const Instruction &instr: prog.instrs) {
		if (instr.type == INST_INP) {
			state.set(instr.lhs, *inputLines.begin());
			inputLines.erase(inputLines.begin());
		} else {
			lhs = state.get(instr.lhs);
			if (instr.isRhsNum) rhs = instr.u.rhsNum;
			else rhs = state.get(instr.u.rhsReg);

			switch (instr.type) {
				case INST_INP: break;
				case INST_ADD: state.set(instr.lhs, lhs + rhs); break;
				case INST_MUL: state.set(instr.lhs, lhs * rhs); break;
				case INST_DIV: state.set(instr.lhs, lhs / rhs); break;
				case INST_MOD: state.set(instr.lhs, lhs % rhs); break;
				case INST_EQL: state.set(instr.lhs, (lhs == rhs ? 1: 0)); break;
			}
		}
	}

	return state;
}

void			printVec(const vector<int> &input, ostream &os) {
	for (const auto &i: input) {
		os << i;
	}
	os << endl;
}

optional<vector<int>>	recursive(
							const vector<Prog> &splittedProgs,
							vector<int> currentInput = {},
							State currentState = State(),
							size_t currentIndex = 0) {
	
	const Prog &currentProg = splittedProgs[currentIndex];

	if (currentIndex == 14) {
		if (currentState.regZ == 0) return optional(currentInput);
		return nullopt;
	}

	// if z is divided by 26
	if (currentProg.instrs[4].u.rhsNum == 26) {
		int		nextInput = 0;

		nextInput = currentState.regZ % 26 + currentProg.instrs[5].u.rhsNum;
		if (nextInput >= 1 && nextInput <= 9) {
			State nextState = runProg(currentProg, { nextInput }, currentState);

			currentInput.push_back(nextInput);
			return recursive(splittedProgs, currentInput, nextState, currentIndex + 1);
		}
		return nullopt;
	}
	// if z is not divided by 26

	for (int i = 1; i <= 9; ++i) {
		State nextState = runProg(currentProg, { i }, currentState);
		
		currentInput.push_back(i);
		auto recResponse = recursive(splittedProgs, currentInput, nextState, currentIndex + 1);
		if (recResponse.has_value()) {
			return recResponse;
		}
		currentInput.pop_back();
	}

	return nullopt;
}

int						main(void) {
	Prog			prog;
	State			finalState;
	vector<int>		inputProg;
	vector<Prog>	splittedProgs;
	vector<Prog>	previousProgs;

	prog = loadInput();
	splittedProgs = prog.split(INST_INP);

	auto vec = recursive(splittedProgs);

	if (vec.has_value()) {
		printVec(*vec, cout);
	}

	return 0;
}
