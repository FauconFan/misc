#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

vector<pair<string, string>>	loadInput() {
	fstream							input;
	vector<pair<string, string>>	res;
	string							line;
	size_t							hyphen;

	input.open("../input.txt");

	while (getline(input, line)) {
		hyphen = line.find('-');
		res.push_back(make_pair(line.substr(0, hyphen), line.substr(hyphen + 1)));
	}

	input.close();
	return res;
}

vector<string>					getNeighborsMask(
									vector<pair<string, string>> graph,
									string vertex,
									set<string> mask) {
	vector<string>		res;
	string				cand;

	for (const auto &p: graph) {
		if (p.first == vertex) cand = p.second;
		else if (p.second == vertex) cand = p.first;
		else continue;

		if (mask.find(cand) != mask.end()) continue;

		res.push_back(cand);
	}
	return res;
}

bool							isUpper(string str) {
	for (const auto &c: str) {
		if (!isupper(c)) return false;
	}
	return true;
}

size_t							countPaths(
									const vector<pair<string, string>> &graph,
									string vertex,
									set<string> mask) {
	vector<string>		neighbors;
	bool				hasBeenMask = false;
	size_t				answer = 0;

	if (vertex == "end") return 1;

	neighbors = getNeighborsMask(graph, vertex, mask);
	if (!isUpper(vertex)) {
		mask.insert(vertex);
		hasBeenMask = true;
	}

	for (const auto &neigh: neighbors) {
		answer += countPaths(graph, neigh, mask);
	}

	if (hasBeenMask) {
		mask.erase(vertex);
	}
	return answer;
}

int		main(void) {
	vector<pair<string, string>>	graph;

	graph = loadInput();
	cout << "answer: " << countPaths(graph, "start", {}) << endl;

	return 0;
}
