#include <string.h> // strerror
#include "sat.hpp"

// This is a C-style file because we use Flex / Bison to parse Dimacs format, so we use global variables and some crazy stuff to make the things work together.

extern int yyparse();
extern FILE * yyin;
extern bool yy_ok;

std::vector<std::string> buff_lines_yyin;

static std::string      getContentFile(FILE * file) {
	std::string res("");
	char buff[200];

	while (fgets(buff, 200, file)) {
		res.append(buff);
	}
	return (res);
}

static void             fill_buff_lines_yyin(const std::string & contentFile) {
	std::string::size_type pos  = 0;
	std::string::size_type prev = 0;

	while ((pos = contentFile.find("\n", prev)) != std::string::npos) {
		buff_lines_yyin.push_back(contentFile.substr(prev, pos - prev));
		prev = pos + 1;
	}

	buff_lines_yyin.push_back(contentFile.substr(prev));
}

std::vector<AClause *> * getInputFNC(const char * path) {
	FILE * file = NULL;
	std::vector<AClause *> res;

	file = fopen(path, "r");

	if (file == NULL) {
		std::cerr << "I can't open the file : " << path << std::endl;
		std::cerr << strerror(errno) << std::endl;
		return (NULL);
	}

	fill_buff_lines_yyin(getContentFile(file));
	rewind(file);

	yyin = file;
	yyparse();

	if (yy_ok == false)
		return (NULL);

	res = FNC_builder::get().getClauses();
	fclose(file);
	return (new std::vector<AClause *>(res));
}
