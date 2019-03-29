#include "sat.hpp"

int main(int argc, char ** argv) {
	if (argc == 2) {
		Fnc * fnc = getInputFNC(argv[1]);

		if (fnc != nullptr) {
			// std::cout << *fnc;

			if (dpll_solve(*fnc))
				std::cout << "true\n";
			else
				std::cout << "false\n";

			// if (cut_solve(*fnc))
			//  std::cout << "true\n";
			// else
			//  std::cout << "false\n";

			delete fnc;
		}
	}
	else {
		return (1);
	}

	return (0);
}
