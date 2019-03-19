#include "sat.hpp"

int main(int argc, char ** argv) {
	if (argc == 2) {
		Fnc * fnc = getInputFNC(argv[1]);

		if (fnc != nullptr) {
			/*FNC::printFNC(fnc);
			 *  FNC::delete_tautologies(fnc);
			 *  FNC::simplify(fnc);
			 *  FNC::printFNC(fnc);*/

			std::cout << *fnc;

			if (cut_solve(*fnc))
				std::cout << "true\n";
			else
				std::cout << "false\n";

			delete fnc;
		}
	}
	else {
		return (1);
	}

	/*Clause * icl = new Clause ({2, -3, 6, 1});
	 * if (*icl == *icl){
	 *  std::cout << "true";
	 * }else{
	 *  std::cout << "false";
	 * }
	 * std::cout << *icl;
	 *
	 * std::cout << icl->contains_litt(-3);
	 *
	 * std::vector <AClause *> * fnc = getInputFNC("../input_files/custom/sample1.cnf");
	 * std::vector<Clause *> *impl_clauses = FNC::convert<Clause>(fnc);
	 *
	 * FNC::printFNC(reinterpret_cast<std::vector<AClause *> *>(impl_clauses));
	 *
	 * apply_cut (impl_clauses, 4);
	 *
	 * FNC::printFNC(reinterpret_cast<std::vector<AClause *> *>(impl_clauses));*/

	return (0);
}
