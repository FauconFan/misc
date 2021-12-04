#include <iostream>
#include <fstream>

using namespace std;

int	main() {
	ifstream	input;
	int			old_depth;
	int			current_depth;
	int			counter;

	counter = 0;
	input.open("../input.txt");
	input >> old_depth;

	while (input >> current_depth) {
		if (current_depth > old_depth) {
			counter += 1;
		}

		old_depth = current_depth;
	}
	cout << "counter: " << counter << endl;
	return 0;
}
