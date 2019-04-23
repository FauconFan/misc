#include "sat.hpp"

static void print_result(std::pair<bool, Distrib> result) {
	if (result.first == false) {
		std::cout << "UNSAT" << std::endl;
	}
	else {
		std::cout << "SAT" << std::endl;
		size_t i = 0;

		for (auto p : result.second.get_distrib()) {
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

static int twosat_run(int argc, char ** argv) {
	if (argc != 1)
		return (1);

	Fnc * fnc = getInputFNC(argv[0]);

	if (fnc != nullptr) {
		auto p = twosat_solve(*fnc);
		print_result(p);

		delete fnc;
	}
	return (0);
}

static int bruteforce_run(int argc, char ** argv) {
	if (argc != 1)
		return (1);

	Fnc * fnc = getInputFNC(argv[0]);

	if (fnc != nullptr) {
		auto p = bruteforcing_solve(*fnc);
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

	if (cmd == "dpll")
		return (dpll_run(argc, argv));

	if (cmd == "bruteforce")
		return (bruteforce_run(argc, argv));

	if (cmd == "2sat")
		return (twosat_run(argc, argv));

	if (cmd == "queens") {
		queens_problems();
		return (0);
	}

	if (cmd == "einstein") {
		einstein_problem();
		return (0);
	}

	std::cout << "The command is not recognised : " << cmd << "\n";

	return (1);
} // main
