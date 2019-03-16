#include "libsat.hpp"

static void polarity_check(Occ_list * litt_occ, Distrib * dist, std::vector<ImplClause *> * fnc) {
	std::pair<std::vector<unsigned int>, std::vector<unsigned int> > p;

	while (true) {
		p = litt_occ->getSoloPolarity();
		auto pos = p.first;
		auto neg = p.second;

		std::cout << "STEP ======= " << std::endl;
		FNC::printFNC(reinterpret_cast<std::vector<AClause *> *>(fnc));

		std::cout << *litt_occ;

		if (pos.empty() && neg.empty())
			break;
		for (auto i : pos) {
			dist->set(i, true);
			*litt_occ -= FNC::delete_if_contains(reinterpret_cast<std::vector<AClause *> *>(fnc), i);
		}
		for (auto i : neg) {
			dist->set(i, false);
			*litt_occ -= FNC::delete_if_contains(reinterpret_cast<std::vector<AClause *> *>(fnc), -i);
		}
	}
}

/* Simplifier (Une seule occurence de chaque littéral dans la prémisse (conclusion))
 * Enlever les tautologie (Retirer les clauses contenant a et -a)
 * Si x a toujours une polarité négative, la retirer partout et mettre x = 0
 * Si x a toujours une polarité positive, la retirer partout et mettre x = 1
 */
static void nettoyage(std::vector<ImplClause *> * fnc, Occ_list * litt_occ, Distrib * dist) {
	std::cout << "clean... \nSimplify... done\n";

	*litt_occ -= FNC::simplify(reinterpret_cast<std::vector<AClause *> *>(fnc));
	std::cout << "Delete tautologies... done\n";
	*litt_occ -= FNC::delete_tautologies(reinterpret_cast<std::vector<AClause *> *>(fnc));
	std::cout << "New litt_occ " << *litt_occ;
	FNC::printFNC(reinterpret_cast<std::vector<AClause *> *>(fnc));

	// Suppression si polarité unique
	std::cout << "Polarity test\n";
	polarity_check(litt_occ, dist, fnc);
	std::cout << *litt_occ << "\ndone\n";

	FNC::printFNC(reinterpret_cast<std::vector<AClause *> *>(fnc));

	std::cout << "end clean\n";
}

/*Effectue la coupure de f par rapport a val*/
static std::vector<ImplClause *> apply_cut(std::vector<ImplClause *> * fnc, Occ_list * litt_occ, unsigned int val) {
	std::vector<ImplClause *> * cls_without_val         = new std::vector<ImplClause *>();
	std::vector<ImplClause *> * cls_with_val_premisse   = new std::vector<ImplClause *>();
	std::vector<ImplClause *> * cls_with_val_conclusion = new std::vector<ImplClause *>();
	ImplClause * res_fusion;

	std::cout << "cut...\n";

	// Range les clauses pour préparer la coupure
	for (auto i = fnc->begin(); i != fnc->end(); i++) {
		int litt_side = (*i)->contains_litt(val);
		if (litt_side == -1) {
			cls_with_val_premisse->push_back(*i);
		}
		else if (litt_side == 1) {
			cls_with_val_conclusion->push_back(*i);
		}
		else {
			cls_without_val->push_back(*i);
		}
	}

	std::cout << "FNC without val\n";
	FNC::printFNC(reinterpret_cast<std::vector<AClause *> *>(cls_without_val));
	std::cout << "FNC with val in premisse\n";
	FNC::printFNC(reinterpret_cast<std::vector<AClause *> *>(cls_with_val_premisse));
	std::cout << "FNC with val in conclusion\n";
	FNC::printFNC(reinterpret_cast<std::vector<AClause *> *>(cls_with_val_conclusion));

	std::cout << "start cut...\n";
	for (auto i = cls_with_val_premisse->begin(); i != cls_with_val_premisse->end(); i++) {
		*litt_occ -= (*i)->get_occ_list();
		for (auto j = cls_with_val_conclusion->begin(); j != cls_with_val_conclusion->end(); j++) {
			if (i == cls_with_val_premisse->begin()) {
				*litt_occ -= (*j)->get_occ_list();
			}

			res_fusion = cut(**i, **j, val);
			std::cout << **i << "\t ; " << **j << "\t -> " << *res_fusion;
			if (!res_fusion->is_tautology() &&
			  !FNC::contains(reinterpret_cast<std::vector<AClause *> *>(cls_without_val), res_fusion))
			{
				cls_without_val->push_back(res_fusion);
				*litt_occ += res_fusion->get_occ_list();
			}
		}
	}

	std::cout << "fnc become : ";

	FNC::printFNC(reinterpret_cast<std::vector<AClause *> *>(cls_without_val));

	std::cout << "New litt_occ : " << *litt_occ << "\nend cut\n";

	delete cls_with_val_premisse;
	delete cls_with_val_conclusion;

	return *cls_without_val;
} // apply_cut

static bool rec_cut(std::vector<ImplClause *> fnc, Occ_list * litt_occ, Distrib * dist) {
	unsigned int cut_value;
	bool ret;

	nettoyage(&fnc, litt_occ, dist);

	if (litt_occ->empty()) {
		return fnc.empty();
	}

	std::vector<ImplClause *> * copy_fnc = new std::vector<ImplClause *>(fnc);

	cut_value = litt_occ->getMinOccu();
	std::cout << "cut_value : " << cut_value << "\n";
	fnc = apply_cut(&fnc, litt_occ, cut_value);

	if ((ret = rec_cut(fnc, litt_occ, dist))) {
		std::cout << "Reassembly... \n";
		FNC::printFNC(reinterpret_cast<std::vector<AClause *> *>(copy_fnc));

		// Il faut assigner les valeurs non assignée apparaissant dans copy_fnc
	}

	delete copy_fnc;
	return ret;
}

/*Distrib **/ bool cut_solve(std::vector<ImplClause *> fnc) {
	Occ_list litt_occ = Occ_list(fnc);
	Distrib dist;

	std::cout << litt_occ << "\n";

	bool res = rec_cut(fnc, &litt_occ, &dist);

	std::cout << dist;

	return res;
}
