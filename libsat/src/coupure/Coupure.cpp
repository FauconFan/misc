#include "libsat.hpp"

/* Simplifier (Une seule occurence de chaque littéral dans la prémisse (conclusion))
 * Enlever les tautologie (Retirer les clauses contenant a et -a)
 * Si x a toujours une polarité négative, la retirer partout et mettre x = 0
 * Si x a toujours une polarité positive, la retirer partout et mettre x = 1
 */
static void nettoyage (std::vector<ImplClause *> * fnc, Occ_list & litt_occ, Distrib & dist){
	std::cout << "clean... \nSimplify... ";
	litt_occ -= FNC::simplify(reinterpret_cast<std::vector<AClause *>*>(fnc));
	std::cout << "\nDelete tautologies...";
	litt_occ -= FNC::delete_tautologies(reinterpret_cast<std::vector<AClause *>*>(fnc));
	std::cout << "done\nNew litt_occ " << litt_occ;
	FNC::printFNC(reinterpret_cast<std::vector<AClause *>*>(fnc));
	
	//Suppression si polarité unique
	std::cout << "Polarity test\n";

	auto current_elt = litt_occ.begin();
	while (current_elt != litt_occ.end()){
		if (current_elt->second.first == 0){
			std::cout << current_elt->first << " has negative polarity\n";
			dist[current_elt->first]=0;
			litt_occ -= FNC::delete_if_contains(reinterpret_cast<std::vector<AClause *>*>(fnc), -current_elt->first);
			std::cout << "New litt_occ : " << litt_occ << "\n";
			FNC::printFNC(reinterpret_cast<std::vector<AClause *>*>(fnc));
			current_elt = litt_occ.begin();
		}else if (current_elt->second.second == 0){
			std::cout << current_elt->first << " has positive polarity\n";
			dist[current_elt->first]=1;
			litt_occ -= FNC::delete_if_contains(reinterpret_cast<std::vector<AClause *>*>(fnc), current_elt->first);
			std::cout << "New litt_occ : " << litt_occ << "\n";
			FNC::printFNC(reinterpret_cast<std::vector<AClause *>*>(fnc));
			current_elt = litt_occ.begin();
		}else{
			current_elt++;
		}
	}

	FNC::printFNC(reinterpret_cast<std::vector<AClause *>*>(fnc));

	std::cout << "end clean\n";
}

/*Effectue la coupure de f par rapport a val*/
static std::vector<ImplClause *> apply_cut (std::vector<ImplClause *> * fnc, Occ_list & litt_occ, unsigned int val)
{
	std::vector<ImplClause *> * cls_without_val = new std::vector<ImplClause *>();
   	std::vector<ImplClause *> * cls_with_val_premisse = new std::vector<ImplClause *>();
	std::vector<ImplClause *> * cls_with_val_conclusion = new std::vector<ImplClause *>();
	ImplClause * res_fusion;

	std::cout << "cut...\n";

	//Range les clauses pour préparer la coupure
	for (auto i = fnc->begin(); i != fnc->end(); i++){
		if ((*i)->contains_litt(-val)){
			cls_with_val_premisse->push_back(*i);
		}else if ((*i)->contains_litt(val)){
			cls_with_val_conclusion->push_back(*i);
		}else{
			cls_without_val->push_back(*i);
		}
	}
	
	std::cout << "FNC without val\n";
	FNC::printFNC(reinterpret_cast<std::vector<AClause *>*>(cls_without_val));
	std::cout << "FNC with val in premisse\n";
	FNC::printFNC(reinterpret_cast<std::vector<AClause *>*>(cls_with_val_premisse));
	std::cout << "FNC with val in conclusion\n";
	FNC::printFNC(reinterpret_cast<std::vector<AClause *>*>(cls_with_val_conclusion));

	//XXX Il faut enlever une seule fois les occurences de cls with val premisse/conclusion
	std::cout << "start cutting...\n";
	for (auto i = cls_with_val_premisse->begin(); i != cls_with_val_premisse->end(); i++){
		litt_occ -= (*i)->get_occ_list();
		for (auto j = cls_with_val_conclusion->begin(); j != cls_with_val_conclusion->end(); j++){

			if (i == cls_with_val_premisse->begin()){
				litt_occ -= (*j)->get_occ_list();
			}

			res_fusion = cut(**i, **j, val);
			std::cout << **i << " ; " << **j << " -> " << *res_fusion;
			if (!res_fusion->is_tautology() && !FNC::contains(reinterpret_cast<std::vector<AClause *>*>(cls_without_val), res_fusion)){
				cls_without_val->push_back(res_fusion);
				litt_occ += res_fusion->get_occ_list();
			}
		}
	}

	std::cout << "fnc became : ";

	FNC::printFNC(reinterpret_cast<std::vector<AClause *>*>(cls_without_val));

	std::cout << "New litt_occ : " << litt_occ << "\nend cut\n" ;

	return *cls_without_val;
}

static bool rec_cut (std::vector<ImplClause *> fnc, Occ_list & litt_occ, Distrib dist){
	nettoyage (&fnc, litt_occ, dist);

	if (litt_occ.empty()){
		return fnc.empty();
	}

	auto i = litt_occ.begin();

	std::cout << "val to cut " << i->first << "\n";

	FNC::printFNC(reinterpret_cast<std::vector<AClause *>*>(&fnc));

	fnc = apply_cut(&fnc, litt_occ, i->first);

	return rec_cut (fnc, litt_occ, dist);
}

/*Distrib **/bool cut_solve (std::vector<ImplClause *> fnc){
	Occ_list litt_occ;
	Distrib dist;

	init_litt_occ (litt_occ, fnc);

	std::cout << litt_occ;

	return rec_cut(fnc, litt_occ, dist);
}
