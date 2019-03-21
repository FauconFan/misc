#include "cimp.h"

extern t_li_token    *scan_string(const char * str);

void    next_parser(char * line) {
	t_li_token	*li_toks;
	li_toks = scan_string(line);

	if (li_toks) {
		li_token_print(li_toks);
		li_token_free(li_toks);
	}
}
