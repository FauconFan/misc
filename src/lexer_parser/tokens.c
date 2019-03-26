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
			printf("RECT(%d %d %d %d)\n", tok->u.rect.x, tok->u.rect.y, tok->u.rect.w,
			  tok->u.rect.h);
			break;
		case POINT:
			printf("POINT(%d %d)\n", tok->u.point.x, tok->u.point.y);
			break;
		case COLOR:
			printf("COLOR(%d %d %d)\n", tok->u.color.r, tok->u.color.g, tok->u.color.b);
			break;
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

t_token * token_point(int x, int y) {
	t_token * tok;

	if ((tok = token_alloc(POINT)) == NULL)
		return (NULL);

	tok->u.point.x = x;
	tok->u.point.y = y;
	return (tok);
}

t_token * token_color(const char * word) {
	t_token * tok;
	uint32_t col;

	if (strlen(word) != 8 || strncmp(word, "0x", 2) != 0)
		return (NULL);

	if ((tok = token_alloc(COLOR)) == NULL)
		return (NULL);

	col = strtol(word + 2, NULL, 16);
	tok->u.color.b = col % 256;
	col = col >> 8;
	tok->u.color.g = col % 256;
	col = col >> 8;
	tok->u.color.r = col % 256;
	// col >> 8;
	return (tok);
}
