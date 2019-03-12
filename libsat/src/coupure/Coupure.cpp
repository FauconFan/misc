#include "libsat.hpp"

//Eviter les variables 
occ_list litt_occ;
Distrib dist;

static void simplify (std::vector<ImplClause> fnc){
	unsigned int i;

	for (i = 0; i < fnc.size(); i++){
		fnc.at(i).simplify_clause(litt_occ);
	}
}

static void delete_tautologies (std::vector<ImplClause> fnc){
	unsigned int i;

	for (i = 0; i < fnc.size(); i++){
		if (fnc.at(i).isTautology()){
			fnc.erase(fnc.begin()+i);
			i--;
		}
	}
}

/* Simplifier (Une seule occurence de chaque littéral dans la prémisse (conclusion))
 * Enlever les tautologie (Retirer les clauses contenant a et -a)
 * Si x a toujours une polarité négative, la retirer partout et mettre x = 0
 * Si x a toujours une polarité positive, la retirer partout et mettre x = 1
 */
static void nettoyage (std::vector<ImplClause> fnc){
	simplify(fnc);
	delete_tautologies(fnc);
	
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

static void init_litt_occ (std::vector<ImplClause> fnc){
	unsigned int i, j, current_elt;
	std::vector<unsigned int> pos_litts, neg_litts;

	for (i = 0; i < fnc.size(); i++){
		pos_litts = *(fnc.at(i).getPosLitts());

		for (j = 0; j < pos_litts.size(); j++){
			current_elt = pos_litts.at(j);

			if (litt_occ.count(current_elt) == 0)
				litt_occ[current_elt]=pair(1, 0);
			else
				litt_occ[current_elt]=litt_occ[current_elt] + pair(1, 0);
		}

		neg_litts = *(fnc.at(i).getNegLitts());

		for (j = 0; j < neg_litts.size(); j++){
			current_elt = neg_litts.at(j);

			if (litt_occ.count(current_elt) == 0)
				litt_occ[current_elt]=pair(0, 1);
			else
				litt_occ[current_elt]=litt_occ[current_elt] + pair(0, 1);
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
			res_fusion = cut(*i, *j);
			if (!res_fusion.isTautology() /*&& !cls_without_val.contains(res_fusion)*/)
				cls_without_val.push_back(res_fusion);
		}
	}

	fnc = cls_without_val;
}

/*Distrib **/void cut_solve (std::vector<ImplClause> fnc){
	init_litt_occ (fnc);

	while (litt_occ.empty() == false) {
		auto i = litt_occ.begin();
		nettoyage (fnc);
		apply_cut(fnc, i->first);
	}

	return;
}
