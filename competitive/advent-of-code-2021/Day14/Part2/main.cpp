#include <fstream>
#include <iostream>
#include <map>

using namespace std;

typedef struct		s_pair_chars
{
	char	left;
	char	right;

	bool operator<(const struct s_pair_chars &pc) const {
		if (left == pc.left) return right < pc.right;
		return left < pc.left;
	}
}					t_pair_chars;

typedef struct		s_problem
{
	string							initial;
	map<t_pair_chars, char>			rules;
}					t_problem;

t_problem		loadInput(void) {
	t_problem		pb;
	fstream			input;
	string			line;
	t_pair_chars	buffer;

	input.open("../input.txt");

	getline(input, pb.initial);
	getline(input, line); // ignore one line

	while (getline(input, line)) {
		buffer.left = line[0];
		buffer.right = line[1];
		pb.rules.insert(make_pair(buffer, line[6]));
	}

	input.close();
	return pb;
}

uint64_t		computeAnswer(const map<char, uint64_t> &counters_chars) {
	uint64_t				res = 0;
	uint64_t				valueBounds[2];

	valueBounds[0] = counters_chars.begin()->second;
	valueBounds[1] = counters_chars.begin()->second;

	for (const auto &d: counters_chars) {

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
	t_problem					pb;
	map<char, uint64_t>			counters_chars;
	map<t_pair_chars, uint64_t>	counters_pairs;
	map<t_pair_chars, uint64_t>	next_counters_pairs;
	t_pair_chars				buffer;
	uint64_t					answer = 0;

	pb = loadInput();

	// initialize counters_chars
	for (const auto &c: pb.initial) {
		auto it = counters_chars.find(c);

		if (it == counters_chars.end()) counters_chars[c] = 1;
		else it->second += 1;
	}

	// initialize counters_pairs
	for (size_t i = 0; i < pb.initial.size() - 1; ++i) {
		buffer.left = pb.initial[i];
		buffer.right = pb.initial[i + 1];
		auto it = counters_pairs.find(buffer);

		if (it == counters_pairs.end()) counters_pairs[buffer] = 1;
		else it->second++;
	}

	// main loop
	for (size_t i = 0; i < 40; ++i) {
		next_counters_pairs.clear();

		for (const auto &p: counters_pairs) {
			char middle = pb.rules[p.first];

			// update counters_chars
			auto itc = counters_chars.find(middle);

			if (itc == counters_chars.end()) counters_chars[middle] = p.second;
			else itc->second += p.second;

			// update left pair counters
			buffer.left = p.first.left;
			buffer.right = middle;
			auto it = next_counters_pairs.find(buffer);

			if (it == next_counters_pairs.end()) next_counters_pairs[buffer] = p.second;
			else it->second += p.second;

			// update right pair counters
			buffer.left = middle;
			buffer.right = p.first.right;
			auto it2 = next_counters_pairs.find(buffer);

			if (it2 == next_counters_pairs.end()) next_counters_pairs[buffer] = p.second;
			else it2->second += p.second;
		}

		counters_pairs.swap(next_counters_pairs);
	}

	answer = computeAnswer(counters_chars);

	cout << "answer: " << answer << endl;

	return 0;
}
