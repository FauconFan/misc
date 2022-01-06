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

int		main(void) {
	t_pb		pb;
	uint64_t	answer;

	pb = loadInput();

	cout << "pb.x_min: " << pb.x_min << endl;
	cout << "pb.x_max: " << pb.x_max << endl;
	cout << "pb.y_min: " << pb.y_min << endl;
	cout << "pb.y_max: " << pb.y_max << endl;

	answer = (abs(pb.y_min) - 1) * abs(pb.y_min) / 2;
	cout << "answer: " << answer << endl;

	return 0;
}
