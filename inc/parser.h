#ifndef PARSER_H
#define	PARSER_H

#define	NO_ANGLE (-1)

typedef enum    e_type_token {
	WORD,
	PATH,
	NUM,
}               t_type_token;

typedef struct  s_token {
	t_type_token type;
	union {
		long int num;
		char *   str;
	}                u;
	struct s_token * next;
}               t_token;

typedef struct	s_li_token {
	t_token		* first;
	t_token		* last;
}				t_li_token;

void    			next_parser(char * line);

void                free_li_token();
void                print_token(t_token * tok);
t_token             *token_word(const char * word);
t_token             *token_path(const char * word);
t_token             *token_num(const char * word);

t_li_token  		*li_token_alloc();
void        		li_token_free(t_li_token *li);
void        		li_token_print(t_li_token *li);
void       		 	li_token_add(t_li_token *li, t_token * tok);

t_cmd * parse_line(char * line, t_error_parser * error);

const char * get_error(t_error_parser error);

t_cmd * init_p_out(char * c, char * nf, int a, SDL_Rect rectangle, t_error_parser * error);

void free_p_out(t_cmd * cmd);


#endif // ifndef PARSER_H
