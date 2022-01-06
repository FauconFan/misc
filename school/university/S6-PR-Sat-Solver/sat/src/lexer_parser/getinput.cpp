#include <cstring> // strerror
#include "sat.hpp"

// This is a C-style file because we use Flex / Bison to parse Dimacs format, so we use global variables and some crazy stuff to make the things work together.

extern int yyparse();
extern FILE * yyin;
extern bool yy_ok;
extern bool is_fnc;

std::vector<std::string> buff_lines_yyin;

static std::string      getContentFile(FILE * file) {
	std::string res;
	char buff[200];

	while (fgets(buff, 200, file) != nullptr) {
		res.append(buff);
	}
	return (res);
}

static void             fill_buff_lines_yyin(const std::string & contentFile) {
	std::string::size_type pos  = 0;
	std::string::size_type prev = 0;

	while ((pos = contentFile.find('\n', prev)) != std::string::npos) {
		buff_lines_yyin.push_back(contentFile.substr(prev, pos - prev));
		prev = pos + 1;
	}

	buff_lines_yyin.push_back(contentFile.substr(prev));
}

Fnc * getInputFNC(const char * path) {
	FILE * file;
	std::vector<Clause> res;

	file = fopen(path, "r");

	if (file == nullptr) {
		std::cerr << "I can't open the file : " << path << std::endl;
		std::cerr << strerror(errno) << std::endl;
		return (nullptr);
	}

	fill_buff_lines_yyin(getContentFile(file));
	rewind(file);

	yyin = file;
	yyparse();

	if (yy_ok == false)
		return (nullptr);

	if (is_fnc == false) { // sat
		try {
			Formula frml = Formula_builder::end_formula();
			fclose(file);
			return frml.formula_to_fnc();
		}
		catch (const std::exception & exc) {
			std::cout << "Exception happened when parsing... : " << exc.what() << std::endl;
			return (nullptr);
		}
	}

	res = FNC_builder::get().getClauses();
	fclose(file);
	return (new Fnc(res));
} // getInputFNC
