#include "sat.hpp"

static void print_result(std::pair<bool, Distrib> result) {
	if (result.first == false) {
		std::cout << "UNSAT" << std::endl;
	}
	else {
		std::cout << "SAT" << std::endl;
		size_t i = 0;

		for (auto p : *result.second.getDistrib()) {
			if (i != 0)
				std::cout << " ";
			i++;
			if (p.second == false)
				std::cout << "-";
			std::cout << p.first;
		}
		std::cout << std::endl;
	}
}

static int cut_run(int argc, char ** argv) {
	if (argc != 1)
		return (1);

	Fnc * fnc = getInputFNC(argv[0]);

	if (fnc != nullptr) {
		auto p = cut_solve(*fnc);
		print_result(p);

		delete fnc;
	}
	return (0);
}

static int dpll_run(int argc, char ** argv) {
	if (argc != 1)
		return (1);

	Fnc * fnc = getInputFNC(argv[0]);

	if (fnc != nullptr) {
		auto p = dpll_solve(*fnc);
		print_result(p);

		delete fnc;
	}
	return (0);
}

int main(int argc, char ** argv) {
	if (argc <= 0)
		return (1);

	argc--;
	argv++;

	if (argc == 0)
		return (1);

	if (std::string(argv[0]) == "--no-logs") {
		Logger::disable();
		argv++;
		argc--;
	}

	if (argc == 0)
		return (1);

	std::string cmd = argv[0];
	argc--;
	argv++;

	if (cmd == "cut")
		return (cut_run(argc, argv));

	if (cmd == "dpll")
		return (dpll_run(argc, argv));

	return (1);
}
