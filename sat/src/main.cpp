#include "sat.hpp"

static int cut_run(int argc, char ** argv) {
	if (argc != 1)
		return (1);

	Fnc * fnc = getInputFNC(argv[0]);

	if (fnc != nullptr) {
		if (cut_solve(*fnc))
			std::cout << "true\n";
		else
			std::cout << "false\n";

		delete fnc;
	}
	return (0);
}

static int dpll_run(int argc, char ** argv) {
	if (argc != 1)
		return (1);

	Fnc * fnc = getInputFNC(argv[0]);

	if (fnc != nullptr) {
		if (dpll_solve(*fnc))
			std::cout << "true\n";
		else
			std::cout << "false\n";

		delete fnc;
	}
	return (0);
}

int main(int argc, char ** argv) {
	if (argc <= 1)
		return (1);

	std::string cmd = argv[1];
	argc -= 2;
	argv += 2;

	if (cmd == "cut")
		return (cut_run(argc, argv));

	if (cmd == "dpll")
		return (dpll_run(argc, argv));

	return (1);
}
