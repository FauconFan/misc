#include <iostream>
#include <fstream>

#include <vector>
#include <set>

#include <algorithm>

using namespace std;

struct	Cuboid
{
	int		xMin;
	int		xMax;
	int		yMin;
	int		yMax;
	int		zMin;
	int		zMax;

	bool		operator==(const Cuboid &cub) const {
		return xMin == cub.xMin && xMax == cub.xMax && \
				yMin == cub.yMin && yMax == cub.yMax && \
				zMin == cub.zMin && zMax == cub.zMax;
	}

	uint64_t	volume() const {
		uint64_t	x = xMax - xMin;
		uint64_t	y = yMax - yMin;
		uint64_t	z = zMax - zMin;

		return x * y * z;
	}
};

struct	Point3D
{
	int		x;
	int		y;
	int		z;

	bool	operator<(const Point3D &pt) const {
		if (x == pt.x) {
			if (y == pt.y) return z < pt.z;
			return y < pt.y;
		}
		return x < pt.x;
	}

	bool	operator==(const Point3D &pt) const {
		return x == pt.x && y == pt.y && z == pt.z;
	}
};

ostream		&operator<<(ostream &os, const Cuboid &cub) {
	return os << "x->[" << cub.xMin << "," << cub.xMax << "] "
			<< "y->[" << cub.yMin << "," << cub.yMax << "] "
			<< "z->[" << cub.zMin << "," << cub.zMax << "]";
}

struct	Problem
{
	vector<pair<bool, Cuboid>>	cuboids;
};

Problem		loadInput(void) {
	Problem		pb;
	fstream		input;
	string		line;
	Cuboid		cub;
	size_t		pos[2];

	input.open("../input.txt");

	while (getline(input, line)) {
		pos[0] = line.find('=') + 1;
		pos[1] = line.find('.', pos[0]);
		cub.xMin = stoi(line.substr(pos[0], pos[1] - pos[0]));

		pos[0] = pos[1] + 2;
		pos[1] = line.find(',', pos[0]);
		cub.xMax = stoi(line.substr(pos[0], pos[1] - pos[0]));

		pos[0] = line.find('=', pos[0]) + 1;
		pos[1] = line.find('.', pos[0]);
		cub.yMin = stoi(line.substr(pos[0], pos[1] - pos[0]));

		pos[0] = pos[1] + 2;
		pos[1] = line.find(',', pos[0]);
		cub.yMax = stoi(line.substr(pos[0], pos[1] - pos[0]));

		pos[0] = line.find('=', pos[0]) + 1;
		pos[1] = line.find('.', pos[0]);
		cub.zMin = stoi(line.substr(pos[0], pos[1] - pos[0]));

		pos[0] = pos[1] + 2;
		pos[1] = line.find(',', pos[0]);
		cub.zMax = stoi(line.substr(pos[0], pos[1] - pos[0]));

		cub.xMax += 1;
		cub.yMax += 1;
		cub.zMax += 1;
		pb.cuboids.push_back({line.substr(0, 2) == "on", cub});
	}

	input.close();
	return pb;
}

optional<Cuboid>	findIntersection(const Cuboid &c1, const Cuboid &c2) {
	int xMin = max(c1.xMin, c2.xMin);
	int xMax = min(c1.xMax, c2.xMax);
	int yMin = max(c1.yMin, c2.yMin);
	int yMax = min(c1.yMax, c2.yMax);
	int zMin = max(c1.zMin, c2.zMin);
	int zMax = min(c1.zMax, c2.zMax);

	if (xMin > xMax) return nullopt;
	if (yMin > yMax) return nullopt;
	if (zMin > zMax) return nullopt;

	Cuboid	res;

	res.xMin = xMin;
	res.xMax = xMax;
	res.yMin = yMin;
	res.yMax = yMax;
	res.zMin = zMin;
	res.zMax = zMax;
	return res;
}

vector<Cuboid>		remainingParts(const Cuboid &cub, const Cuboid &inner) {
	vector<Cuboid>			res;
	vector<pair<int, int>>	xs;
	vector<pair<int, int>>	ys;
	vector<pair<int, int>>	zs;

	auto add = [](int left, int right, vector<pair<int, int>> &xs) {
		if (left < right) {
			xs.push_back({left, right});
		}
	};

	add(cub.xMin, inner.xMin, xs);
	add(inner.xMin, inner.xMax, xs);
	add(inner.xMax, cub.xMax, xs);

	add(cub.yMin, inner.yMin, ys);
	add(inner.yMin, inner.yMax, ys);
	add(inner.yMax, cub.yMax, ys);

	add(cub.zMin, inner.zMin, zs);
	add(inner.zMin, inner.zMax, zs);
	add(inner.zMax, cub.zMax, zs);

	for (const auto &x: xs) {
		for (const auto &y: ys) {
			for (const auto &z: zs) {
				Cuboid		actu;

				actu.xMin = x.first;
				actu.xMax = x.second;
				actu.yMin = y.first;
				actu.yMax = y.second;
				actu.zMin = z.first;
				actu.zMax = z.second;

				if (!(actu == inner)) res.push_back(actu);
			}
		}
	}
	return res;
}

int			main(void) {
	Problem			pb;
	uint64_t		answer = 0;
	vector<Cuboid>	effsOn;

	pb = loadInput();

	// findIntersection(pb.cuboids[0].second, pb.cuboids[1].second);

	for (const auto &p: pb.cuboids) {
		bool	on = p.first;
		Cuboid	cub = p.second;

		for (int i = effsOn.size() - 1; i >= 0; --i) {
			auto intersection = findIntersection(effsOn[i], cub);

			if (intersection.has_value()) {
				auto remaining = remainingParts(effsOn[i], *intersection);
				for (const auto &cc: remaining) {
					effsOn.push_back(cc);
				}
				effsOn.erase(effsOn.begin() + i);
			}
		}

		if (on) {
			effsOn.push_back(cub);
		}
	}

	for (const auto &cub: effsOn) {
		answer += cub.volume();
	}

	cout << "answer: " << answer << endl;

	return 0;
}
