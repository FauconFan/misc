#include "sat.hpp"

enum cmd_type{
	BRUT_SAT,
	INTERNAL_VOID,
	INTERNAL_INT,
};

struct cmd_config{
	std::string name;
	cmd_type    type;
	union ptr_fns{
		std::pair<bool, Distrib>(* brut)(Fnc &);
		void (* internal_void)(void);
		void (* internal_int)(int);
	} fns;

	cmd_config(std::string name, std::pair<bool, Distrib>(*brut)(Fnc &)) : name(name), type(BRUT_SAT) {
		this->fns.brut = brut;
	}

	cmd_config(std::string name, void(*internal_void)(void)) : name(name), type(INTERNAL_VOID) {
		this->fns.internal_void = internal_void;
	}

	cmd_config(std::string name, void(*internal_int)(int)) : name(name), type(INTERNAL_INT) {
		this->fns.internal_int = internal_int;
	}
};

static const struct cmd_config cmds[] = {
	{"cdcl",       cdcl_solve        },
	{"dpll",       dpll_solve        },
	{"bruteforce", bruteforcing_solve},
	{"2sat",       twosat_solve      },
	{"queens",     queens_problems   },
	{"einstein",   einstein_problem  },
	{"PHP", pigeon_hole_principle},
};

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

	for (size_t i = 0; i < sizeof(cmds) / sizeof(*cmds); ++i) {
		struct cmd_config cmd_conf = cmds[i];

		if (cmd == cmd_conf.name) {
			switch (cmd_conf.type) {
				case BRUT_SAT: {
					if (argc != 1)
						return (1);

					Fnc * fnc = getInputFNC(argv[0]);

					if (fnc != nullptr) {
						auto p = cmd_conf.fns.brut(*fnc);
						print_result(p);

						delete fnc;
					}
					else {
						return (1);
					}
					return (0);
				}
				case INTERNAL_VOID: {
					if (argc != 0)
						return (1);

					cmd_conf.fns.internal_void();
					return (0);
				}
				case INTERNAL_INT: {
					if (argc != 1)
						return (1);

					int arg = atoi(argv[0]);

					cmd_conf.fns.internal_int(arg);
					return (0);
				}
			}
			break;
		}
	}

	std::cout << "The command is not recognised : " << cmd << "\n";

	return (1);
} // main
