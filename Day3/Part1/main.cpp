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

int					main(void) {
	vector<string>	diagnosisReport;
	string			gamma;
	string			epsilon;
	size_t			length_word;
	size_t			counters[2];

	diagnosisReport = loadFile();
	length_word = (*diagnosisReport.begin()).length();
	for (size_t i = 0; i < length_word; ++i) {
		counters[0] = 0;
		counters[1] = 0;
		for (auto it = diagnosisReport.begin(); it != diagnosisReport.end(); it++) {
			if ((*it)[i] == '0') counters[0]++;
			else counters[1]++;
		}

		if (counters[0] > counters[1]) {
			gamma += "0";
			epsilon += "1";
		} else {
			gamma += "1";
			epsilon += "0";
		}
	}
	cout << (stoi(gamma, NULL, 2) * stoi(epsilon, NULL, 2)) << endl;
	return 0;
}
