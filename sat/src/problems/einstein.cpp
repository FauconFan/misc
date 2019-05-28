#include "sat.hpp"

enum Nationality{
	English = 1, Swedish = 2, Danish = 3, Norwegian = 4, German = 5
};

enum Color{
	Red = 6, White = 7, Green = 8, Yellow = 9, Blue = 10
};

enum Cigarette{
	Pall_Mall = 11, Dunhill = 12, Blend = 13, Prince = 14, Bluemaster = 15
};

enum Drink{
	Tea = 16, Coffee = 17, Milk = 18, Beer = 19, Water = 20
};

enum Animal{
	Dog = 21, Bird = 22, Cat = 23, Horse = 24, Fish = 25
};

static std::string      get_str_of_caract(int id) {
	const std::string tab[] =
	{
		"English",   "Swedish", "Danish", "Norwegian", "German",
		"Red",       "White",   "Green",  "Yellow",    "Blue",
		"Pall Mall", "Dunhill", "Blend",  "Prince",    "Bluemaster",
		"Tea",       "Coffee",  "Milk",   "Beer",      "Water",
		"Dog",       "Bird",    "Cat",    "Horse",     "Fish",
	};

	if (id <= 0 || id > 25)
		return ("???");

	return (tab[id - 1]);
}

static void             print_result(const Distrib & distrib_cont) {
	const auto & distrib = distrib_cont.get_distrib();

	for (int i = 0; i < 5; ++i) {
		std::vector<int> res;
		for (int j = 0; j < 5; ++j) {
			int base = 25 * i + 5 * j + 1;
			for (int k = base; k < base + 5; ++k) {
				if (distrib.at(k)) {
					res.push_back(((k - 1) % 25) + 1);
					break;
				}
			}
		}
		// for (auto l : res)
		//     std::cout << l << " ";
		// std::cout << std::endl;
		// std::cout << res.size() << std::endl;
		std::cout
			<< "The " << get_str_of_caract(res[0])
			<< " lives in the " << get_str_of_caract(res[1]) << " house"
			<< ", smokes " << get_str_of_caract(res[2])
			<< " and drinks " << get_str_of_caract(res[3])
			<< ", with his " << get_str_of_caract(res[4])
			<< "." << std::endl;
	}
}

static void             add_relation_in_house(Fnc & fnc, int a, int b) {
	for (int base = 0; base < 25 * 5; base += 25) {
		fnc.add_clause(Clause({-(base + a), (base + b)}));
		fnc.add_clause(Clause({(base + a), -(base + b)}));
	}
}

static void             add_relation_in_house_right_house(Fnc & fnc, int a, int b) {
	for (int base = 0; base < 25 * 4; base += 25) {
		fnc.add_clause(Clause({-(base + a), (base + b + 25)}));
		fnc.add_clause(Clause({(base + a), -(base + b + 25)}));
	}
	fnc.add_clause(Clause({-(0 + b)}));
	fnc.add_clause(Clause({-(100 + a)}));
}

static void             add_relation_in_house_next_to_house(Fnc & fnc, int a, int b) {
	fnc.add_clause(Clause({-(0 + a), 25 + b}));
	fnc.add_clause(Clause({-(100 + a), 75 + b}));
	for (int base = 25; base < 25 + 25 * 3; base += 25) {
		fnc.add_clause(Clause({-(base + a), (base - 25 + b), (base + 25 + b)}));
	}
}

void                    einstein_problem() {
	Fnc fnc;
	std::vector<unsigned int> vec;
	std::list<std::string> rules;
	std::list<std::string> facts;

	Logger::disable();

	// Facts
	facts.push_back("There are 5 houses (along a street) in 5 different colors: blue, green, red, white and yellow.");
	facts.push_back("In each house lives a person of a different nationality: Brit, Dane, German, Norwegian and Swede.");
	facts.push_back(
	  "These 5 owners drink a certain beverage:beer, coffee, milk, tea and water, smoke a certain brand of cigar: Blue Master, Dunhill, Pall Mall, Prince and blend, and keep a certain pet: cat, bird, dog, fish and horse.");
	facts.push_back("No owners have the same pet, smoke the same brand of cigar, or drink the same beverage.");

	// Encoding facts

	vec.reserve(5);
	// 5 caract for each house
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			int base = 25 * i + 5 * j + 1;
			for (int k = base; k < base + 5; ++k) {
				vec.push_back(k);
			}
			fnc.add_fnc(ModelBuilder::eq_kb(vec, 1, true));
			vec.clear();
		}
	}

	// One unique caract for all houses
	for (int j = 0; j < 5; ++j) {
		for (int k = 0; k < 5; ++k) {
			int base = 5 * j + k;
			for (int i = base; i < base + 25 * 5; i += 25) {
				vec.push_back(i);
			}
			fnc.add_fnc(ModelBuilder::eq_kb(vec, 1, true));
			vec.clear();
		}
	}

	// Rules
	rules.push_back("The British man lives in the red house.");
	add_relation_in_house(fnc, English, Red);

	rules.push_back("The Swedish man has a dog for a pet.");
	add_relation_in_house(fnc, Swedish, Dog);

	rules.push_back("The Danish man drinks tea.");
	add_relation_in_house(fnc, Danish, Tea);

	rules.push_back("The green house is to the left of the white house.");
	add_relation_in_house_right_house(fnc, Green, White);

	rules.push_back("The owner of the green house drinks coffee.");
	add_relation_in_house(fnc, Green, Coffee);

	rules.push_back("The person that smokes Pall Mall has a bird.");
	add_relation_in_house(fnc, Pall_Mall, Bird);

	rules.push_back("The owner of the yellow house smokes Dunhill.");
	add_relation_in_house(fnc, Yellow, Dunhill);

	rules.push_back("The person that lives in the middle house drinks milk.");
	fnc.add_clause(Clause({50 + Milk}));

	rules.push_back("The Norwegian lives in the first house.");
	fnc.add_clause(Clause({0 + Norwegian}));

	rules.push_back("The person that smokes Blend, lives next to the one that has a cat.");
	add_relation_in_house_next_to_house(fnc, Blend, Cat);

	rules.push_back("The person that has a horse, lives next to the one that smokes Dunhill.");
	add_relation_in_house_next_to_house(fnc, Horse, Dunhill);

	rules.push_back("The one that smokes Bluemaster drinks beer.");
	add_relation_in_house(fnc, Bluemaster, Beer);

	rules.push_back("The German smokes Prince.");
	add_relation_in_house(fnc, German, Prince);

	rules.push_back("The Norwegian lives next to the blue house.");
	add_relation_in_house_next_to_house(fnc, Norwegian, Blue);

	rules.push_back("The person that smokes Blend, has a neighbour that drinks water.");
	add_relation_in_house_next_to_house(fnc, Blend, Water);

	// std::cout << fnc;

	auto p = dpll_solve(fnc);

	if (p.is_sat()) {
		std::cout << "\t\tEinstein problem:\n\n";

		std::cout << "Link : http://www.davar.net/MATH/PROBLEMS/EINSTEIN.HTM\n\n";

		std::cout << "\tFacts\n";
		int rank = 1;
		for (const auto & fact : facts) {
			std::cout << "Fact " << rank << ": " << fact << "\n";
			rank++;
		}

		std::cout << "\n\n";

		std::cout << "\tRules\n";
		rank = 1;
		for (const auto & rule : rules) {
			std::cout << "Rule " << rank << ": " << rule << "\n";
			rank++;
		}

		std::cout << "\n\n\tWho keeps fish ?";

		std::cout << "\n\n";

		print_result(p.get_distrib());

		std::cout << "\nNormally, the German has fish.\n\n";
	}
	else {
		std::cout << "Has no solution\n";
	}
} // einstein_problem
