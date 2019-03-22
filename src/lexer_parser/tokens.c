#include "cimp.h"

static t_token * token_alloc(t_type_token type_token) {
	t_token * tok;

	if ((tok = malloc(sizeof(t_token))) == NULL) {
		printf("%s\n", MALLOC_FAIL);
		return (NULL);
	}
	memset(tok, 0, sizeof(t_token));
	tok->type = type_token;
	return (tok);
}

void                print_token(t_token * tok) {
	if (tok == NULL)
		return;

	switch (tok->type) {
		case NUM:
			printf("NUM(%ld)\n", tok->u.num);
			break;
		case WORD:
			printf("WORD(%s)\n", tok->u.str);
			break;
		case PATH:
			printf("PATH(%s)\n", tok->u.str);
			break;
		case RECT:
			printf("RECT(%d %d %d %d)\n", tok->u.rect.x, tok->u.rect.y, tok->u.rect.w, tok->u.rect.h);
			break ;
	}
}

t_token * token_word(const char * word) {
	t_token * tok;

	if ((tok = token_alloc(WORD)) == NULL)
		return (NULL);

	tok->u.str = dupstr(word);
	return (tok);
}

t_token * token_path(const char * word) {
	t_token * tok;

	if ((tok = token_alloc(PATH)) == NULL)
		return (NULL);

	tok->u.str = dupstr(word);
	return (tok);
}

t_token * token_num(int num) {
	t_token * tok;

	if ((tok = token_alloc(NUM)) == NULL)
		return (NULL);

	tok->u.num = num;
	return (tok);
}

t_token * token_rect(int x, int y, int w, int h) {
	t_token * tok;

	if ((tok = token_alloc(RECT)) == NULL)
		return (NULL);

	tok->u.rect.x = x;
	tok->u.rect.y = y;
	tok->u.rect.w = w;
	tok->u.rect.h = h;
	return (tok);
}

// t_bool              eat_word_token(char ** word) {
//     if (word == NULL || g_li_token == NULL)
//         return (FALSE);

// }
