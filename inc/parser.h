#ifndef PARSER_H
#define	PARSER_H

#define	NO_ANGLE -1


typedef struct      s_parser_config {
	char * name;
	short  has_name;
	short  has_angle;
}                   t_parser_config;

extern t_parser_config g_config[];
extern size_t g_config_size;

typedef struct      s_parser_out {
	char * cmd;
	char * name_file;
	int    angle;
}                   t_parser_out;


typedef enum e_error_parser {
	TOO_MUCH_ARGS = 0,
	NOT_ENOUGH_ARGS,
	UNKNOW_NAME,
	MALLOC_EST_LE_MAILLON_FAIBLE,
    INVALID_ARGUMENT,
}            t_error_parser;

extern char * g_error_parser_strings [];

t_parser_out * parse_line(char * line, t_error_parser * error);

char * get_error(t_error_parser error);

void free_p_out(t_parser_out * cmd);


#endif // ifndef PARSER_H
