#include "libsat.hpp"

/*Effectue la coupure de f par rapport a val*/
static void apply_cut(Fnc & fnc, Occ_list & litt_occ, unsigned int val) {
	Fnc fnc_without_val;
	Fnc fnc_premisse;
	Fnc fnc_conclusion;
	Clause res_fusion;

	std::cout << "cut...\n";

	std::vector<Clause> clauses = fnc.get_implclauses();

	// Range les clauses pour préparer la coupure
	for (const auto & implc : clauses) {
		int litt_side = implc.contains_litt(val);
		if (litt_side == -1) {
			fnc_premisse.add_clause(implc);
		}
		else if (litt_side == 1) {
			fnc_conclusion.add_clause(implc);
		}
		else {
			fnc_without_val.add_clause(implc);
		}
	}

	std::cout << "FNC without val\n" << fnc_without_val;
	std::cout << "FNC with val in premisse\n" << fnc_premisse;
	std::cout << "FNC with val in conclusion\n" << fnc_conclusion;

	auto cls_with_val_premisse       = fnc_premisse.get_implclauses();
	auto cls_cls_with_val_conclusion = fnc_conclusion.get_implclauses();

	std::cout << "start cut...\n";
	for (const auto & i : cls_with_val_premisse)
		litt_occ -= i.get_occ_list();
	for (const auto & j : cls_cls_with_val_conclusion)
		litt_occ -= j.get_occ_list();

	for (const auto & i : cls_with_val_premisse) {
		for (const auto & j : cls_cls_with_val_conclusion) {
			res_fusion = cut(i, j, val);
			std::cout << "; " << i << "; " << j << "\t -> " << res_fusion;
			if (!res_fusion.is_tautology() && !fnc.contains(res_fusion)) {
				std::cout << "hh\n";
				fnc_without_val.add_clause(res_fusion);
				litt_occ += res_fusion.get_occ_list();
			}
		}
	}

	std::cout << "fnc become : ";
	std::cout << fnc_without_val;
	std::cout << "New litt_occ : " << litt_occ << "\nend cut\n";

	fnc = fnc_without_val;
} // apply_cut

static bool rec_cut(Fnc fnc, Occ_list & litt_occ, Distrib & dist) {
	unsigned int cut_value;
	bool ret;
	Fnc next;

	fnc.nettoyage(litt_occ, dist);

	if (litt_occ.empty()) {
		return (fnc.empty());
	}

	Fnc copy_fnc = Fnc(fnc);

	cut_value = litt_occ.getMinOccu();
	std::cout << "cut_value : " << cut_value << "\n";

	apply_cut(fnc, litt_occ, cut_value);

	if ((ret = rec_cut(fnc, litt_occ, dist))) {
		std::cout << "Reassembly... \n";

		std::cout << copy_fnc;

		copy_fnc.assign_other_value(cut_value, dist);
		copy_fnc.unit_propagation(dist);
	}

	return ret;
}

bool cut_solve(const Fnc & fnc) {
	Occ_list litt_occ = Occ_list(fnc);
	Distrib dist;

	std::cout << litt_occ << "\n";

	bool res = rec_cut(Fnc(fnc), litt_occ, dist);

	if (res) {
		fnc.assign_other_value(0, dist);
		std::cout << dist;
	}

	return res;
}
