#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

typedef struct		s_pb
{
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;
}					t_pb;

t_pb	loadInput(void) {
	t_pb		pb;
	fstream		input;
	string		line;
	size_t		pos[2];

	input.open("../input.txt");

	getline(input, line);

	pos[0] = line.find('=') + 1;
	pos[1] = line.find('.');
	pb.x_min = stoi(line.substr(pos[0], pos[1] - pos[0]));
	pos[0] = line.find(',');
	pos[1] += 2;
	pb.x_max = stoi(line.substr(pos[1], pos[0] - pos[1]));

	pos[0] = line.find('=', pos[0]) + 1;
	pos[1] = line.find('.', pos[0]);
	pb.y_min = stoi(line.substr(pos[0], pos[1] - pos[0]));
	pos[1] += 2;
	pb.y_max = stoi(line.substr(pos[1]));

	input.close();

	return pb;
}

bool	simulateTrajectory(const t_pb &pb, int vx, int vy, int x = 0, int y = 0) {
	if (vx == 0 && (x < pb.x_min || x > pb.x_max)) {
		return false;
	}
	else if (y < pb.y_min) {
		return false;
	}
	else if (x >= pb.x_min && x <= pb.x_max && y >= pb.y_min && y <= pb.y_max) {
		return true;
	}

	x += vx;
	y += vy;

	vy -= 1;
	if (vx > 0) vx -= 1;
	else if (vx < 0) vx += 1;

	return simulateTrajectory(pb, vx, vy, x, y);
}

size_t	count(const t_pb &pb) {
	size_t		answer = 0;

	for (int vx = 1; vx <= pb.x_max; ++vx) {
		for (int vy = pb.y_min; vy <= -pb.y_min; ++vy) {
			if (simulateTrajectory(pb, vx, vy)) {
				answer++;
			}
		}
	}
	return answer;
}

int		main(void) {
	t_pb		pb;
	uint64_t	answer;

	pb = loadInput();

	answer = count(pb);
	cout << "answer: " << answer << endl;

	return 0;
}
