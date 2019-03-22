#ifndef PARSER_H
#define	PARSER_H

#define	NO_ANGLE (-1)

typedef enum    e_type_token {
	WORD,
	PATH,
	NUM,
	RECT,
}               t_type_token;

typedef struct  s_token {
	t_type_token type;
	union {
		int64_t num;
		char *  str;
		SDL_Rect rect;
	}                u;
	struct s_token * next;
}               t_token;

typedef struct  s_li_token {
	t_token * first;
	t_token * last;
	t_token * actu;
	t_bool ok;
}               t_li_token;

t_cmd * next_parser(char * line);
void cmd_free(t_cmd * cmd);

void free_li_token();
void print_token(t_token * tok);
t_token * token_word(const char * word);
t_token * token_path(const char * word);
t_token * token_num(int num);
t_token * token_rect(int x, int y, int w, int h);

t_li_token * li_token_alloc();
void li_token_free(t_li_token * li);
t_bool li_token_empty(t_li_token * li);
void li_token_print(t_li_token * li);
void li_token_add(t_li_token * li, t_token * tok);
t_token * li_token_get_next(t_li_token * li);

t_cmd * parse_line(char * line, t_error_parser * error);

const char * get_error(t_error_parser error);


#endif // ifndef PARSER_H
