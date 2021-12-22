#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

struct	Cuboid
{
	int		xMin;
	int		xMax;
	int		yMin;
	int		yMax;
	int		zMin;
	int		zMax;

	bool	doIgnore(void) const {
		if (abs(xMin) > 50) return true;
		if (abs(xMax) > 50) return true;
		if (abs(yMin) > 50) return true;
		if (abs(yMax) > 50) return true;
		if (abs(zMin) > 50) return true;
		if (abs(zMax) > 50) return true;

		return false;
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

		pb.cuboids.push_back({line.substr(0, 2) == "on", cub});
	}

	input.close();
	return pb;
}

int			main(void) {
	Problem			pb;
	set<Point3D>	points;

	pb = loadInput();

	for (const auto &p: pb.cuboids) {
		bool	on = p.first;
		Cuboid	cub = p.second;

		if (cub.doIgnore()) continue;

		for (int x = cub.xMin; x <= cub.xMax; ++x) {
			for (int y = cub.yMin; y <= cub.yMax; ++y) {
				for (int z = cub.zMin; z <= cub.zMax; ++z) {
					Point3D		pt;

					pt.x = x;
					pt.y = y;
					pt.z = z;
					if (on) points.insert(pt);
					else points.erase(pt);
				}
			}
		}
	}

	cout << "answer: " << points.size() << endl;

	return 0;
}
