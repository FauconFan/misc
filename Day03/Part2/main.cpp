#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<string> 		loadFile(void) {
	fstream			input;
	string			actualNumber;
	vector<string>	diagnosisReport;

	input.open("../input.txt");

	while (true) {
		input >> actualNumber;

		if (input.fail()) {
			break;
		}

		diagnosisReport.push_back(actualNumber);

		if (input.eof()) {
			break;
		}
	}

	input.close();
	return diagnosisReport;
}

char				searchMostCommonAt(const vector<string> &vec, size_t pos, bool reverse) {
	size_t			counters[2];

	counters[0] = 0;
	counters[1] = 0;

	for (auto it = vec.begin(); it != vec.end(); ++it) {
		if ((*it)[pos] == '0') counters[0]++;
		else counters[1]++;
	}

	if (reverse == false) {
		if (counters[0] > counters[1]) {
			return '1';
		}
		return '0';
	}

	if (counters[0] > counters[1]) {
		return '0';
	}
	return '1';
}

void				filterPosWith(vector<string> &vec, size_t pos, char value) {
	for (auto it = vec.begin(); it != vec.end(); ) {
		if ((*it)[pos] == value) it++;
		else it = vec.erase(it);
	}
}

string				findWord(vector<string> vec, size_t length_word, bool most) {
	size_t		posActu = 0;

	while (vec.size() > 1) {
		if (posActu >= length_word) {
			cerr << "Smth went wrong" << endl;
		}

		filterPosWith(vec, posActu, searchMostCommonAt(vec, posActu, most));
		posActu++;
	}

	return *vec.begin();
}

int					main(void) {
	vector<string>	diagnosisReport;
	string			ogr; // oxygen generator rating
	string			csr; // CO2 scrubber rating
	size_t			length_word;

	diagnosisReport = loadFile();
	length_word = (*diagnosisReport.begin()).length();

	// Finding ogr;
	ogr = findWord(diagnosisReport, length_word, true);
	// Finding csr;
	csr = findWord(diagnosisReport, length_word, false);

	cout << (stoi(ogr, NULL, 2) * stoi(csr, NULL, 2)) << endl;
	return 0;
}
