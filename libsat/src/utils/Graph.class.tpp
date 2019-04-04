#include "libsat.hpp"

template <typename T> Graph<T>::Graph() = default;

template <typename T> Graph<T>::~Graph() = default;

template <typename T> Graph<T>::Graph(const Graph & rhs) = default;

template <typename T>
Graph<T> &Graph<T>::operator=(const Graph<T> &rhs) = default;

template <typename T>
void Graph<T>::addVertex(const T & u) {
	this->_li_vertices.insert(u);
	this->_li_edges[u];
}

template <typename T>
void Graph<T>::addEdge(const T & u, const T & v) {
	this->addVertex(u);
	this->addVertex(v);
	this->_li_edges[u].insert(v);
}

template <typename T>
const std::set<T> &Graph<T>::getVertices() const{
	return this->_li_vertices;
}

template <typename T>
const std::map<T, std::set<T> > &Graph<T>::getEdges() const{
	return this->_li_edges;
}

template <typename T>
Graph<T> Graph<T>::transpose() const{
	Graph<T> gst;
	std::set<T> vert_actu;

	for (const T & vert : this->_li_vertices) {
		vert_actu = this->_li_edges.at(vert);

		for (const T & vert2 : vert_actu) {
			gst.addEdge(vert2, vert);
		}
	}
	return (gst);
}

template <typename T>
std::set<std::set<T> > Graph<T>::getCFC() const{
	Graph gstt;
	std::set<std::set<T> > CFC;
	std::map<T, bool> colors;
	std::stack<T> pile;

	for (const T & vert : this->_li_vertices)
		colors[vert] = true;
	for (const T & vert : this->_li_vertices) {
		if (colors[vert] == true)
			this->CFC_PP1(vert, colors, pile);
	}
	for (const T & vert : this->_li_vertices)
		colors[vert] = true;
	gstt = this->transpose();
	while (pile.empty() == false) {
		std::set<T> C;
		T x;

		x = pile.top();
		pile.pop();
		if (colors[x] == true) {
			gstt.CFC_PP2(x, colors, C);
			CFC.insert(C);
		}
	}
	return (CFC);
}

template <typename T>
Graph<std::set<T> > Graph<T>::getCFC_DAG(std::set<std::set<T> > * p_cfc) const{
	Graph<std::set<T> > gst;
	std::map<T, int> m_v_id;
	std::map<int, std::set<T> > m_id_c;
	int id_cfc;
	std::set<std::set<T> > cfc;

	if (p_cfc)
		cfc = *p_cfc;
	else
		cfc = this->getCFC();
	id_cfc = 0;
	for (const auto & cc : cfc) {
		gst.addVertex(cc);
		for (const auto & elem : cc) {
			m_v_id[elem] = id_cfc;
		}
		m_id_c[id_cfc] = cc;
		++id_cfc;
	}
	for (const auto & edge : this->_li_edges) {
		T u = edge.first;
		for (const T & v : edge.second) {
			int idu = m_v_id[u];
			int idv = m_v_id[v];
			if (idu != idv) {
				gst.addEdge(m_id_c[idu], m_id_c[idv]);
			}
		}
	}
	return (gst);
}

template <typename T>
void Graph<T>::CFC_PP1(const T & s, std::map<T, bool> &colors, std::stack<T> &pile) const{
	std::set<T> vert_actu;

	colors[s] = false;
	vert_actu = this->_li_edges.at(s);
	for (const T & u : vert_actu) {
		if (colors[u] == true)
			this->CFC_PP1(u, colors, pile);
	}
	pile.push(s);
}

template <typename T>
void Graph<T>::CFC_PP2(const T & s, std::map<T, bool> &colors, std::set<T> &C) const{
	std::set<T> vert_actu;

	colors[s] = false;
	vert_actu = this->_li_edges.at(s);
	C.insert(s);
	for (const T & u : vert_actu) {
		if (colors[u] == true)
			this->CFC_PP2(u, colors, C);
	}
}

template <typename T>
std::list<T> Graph<T>::getTriTopo() const{
	std::list<T> lst;
	std::map<T, bool> colors;

	for (const T & u : this->_li_vertices)
		colors[u] = true;
	for (const T & u : this->_li_vertices) {
		if (colors[u] == true)
			this->TriT_PP(u, colors, lst);
	}
	return (lst);
}

template <typename T>
void Graph<T>::TriT_PP(const T & s, std::map<T, bool> &colors, std::list<T> &lst) const{
	std::set<T> vert_actu;

	colors[s] = false;
	vert_actu = this->_li_edges.at(s);
	for (const T & u : vert_actu) {
		if (colors[u] == true)
			this->TriT_PP(u, colors, lst);
	}
	lst.push_front(s);
}

template <typename T>
std::ostream &operator<<(std::ostream &os, Graph<T> const & gst) {
	os << "Begin Graph" << std::endl;
	for (const T & vertex : gst.getVertices()) {
		os << "Vertex " << vertex << std::endl;
		os << "\t";
		const auto & vec = gst.getEdges().at(vertex);
		for (auto it = vec.begin(); it != vec.end(); ++it) {
			if (it != vec.begin())
				os << ", ";
			os << *it;
		}
		os << std::endl;
	}
	os << "End Graph" << std::endl;
	return (os);
}
