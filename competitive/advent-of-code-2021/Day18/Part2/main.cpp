#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

enum		e_nailtype
{
	NT_LITERAL,
	NT_PAIR
};

class		c_nailnum
{
public:
	e_nailtype				type;
	c_nailnum				*parent;
	union {
		uint8_t				literal;
		struct {
			c_nailnum		*left;
			c_nailnum		*right;
		}					p;
	}						u;

	c_nailnum () = delete;

	virtual ~c_nailnum () {
		if (this->type == NT_PAIR) {
			delete this->u.p.left;
			delete this->u.p.right;
		}
	}

	c_nailnum (const c_nailnum &rhs) {
		this->type = rhs.type;
		this->parent = rhs.parent;
		if (this->type == NT_LITERAL) {
			this->u.literal = rhs.u.literal;
		} else {
			this->u.p.left = new c_nailnum(*rhs.u.p.left);
			this->u.p.right = new c_nailnum(*rhs.u.p.right);
			this->u.p.left->parent = this;
			this->u.p.right->parent = this;
		}
	}

	c_nailnum (const c_nailnum *root) {
		this->type = root->type;
		this->parent = NULL;
		if (this->type == NT_LITERAL) {
			this->u.literal = root->u.literal;
		} else {
			this->u.p.left = new c_nailnum(root->u.p.left);
			this->u.p.right = new c_nailnum(root->u.p.right);
			this->u.p.left->parent = this;
			this->u.p.right->parent = this;
		}
	}

	c_nailnum (uint8_t litteral) {
		this->type = NT_LITERAL;
		this->parent = NULL;
		this->u.literal = litteral;
	}

	c_nailnum (c_nailnum *left, c_nailnum *right) {
		this->type = NT_PAIR;
		this->parent = NULL;
		this->u.p.left = left;
		this->u.p.right = right;
		left->parent = this;
		right->parent = this;
	}

	uint64_t	computeMagnitude() const {
		if (this->type == NT_LITERAL) {
			return this->u.literal;
		}
		return 3 * this->u.p.left->computeMagnitude() + \
				2 * this->u.p.right->computeMagnitude();
	}

	void		addToRightMost(uint8_t val) {
		if (this->type == NT_LITERAL) {
			this->u.literal += val;
		} else {
			this->u.p.right->addToRightMost(val);
		}
	}

	void		addToLeftMost(uint8_t val) {
		if (this->type == NT_LITERAL) {
			this->u.literal += val;
		} else {
			this->u.p.left->addToLeftMost(val);
		}
	}

	void		addToRightMostOnLeft(uint8_t val) {
		if (this->parent == NULL) return;

		if (this->parent->u.p.left == this) {
			this->parent->addToRightMostOnLeft(val);
		} else {
			this->parent->u.p.left->addToRightMost(val);
		}
	}

	void		addToLeftMostOnRight(uint8_t val) {
		if (this->parent == NULL) return;

		if (this->parent->u.p.right == this) {
			this->parent->addToLeftMostOnRight(val);
		} else {
			this->parent->u.p.right->addToLeftMost(val);
		}
	}

	void		replaceWithZero() {
		if (this->parent) {
			c_nailnum	*zero = new c_nailnum(static_cast<uint8_t>(0));

			if (this->parent->u.p.left == this) {
				this->parent->u.p.left = zero;
			} else {
				this->parent->u.p.right = zero;
			}
			zero->parent = this->parent;
			this->parent = NULL;
		}
		delete this;
	}

	bool		explode(size_t depth = 0) {

		if (this->type == NT_PAIR && depth == 4) {
			// We assume that pair is made of regular numbers
			if (this->u.p.left->type != NT_LITERAL || this->u.p.right->type != NT_LITERAL) {
				cerr << "Error in the data" << endl;
				exit(1);
			}

			this->addToRightMostOnLeft(this->u.p.left->u.literal);
			this->addToLeftMostOnRight(this->u.p.right->u.literal);

			this->replaceWithZero();

			return true;
		}
		
		if (this->type == NT_PAIR) {
			if (this->u.p.left->explode(depth + 1)) return true;
			if (this->u.p.right->explode(depth + 1)) return true;
		}

		return false;
	}

	bool		split() {
		uint8_t		val;

		if (this->type == NT_LITERAL && this->u.literal >= 10) {
			val = this->u.literal;

			this->type = NT_PAIR;
			this->u.p.left = new c_nailnum(val / 2);
			this->u.p.right = new c_nailnum(val - val / 2);

			this->u.p.left->parent = this;
			this->u.p.right->parent = this;
			return true;
		}

		if (this->type == NT_PAIR) {
			if (this->u.p.left->split()) return true;
			if (this->u.p.right->split()) return true;
		}

		return false;
	}

	void		reduce() {
		while (true) {
			if (this->explode()) continue;
			if (this->split()) continue;
			break;
		}
	}

	ostream		&dumpString(ostream &os) const {
		if (this->type == NT_LITERAL) {
			os << static_cast<int>(this->u.literal);
		} else {
			os << '[';
			this->u.p.left->dumpString(os);
			os << ',';
			this->u.p.right->dumpString(os);
			os << ']';
		}
		return os;
	}

	ostream		&dump(ostream &os, size_t depth = 0) const {
		string		prefix(2 * depth, ' ');

		if (this->type == NT_LITERAL) {
			os << prefix << "NUM: " << static_cast<int>(this->u.literal);
			if (this->parent != NULL) {
				os << " has parent";
			}
			os << endl;
		} else {
			os << prefix << "PAIR:";
			if (this->parent != NULL) {
				os << " has parent";
			}
			os << endl;
			this->u.p.left->dump(os, depth + 1);
			this->u.p.right->dump(os, depth + 1);
		}
		return os;
	}
};

ostream	&operator<<(ostream &os, const c_nailnum &nailnum) {
	nailnum.dumpString(os);
	os << endl;
	// return nailnum.dump(os);
	return os;
}

typedef struct		s_pb
{
	vector<c_nailnum *>	nums;
}					t_pb;

c_nailnum			*eatNailNum(const string &line, size_t *endpos = NULL, size_t depth = 0) {
	size_t		nextEndPos[2];
	c_nailnum	*nailnum;
	string		prefix(2 * depth, ' ');

	if (line[0] == '[') {
		c_nailnum	*left, *right;

		left = eatNailNum(line.substr(1), &nextEndPos[0], depth + 1);
		nextEndPos[0] += 1 + 1;

		right = eatNailNum(line.substr(nextEndPos[0]), &nextEndPos[1], depth + 1);
		nextEndPos[1] += nextEndPos[0] + 1;

		nailnum = new c_nailnum(left, right);
		left->parent = nailnum;
		right->parent = nailnum;

		if (endpos) *endpos = nextEndPos[1];
	} else {
		size_t		length = 1;

		if (isdigit(line[1])) length++;
		nailnum = new c_nailnum(stoi(line.substr(0, length)));
		if (endpos) *endpos = length;
	}
	return nailnum;
}

t_pb				loadInput() {
	t_pb				pb;
	fstream				input;
	string				line;
	c_nailnum			*nailnum;
	vector<c_nailnum *>	nums;

	input.open("../input.txt");

	while(getline(input, line)) {
		nailnum = eatNailNum(line);

		nums.push_back(nailnum);
	}

	pb.nums = nums;

	input.close();

	return pb;
}

int		main(void) {
	t_pb		pb;
	c_nailnum	*num;
	uint64_t	answer = 0;
	uint64_t	cand;

	pb = loadInput();

	for (size_t i = 0; i < pb.nums.size(); ++i) {
		for (size_t j = 0; j < pb.nums.size(); ++j) {
			num = new c_nailnum(new c_nailnum(pb.nums[i]), new c_nailnum(pb.nums[j]));

			num->reduce();
			cand = num->computeMagnitude();

			if (answer < cand) {
				answer = cand;
			}
			delete num;
		}
	}

	cout << "answer: " << answer << endl;

	for (size_t i = 0; i < pb.nums.size(); ++i) {
		delete pb.nums[i];
	}
	
	pb.nums.clear();

	return 0;
}
