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

void							countPaths(
									const vector<pair<string, string>> &graph,
									const string &vertex,
									set<string> &mask,
									bool singleCaveVisited,
									vector<string> &currentPath,
									set<vector<string>> &allPaths) {
	vector<string>		neighbors;
	bool				hasBeenMask = false;

	currentPath.push_back(vertex);

	if (vertex == "end") {
		allPaths.insert(currentPath);
		currentPath.pop_back();
		return ;
	}

	neighbors = getNeighborsMask(graph, vertex, mask);

	if (!isUpper(vertex) && vertex != "start" && !singleCaveVisited) {
		for (const auto &neigh: neighbors) {
			countPaths(graph, neigh, mask, true, currentPath, allPaths);
		}
	}

	if (!isUpper(vertex)) {
		mask.insert(vertex);
		hasBeenMask = true;
	}

	for (const auto &neigh: neighbors) {
		countPaths(graph, neigh, mask, singleCaveVisited, currentPath, allPaths);
	}

	if (hasBeenMask) {
		mask.erase(vertex);
	}

	currentPath.pop_back();
}

int		main(void) {
	vector<pair<string, string>>	graph;
	set<string> 					mask;
	vector<string>					currentPath;
	set<vector<string>>				allPaths;
	size_t							answer;

	graph = loadInput();
	countPaths(graph, "start", mask, false, currentPath, allPaths);
	answer = allPaths.size();

	cout << "answer: " << answer << endl;

	return 0;
}
