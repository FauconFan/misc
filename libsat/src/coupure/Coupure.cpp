#include "libsat.hpp"

/* Simplifier (Une seule occurence de chaque littéral dans la prémisse (conclusion))
 * Enlever les tautologie (Retirer les clauses contenant a et -a)
 * Si x a toujours une polarité négative, la retirer partout et mettre x = 0
 * Si x a toujours une polarité positive, la retirer partout et mettre x = 1
 */
static void nettoyage (std::vector<ImplClause> * fnc, Occ_list & litt_occ, Distrib & dist){
	FNC::simplify(reinterpret_cast<std::vector<AClause *>*>(fnc));
	FNC::delete_tautologies(reinterpret_cast<std::vector<AClause *>*>(fnc));
	
	//Suppression si polarité unique
	for (auto i = litt_occ.begin(); i != litt_occ.end(); i++){
		//Il faut supprimer toutes les clauses contenant i->first
		if (i->second.first == 0){
			dist[i->first]=0;
			//fnc.delete_contains(unsigned int *i)
			litt_occ.erase(i);
		}else if (i->second.second == 0){
			dist[i->first]=1;
			//fnc.delete_clause_contains(unsigned int *i)
			litt_occ.erase(i);
		}
	}
}

/*Effectue la coupure de f par rapport a val*/
static void apply_cut (std::vector<ImplClause> fnc, unsigned int val)
{
	std::vector<ImplClause> cls_without_val, cls_with_val_premisse, cls_with_val_conclusion;
	ImplClause res_fusion;

	//Range les clauses pour préparer la coupure
	for (auto i = fnc.begin(); i != fnc.end(); i++){
		if (i->contains_litt(val)){
			cls_with_val_premisse.push_back(*i);
		}else if (i->contains_litt(-val)){
			cls_with_val_conclusion.push_back(*i);
		}else{
			cls_without_val.push_back(*i);
		}
	}

	//Il faut rajouter les nouvelles occurences dans litt_occ
	for (auto i = cls_with_val_premisse.begin(); i != cls_with_val_premisse.end(); i++){
		for (auto j = cls_with_val_conclusion.begin(); j != cls_with_val_conclusion.end(); j++){
			res_fusion = *cut(*i, *j);
			if (!res_fusion.is_tautology() /*&& !cls_without_val.contains(res_fusion)*/)
				cls_without_val.push_back(res_fusion);
		}
	}

	fnc = cls_without_val;
}

static bool rec_cut (std::vector<ImplClause> fnc, Occ_list litt_occ, Distrib dist){
	auto i = litt_occ.begin();

	if (i == litt_occ.end()){
		return true;
	}

	nettoyage (&fnc, litt_occ, dist);
	apply_cut(fnc, i->first);
	return rec_cut (fnc, litt_occ, dist);
}

/*Distrib **/bool cut_solve (std::vector<ImplClause> fnc){
	Occ_list litt_occ;
	Distrib dist;

	init_litt_occ (litt_occ, fnc);

	return rec_cut(fnc, litt_occ, dist);
}
