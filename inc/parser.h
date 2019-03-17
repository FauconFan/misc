#ifndef PARSER_H
#define	PARSER_H

#define	NO_ANGLE (-1)

t_cmd * parse_line(char * line, t_error_parser * error);

const char * get_error(t_error_parser error);

t_cmd * init_p_out(char * c, char * nf, int a, SDL_Rect rectangle, t_error_parser * error) ;

void free_p_out(t_cmd * cmd);


#endif // ifndef PARSER_H
