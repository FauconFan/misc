#include "libsat.hpp"

static Graph<int>   buildGraph2SAT(const Fnc & fnc) {
	Graph<int> res;

	for (const auto & cl : fnc.get_clauses()) {
		const auto & litts = cl.build_litts();
		const auto val1    = *litts.cbegin();
		const auto val2    = *(litts.cbegin()++);


		res.addEdge(-val1, val2);
		res.addEdge(-val2, val1);
	}
	return (res);
}

static bool         isSat(const std::set<std::set<int> > &cfc) {
	for (const auto & Cc : cfc) {
		std::set<int> marked;

		for (const auto & elem : Cc) {
			int id = abs(elem);
			if (marked.find(id) != marked.end())
				return (false);

			marked.insert(id);
		}
	}
	return (true);
}

static std::map<std::set<int>, int> build_cc_ID_from_CFC(const std::set<std::set<int> > & cfc) {
	int id_incr;
	std::map<std::set<int>, int> res;
	std::map<int, int> m_ver;

	id_incr = 1;
	for (const auto & Cc : cfc) {
		int actu = *(Cc.begin());

		if (m_ver.find(-actu) == m_ver.end()) {
			res[Cc] = id_incr;
			for (const auto & elem : Cc) {
				m_ver[elem] = id_incr;
			}
			id_incr++;
		}
		else {
			int id_actu = m_ver[-actu];

			res[Cc] = id_actu;
			for (const auto & elem : Cc) {
				m_ver[elem] = id_actu;
			}
		}
	}
	return (res);
}

static Distrib          build_solution(
  const std::map<std::set<int>, int> & m_con_did,
  const std::list<std::set<int> > & tri_topo) {
	Distrib dist;
	std::set<int> marked;

	for (const auto & Cc : tri_topo) {
		int id_actu = m_con_did.at(Cc);

		if (marked.find(id_actu) == marked.end()) {
			marked.insert(id_actu);
		}
		else {
			for (const auto & elem : Cc) {
				dist.set(abs(elem), elem > 0);
			}
		}
	}
	return (dist);
}

std::pair<bool, Distrib> twosat_solve(const Fnc & fnc) {
	Graph<int> gst;
	std::set<std::set<int> > cfc;
	std::map<std::set<int>, int> m_con_did;
	std::list<std::set<int> > tri_topo;

	Logger::info() << "Two sat Algorithm\n";
	if (fnc.is_two_fnc() == false) {
		Logger::info() << "The fnc given is not a 2 fnc\n";
		return std::make_pair(false, Distrib());
	}
	Logger::info() << "Building graph of implications\n";
	gst = buildGraph2SAT(fnc);
	Logger::info() << "Building Cfc of the graph\n";
	cfc = gst.getCFC();
	Logger::info() << "Checking inconsistent condition to satisfaisability\n";
	if (isSat(cfc) == false) {
		Logger::info() << "The fnc is not satisfaisable\n";
		return std::make_pair(false, Distrib());
	}
	Logger::info() << "Building solution\n";
	m_con_did = build_cc_ID_from_CFC(cfc);
	tri_topo  = gst.getCFC_DAG(&cfc).getTriTopo();
	return std::make_pair(true, build_solution(m_con_did, tri_topo));
}
