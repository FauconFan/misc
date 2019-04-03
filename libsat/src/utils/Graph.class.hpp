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

		void addVertex(T u);
		void addEdge(T u, T v);

		const std::set<T> &getVertices() const;
		const std::unordered_map<T, std::set<T> > &getEdges() const;

		Graph transpose() const;

		std::set<std::set<T> > getCFC() const;
		Graph<std::set<T> > getCFC_DAG(std::set<std::set<T> > * p_cfc = NULL) const;

		std::stack<T> getTriTopo() const;
	private:
		std::unordered_map<T, std::set<T> > _li_edges;
		std::set<T> _li_vertices;


		void CFC_PP1(const T & s, std::unordered_map<T, bool> & colors, std::stack<T> & pile) const;
		void CFC_PP2(const T & s, std::unordered_map<T, bool> & colors, std::set<T> & C) const;

		void TriT_PP(const T & s, std::unordered_map<T, bool> & colors, std::stack<T> & stk) const;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, Graph<T> const & gst);

#include "src/utils/Graph.class.tpp"

#endif // ifndef GRAPH_CLASS_HPP
