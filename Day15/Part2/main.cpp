#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef struct		s_problem
{
	vector<vector<uint8_t>>	map;
	size_t					height;
	size_t					width;
}					t_problem;

typedef struct		s_vertex
{
	int				x;
	int				y;

	bool	operator<(const struct s_vertex &vert) const {
		if (x == vert.x) return y < vert.y;
		return x < vert.x;
	}

	bool	operator==(const struct s_vertex &vert) const {
		return x == vert.x && y == vert.y;
	}

	bool	operator!=(const struct s_vertex &vert) const {
		return !(*this == vert);
	}
}					t_vertex;

ostream				&operator<<(ostream &os, const t_vertex &vert) {
	return os << "(" << vert.y << ", " << vert.x << ")";
}

typedef struct		s_graph
{
	set<t_vertex>									vertices;
	map<t_vertex, vector<pair<t_vertex, uint8_t>>>	edges;
}					t_graph;

t_problem			loadInput()
{
	t_problem			pb;
	fstream				input;
	string				line;
	vector<uint8_t>		current_line;

	input.open("../input.txt");

	while (getline(input, line)) {
		current_line.clear();
		for (const char &c: line) {
			current_line.push_back(c - '0');
		}
		pb.map.push_back(current_line);
	}
	pb.height = pb.map.size();
	pb.width = pb.map.begin()->size();

	input.close();

	return pb;
}

t_problem			extendProblemFiveAsLarge(const t_problem &pb) {
	t_problem		newPb;
	vector<uint8_t>	current_line;

	for (int j = 0; j < 5; ++j) {
		for (const vector<uint8_t> &row: pb.map) {
			current_line.clear();
			for (int i = 0; i < 5; ++i) {
				for (const uint8_t &elem: row) {
					uint8_t		newElem = elem;

					newElem += i + j;
					while (newElem >= 10) newElem -= 9;

					current_line.push_back(newElem);
				}
			}
			newPb.map.push_back(current_line);
		}
	}

	newPb.height = newPb.map.size();
	newPb.width = newPb.map.begin()->size();

	return newPb;
}

static const pair<int, int> DIRECTIONS[] = {
	make_pair(0, 1),
	make_pair(0, -1),
	make_pair(1, 0),
	make_pair(-1, 0)
};

t_graph				getGraphFromProblem(const t_problem &pb) {
	t_graph								gr;
	int									j2, i2;
	vector<pair<t_vertex, uint8_t>>		buffer_list_edges;
	t_vertex							buffer_vertices[2];

	for (int j = 0; j < pb.height; ++j) {
		for (int i = 0; i < pb.width; ++i) {
			buffer_list_edges.clear();

			buffer_vertices[0].y = j;
			buffer_vertices[0].x = i;

			for (const auto &dir: DIRECTIONS) {
				j2 = j + dir.first;
				i2 = i + dir.second;

				if (j2 >= 0 && j2 < pb.height && i2 >= 0 && i2 < pb.width) {
					buffer_vertices[1].y = j2;
					buffer_vertices[1].x = i2;

					buffer_list_edges.push_back(make_pair(buffer_vertices[1], pb.map[j2][i2]));
				}
			}

			gr.vertices.insert(buffer_vertices[0]);
			gr.edges[buffer_vertices[0]] = buffer_list_edges;
		}
	}

	return gr;
}

typedef pair<uint64_t, t_vertex>	qElem;

typedef struct						s_dijkstra_response
{
	map<t_vertex, uint64_t>				dist;
	map<t_vertex, t_vertex>				prev;
}									t_dijkstra_response;

t_dijkstra_response					dijkstra(const t_graph &gr, const t_vertex &s) {
	t_dijkstra_response										response;
	map<t_vertex, uint64_t>									dist;
	map<t_vertex, t_vertex>									prev;

	set<t_vertex>											visited;
	priority_queue<qElem, vector<qElem>, greater<qElem>>	queue;

	dist[s] = 0;
	queue.push(make_pair(0, s));

	for (const auto &v: gr.vertices) {
		dist[v] = -1; // max value
	}

	while (!queue.empty()) {
		qElem	u = queue.top();
		queue.pop();

		if (visited.find(u.second) != visited.end()) {
			continue;
		}
		visited.insert(u.second);

		for (const pair<t_vertex, uint8_t> &v_edge: gr.edges.at(u.second)) {
			uint64_t	alt;

			alt = dist[u.second] + v_edge.second;
			if (dist[v_edge.first] > alt) {
				dist[v_edge.first] = alt;
				prev[v_edge.first] = u.second;

				queue.push(make_pair(alt, v_edge.first));
			}
		}
	}

	response.dist = dist;
	response.prev = prev;

	return response;
}

int					main(void) {
	t_problem				pb;
	t_graph					gr;
	t_dijkstra_response		response;

	pb = loadInput();
	pb = extendProblemFiveAsLarge(pb);
	gr = getGraphFromProblem(pb);

	t_vertex		start;
	t_vertex		end;
	t_vertex		actu;
	t_vertex		prev;
	uint64_t		answer = 0;

	start.y = 0;
	start.x = 0;

	end.y = pb.height - 1;
	end.x = pb.width - 1;
	
	response = dijkstra(gr, start);

	actu = end;

	while (actu != start) {
		prev = response.prev[actu];

		for (const auto &d: gr.edges.at(prev)) {
			if (d.first == actu) {
				answer += d.second;
				break;
			}
		}

		actu = prev;
	}

	cout << "answer: " << answer << endl;

	return 0;
}
