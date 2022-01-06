#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>

using namespace std;

string	loadInput(void) {
	fstream		input;
	string		line;
	string		pb;

	input.open("../input.txt");

	getline(input, line);

	for (const char &c: line) {
		if (c >= '0' and c <= '9') {
			pb += bitset<4>(c - '0').to_string();
		} else {
			pb += bitset<4>(c - 'A' + 10).to_string();
		}
	}

	input.close();
	return pb;
}

typedef struct		s_packet
{
	uint8_t					version;
	uint8_t					type;
	uint64_t				value;
	vector<struct s_packet>	subpackets;



	ostream &dump(ostream &os, uint8_t depth = 0) const {
		string		prefix(depth * 4, ' ');

		os << prefix << "{" << endl;
		os << prefix << "  version: " << static_cast<int>(version) << endl;
		os << prefix << "  type: " << static_cast<int>(type) << " " << (type == 4 ? "(literal)": "(operator)") << endl;
		if (type == 4) {
			os << prefix << "  value: " << static_cast<int>(value) << endl;
		} else {
			os << prefix << "  subpackets (size = " << subpackets.size() << "): [" << endl;
			for (const auto &pack: subpackets) {
				pack.dump(os, depth + 1);
			}
			os << prefix << "  ]" << endl;
		}
		os << prefix << "}" << endl;
		return os;
	}
}					t_packet;

ostream	&operator<<(ostream &os, const t_packet &p) {
	return p.dump(os);
}

pair<t_packet, size_t>	eatPacket(const string &pb) {
	t_packet			p;
	uint64_t			value;
	size_t				pos;

	p.version = bitset<3>(pb, 0, 3).to_ulong();
	p.type = bitset<3>(pb, 3, 6).to_ulong();

	if (p.type == 4) {
		value = 0;
		pos = 6;
		while (true) {
			value = (value << 4) + bitset<4>(pb, pos + 1, pos + 5).to_ulong();
			pos += 5;
			if (pb[pos - 5] == '0') break;
		}
		p.value = value;
	} else {
		vector<t_packet>	subpackets;
		size_t				length;

		if (pb[6] == '0') { // Length type mode is 0
			size_t		endpos;

			pos = 7;
			length = bitset<15>(pb, pos, pos + 15).to_ulong();
			pos += 15;
			endpos = pos + length;

			while (pos != endpos) {
				auto p = eatPacket(pb.substr(pos));
				subpackets.push_back(p.first);
				pos += p.second;
			}
		} else { // Length type mode is 1
			pos = 7;
			length = bitset<11>(pb, pos, pos + 11).to_ulong();
			pos += 11;

			for (size_t i = 0; i < length; ++i) {
				auto p = eatPacket(pb.substr(pos));
				subpackets.push_back(p.first);
				pos += p.second;
			}
		}

		p.subpackets = subpackets;
	}

	return make_pair(p, pos);
}

t_packet		parsePacket(const string &pb) {
	auto p = eatPacket(pb);

	return p.first;
}

uint64_t		computeAnswer(const t_packet &pack) {
	uint64_t	answer;

	answer = pack.version;
	if (pack.type != 4) {
		for (const t_packet &subpack: pack.subpackets) {
			answer += computeAnswer(subpack);
		}
	}
	return answer;
}

int		main(void) {
	string			pb;
	t_packet		mainPack;
	uint64_t		answer;

	pb = loadInput();
	// cout << pb << endl;

	mainPack = parsePacket(pb);
	// cout << mainPack;

	answer = computeAnswer(mainPack);
	cout << "answer: " << answer << endl;
	return 0;
}