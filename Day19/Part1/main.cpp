#include <iostream>
#include <fstream>

#include <vector>
#include <array>
#include <set>
#include <map>

#include <cmath>

using namespace std;

struct		Point
{
	int		x, y, z;

	bool operator<(const Point &p2) const {
		if (x == p2.x && y == p2.y) return z < p2.z;
		else if (x == p2.x) return y < p2.y;
		return x < p2.x;
	}
};

ostream	&operator<<(ostream &os, const Point &pt) {
	return os << pt.x << "," << pt.y << "," << pt.z;
}

struct		Scanner
{
	vector<Point>	points;
};

struct		Problem
{
	vector<Scanner>	scanners;
};

Point				point_add(const Point &p1, const Point &p2) {
	Point		res;

	res.x = p1.x + p2.x;
	res.y = p1.y + p2.y;
	res.z = p1.z + p2.z;
	return res;
}

Point				point_diff(const Point &p1, const Point &p2) {
	Point		res;

	res.x = p1.x - p2.x;
	res.y = p1.y - p2.y;
	res.z = p1.z - p2.z;
	return res;
}

using Matrix3D = array<array<int, 3>, 3>;

Matrix3D			mat_mul(const Matrix3D &m1, const Matrix3D &m2) {
	Matrix3D	res;

	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < 3; ++j) {
			res[i][j] = 0;
		}
	}

	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < 3; ++j) {
			for (size_t k = 0; k < 3; ++k) {
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}

	return res;
}

Point				mat_mul(const Matrix3D &mat, const Point &p) {
	Point		res;

	res.x = mat[0][0] * p.x + mat[0][1] * p.y + mat[0][2] * p.z;
	res.y = mat[1][0] * p.x + mat[1][1] * p.y + mat[1][2] * p.z;
	res.z = mat[2][0] * p.x + mat[2][1] * p.y + mat[2][2] * p.z;
	return res;
}

Matrix3D			mat_transp(const Matrix3D &mat) {
	Matrix3D	res;

	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < 3; ++j) {
			res[i][j] = mat[j][i];
		}
	}
	return res;
}

void				mat_print(const Matrix3D &m) {
	cout << "[[" << m[0][0] << ", " << m[0][1] << ", " << m[0][2] << "]" << endl;
	cout << " [" << m[1][0] << ", " << m[1][1] << ", " << m[1][2] << "]" << endl;
	cout << " [" << m[2][0] << ", " << m[2][1] << ", " << m[2][2] << "]]" << endl;
}

enum	around_axis
{
	AROUND_X,
	AROUND_Y,
	AROUND_Z
};

Matrix3D			mat_rotation(int piover2_factor, enum around_axis aroundAxis) {
	Matrix3D	res;
	double		cosOf_double;
	double		sinOf_double;
	int			cosOf;
	int			sinOf;

	cosOf_double = cos(piover2_factor * M_PI_2);
	sinOf_double = sin(piover2_factor * M_PI_2);

	if (cosOf_double > 0.5) cosOf = 1;
	else if (cosOf_double < -0.5) cosOf = -1;
	else cosOf = 0;

	if (sinOf_double > 0.5) sinOf = 1;
	else if (sinOf_double < -0.5) sinOf = -1;
	else sinOf = 0;

	switch (aroundAxis)
	{
		case AROUND_X:
			res = {{
				{1, 0, 0},
				{0, cosOf, sinOf},
				{0, -sinOf, cosOf}
			}};
			break;
		case AROUND_Y:
			res = {{
				{cosOf, 0, -sinOf},
				{0, 1, 0},
				{sinOf, 0, cosOf}
			}};
			break;
		case AROUND_Z:
			res = {{
				{cosOf, sinOf, 0},
				{-sinOf, cosOf, 0},
				{0, 0, 1}
			}};
			break;
	}

	return res;
}

vector<Matrix3D>	generateAllOrientations(void) {
	vector<Matrix3D>		res;

	vector<Matrix3D>		rotations;
	vector<Matrix3D>		facings;

	for (int i = 0; i < 4; ++i) {
		rotations.push_back(mat_rotation(i, AROUND_Y));
	}
	rotations.push_back(mat_rotation(1, AROUND_Z));
	rotations.push_back(mat_rotation(3, AROUND_Z));

	for (int i = 0; i < 4; ++i) {
		facings.push_back(mat_rotation(i, AROUND_X));
	}

	for (const Matrix3D &rot: rotations) {
		for (const Matrix3D &facing: facings) {
			res.push_back(mat_mul(rot, facing));
		}
	}

	return res;
}

Problem		loadInput(void) {
	fstream			input;
	Problem			pb;
	Scanner			sc;
	Point			pt;
	string			line;
	size_t			pos[2];

	input.open("../input.txt");

	while (true) {
		getline(input, line);

		if (input.fail()) break;

		sc.points.clear();

		while (true) {
			getline(input, line);
			if (input.fail() || line.length() == 0) break;

			pos[0] = line.find(',');
			pt.x = stoi(line.substr(0, pos[0]));
			pos[0]++;
			pos[1] = line.find(',', pos[0]);
			pt.y = stoi(line.substr(pos[0], pos[1] - pos[0]));
			pos[1]++;
			pt.z = stoi(line.substr(pos[1]));

			sc.points.push_back(pt);
		}
		
		pb.scanners.push_back(sc);
	}

	input.close();
	return pb;
}

struct		ResOverlap
{
	Matrix3D	orient;
	Point		offset;
};

optional<ResOverlap>	overlap(
			const vector<Matrix3D> &allOrientations,
			const set<Point> &points,
			const Scanner &sc) {

	for (const Matrix3D &orient: allOrientations) {
		map<Point, int>		matches;

		for (const Point &p1: points) {
			for (const Point &p2: sc.points) {
				Point p2_projected = mat_mul(orient, p2);
				Point offset = point_diff(p1, p2_projected);

				auto it = matches.find(offset);
				if (it == matches.end()) matches[offset] = 1;
				else it->second++;
			}
		}

		for (const auto &p: matches) {
			if (p.second >= 12) {
				ResOverlap	res;

				res.orient = orient;
				res.offset = p.first;
				return optional(res);
			}
		}
	}

	return nullopt;
}

using positionAndOrientation = pair<Matrix3D, Point>;

int		main(void) {
	Problem									pb;
	vector<Matrix3D>						allOrientations;
	set<size_t>								isFound;
	set<Point>								actualPoints;

	allOrientations = generateAllOrientations();

	pb = loadInput();

	isFound.insert(0);
	for (const Point &p: pb.scanners[0].points) {
		actualPoints.insert(p);
	}

	while (isFound.size() != pb.scanners.size()) {

		for (size_t i = 0; i < pb.scanners.size(); ++i) {
			if (isFound.find(i) != isFound.end()) continue;

			optional<ResOverlap>	resOverlap = overlap(
													allOrientations,
													actualPoints,
													pb.scanners[i]);
			
			if (resOverlap) {
				cout << "overlap found with scanner " << i << endl;

				for (const Point &p: pb.scanners[i].points) {
					Point p_projected = point_add(
						mat_mul(resOverlap->orient, p),
						resOverlap->offset
					);
					actualPoints.insert(p_projected);
				}
				isFound.insert(i);
				break;
			}
		}
	}

	cout << "answer: " << actualPoints.size() << endl;

	return 0;
}
