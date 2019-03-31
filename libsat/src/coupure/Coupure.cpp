#include "libsat.hpp"

static Clause cut(const Clause & icl1, const Clause & icl2, unsigned int val) {
	std::vector<unsigned int> * icl1_pos_litts;
	std::vector<unsigned int> * icl1_neg_litts;
	std::vector<unsigned int> * icl2_pos_litts;
	std::vector<unsigned int> * icl2_neg_litts;
	Clause res_cut;

	std::set<unsigned int> buff;

	icl1_pos_litts = icl1.getPosLitts();
	icl1_neg_litts = icl1.getNegLitts();
	icl2_pos_litts = icl2.getPosLitts();
	icl2_neg_litts = icl2.getNegLitts();

	for (unsigned int i : *icl1_pos_litts) {
		if (i != val)
			buff.insert(i);
	}

	for (unsigned int i : *icl2_pos_litts) {
		if (i != val)
			buff.insert(i);
	}

	res_cut.getPosLitts()->assign(buff.begin(), buff.end());
	buff.clear();

	for (unsigned int i : *icl1_neg_litts) {
		if (i != val)
			buff.insert(i);
	}

	for (unsigned int i : *icl2_neg_litts) {
		if (i != val)
			buff.insert(i);
	}

	res_cut.getNegLitts()->assign(buff.begin(), buff.end());

	return res_cut;
} // cut

/*Effectue la coupure de f par rapport a val*/
static void apply_cut(Fnc & fnc, Occ_list & litt_occ, unsigned int val) {
	Fnc fnc_without_val;
	Fnc fnc_premisse;
	Fnc fnc_conclusion;
	Clause res_fusion;

	Logger::info() << "cut...\n";

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

	Logger::info() << "FNC without val\n" << fnc_without_val;
	Logger::info() << "FNC with val in premisse\n" << fnc_premisse;
	Logger::info() << "FNC with val in conclusion\n" << fnc_conclusion;

	auto cls_with_val_premisse       = fnc_premisse.get_implclauses();
	auto cls_cls_with_val_conclusion = fnc_conclusion.get_implclauses();

	Logger::info() << "start cut...\n";
	for (const auto & i : cls_with_val_premisse)
		litt_occ -= i.build_occ_list();
	for (const auto & j : cls_cls_with_val_conclusion)
		litt_occ -= j.build_occ_list();

	for (const auto & i : cls_with_val_premisse) {
		for (const auto & j : cls_cls_with_val_conclusion) {
			res_fusion = cut(i, j, val);
			Logger::info() << "; " << i << "; " << j << "\t -> " << res_fusion;
			if (!res_fusion.is_tautology() && !fnc.contains(res_fusion)) {
				Logger::info() << "hh\n";
				fnc_without_val.add_clause(res_fusion);
				litt_occ += res_fusion.build_occ_list();
			}
		}
	}

	Logger::info() << "fnc become : ";
	Logger::info() << fnc_without_val;
	Logger::info() << "New litt_occ : " << litt_occ << "\nend cut\n";

	fnc = fnc_without_val;
} // apply_cut

static bool rec_cut(Fnc fnc, Occ_list & litt_occ, Distrib & dist) {
	unsigned int cut_value;
	bool ret;
	Fnc next;

	fnc.nettoyage(litt_occ, dist);

	if (fnc.has_empty_clause())
		return (false);

	if (fnc.empty())
		return (true);

	Fnc copy_fnc = Fnc(fnc);

	cut_value = litt_occ.getMinOccu();
	Logger::info() << "cut_value : " << cut_value << "\n";

	apply_cut(fnc, litt_occ, cut_value);

	if ((ret = rec_cut(fnc, litt_occ, dist))) {
		Logger::info() << "Reassembly... \n";

		Logger::info() << copy_fnc;

		copy_fnc.cut_assign_other_value(cut_value, dist);
		copy_fnc.cut_unit_propagation(dist);
	}

	return ret;
}

bool cut_solve(const Fnc & fnc) {
	Occ_list litt_occ = Occ_list(fnc);
	Distrib dist;

	Logger::info() << "Cut algorithm\n";
	Logger::info() << fnc << "\n";
	Logger::info() << litt_occ << "\n";

	bool res = rec_cut(Fnc(fnc), litt_occ, dist);

	if (res) {
		fnc.cut_assign_other_value(0, dist);
		Logger::info() << dist;
	}

	return res;
}
