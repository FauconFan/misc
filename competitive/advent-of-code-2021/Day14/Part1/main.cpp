#include <fstream>
#include <iostream>
#include <map>

using namespace std;

typedef struct		s_problem
{
	string							initial;
	map<pair<char, char>, char>		rules;
}					t_problem;

t_problem		loadInput(void) {
	t_problem		pb;
	fstream			input;
	string			line;

	input.open("../input.txt");

	getline(input, pb.initial);
	getline(input, line); // ignore one line

	while (getline(input, line)) {
		pb.rules.insert(make_pair(make_pair(line[0], line[1]), line[6]));
	}

	input.close();
	return pb;
}

uint32_t		computeAnswer(const string &pattern) {
	uint32_t				res = 0;
	map<char, uint32_t>		counter;
	uint32_t				valueBounds[2];

	for (const auto &c: pattern) {
		auto it = counter.find(c);

		if (it == counter.end()) {
			counter[c] = 1;
		} else {
			it->second++;
		}
	}

	valueBounds[0] = counter.begin()->second;
	valueBounds[1] = counter.begin()->second;

	for (const auto &d: counter) {

		if (valueBounds[0] > d.second) {
			valueBounds[0] = d.second;
		}
		else if (valueBounds[1] < d.second) {
			valueBounds[1] = d.second;
		}

	}

	res = valueBounds[1] - valueBounds[0];

	return res;
}

int				main(void) {
	t_problem		pb;
	string			pattern;
	string			next_pattern;
	uint32_t		answer = 0;

	pb = loadInput();

	pattern = pb.initial;

	for (size_t i = 0; i < 10; ++i) {
		next_pattern = "";

		for (size_t j = 0; j < pattern.size() - 1; ++j) {
			next_pattern += pattern[j];
			next_pattern += pb.rules[make_pair(pattern[j], pattern[j + 1])];
		}
		next_pattern += pattern[pattern.size() - 1];

		pattern = next_pattern;
	}

	answer = computeAnswer(pattern);

	cout << "answer: " << answer << endl;

	return 0;
}
