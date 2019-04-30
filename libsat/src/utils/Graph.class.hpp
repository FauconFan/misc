#ifndef GRAPH_CLASS_HPP
#define	GRAPH_CLASS_HPP

#include "libsat.hpp"

template <typename T>
class Graph
{
	public:
		Graph ();
		Graph (const Graph & rhs);
		Graph &operator=(const Graph & rhs);
		virtual~Graph ();

		void addVertex(const T & u);
		void addEdge(const T & u, const T & v);

		const std::set<T> & getVertices() const;
		const std::map<T, std::set<T> > & getEdges() const;

		std::optional<T &> findVertex(const T & v) const;

		Graph transpose() const;

		std::set<std::set<T> > getCFC() const;
		Graph<std::set<T> > getCFC_DAG(std::set<std::set<T> > * p_cfc = NULL) const;

		std::list<T> getTriTopo() const;
	private:
		std::map<T, std::set<T> > _li_edges;
		std::set<T> _li_vertices;

		void CFC_PP1(const T & s, std::map<T, bool> & colors, std::stack<T> & pile) const;
		void CFC_PP2(const T & s, std::map<T, bool> & colors, std::set<T> & C) const;

		void TriT_PP(const T & s, std::map<T, bool> & colors, std::list<T> & lst) const;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, Graph<T> const & gst);

#include "src/utils/Graph.class.tpp"

#endif // ifndef GRAPH_CLASS_HPP
