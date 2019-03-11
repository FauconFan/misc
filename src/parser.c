#include "cimp.h"

/*Une fonction qui cree un pointeur vers un t_parser_out avec les champs c pour cmd, nf pour name_file et a pour angle*/
t_parser_out * init_p_out(char * c, char * nf, int a, SDL_Rect rectangle, t_error_parser * error) {
	t_parser_out * res = malloc(sizeof(t_parser_out));

	if (res == NULL) {
		*error = MALLOC_EST_LE_MAILLON_FAIBLE;
		return NULL;
	}

	res->cmd       = dupstr(c);
	res->name_file = dupstr(nf);
	res->angle     = a;
	res->rect      = rectangle;
	return res;
}

/*Une fonction qui libere la memoire allouee au t_parser_out cmd*/
void free_p_out(t_parser_out * cmd) {
	free(cmd->cmd);
	free(cmd->name_file);
	free(cmd);
}

/*Renvoie le t_parser_config correspondant a la commande cmd et NULL si elle n'existe pas*/
const t_parser_config * get_cmd(char * cmd) {
	for (int i = 0; i < (int) g_command_list_size; i++) {
		if (strcmp(cmd, g_command_list[i].name) == 0) {
			return g_command_list + i;
		}
	}
	return NULL;
}

/*Renvoie le nombre d'arguments correspondant a la commande cmd ou -1 si elle vaut NULL*/
int nb_args(const t_parser_config * cmd) {
	int res = 0;

	if (cmd == NULL) {
		return -1;
	}

	if (cmd->has_name) res++;
	if (cmd->has_angle) res++;
	if (cmd->has_rect) res += 4;
	return res;
}

/*Renvoie l'explication de l'erreur correspondant a error*/
const char * get_error(t_error_parser error) {
	return g_error_parser_strings[error];
}

/*Une fonction qui renvoie un pointeur vers un t_parser_out correspondant a la commande correspondant a line si la commande existe;
 * si elle n'existe pas ou que le nombre d'arguments ne correspond pas on met a jour le champs error et on renvoie NULL
 * si la ligne est vide on renvoit NULL*/
t_parser_out * parse_line(char * line, t_error_parser * error) {
	if ((*line) == 0) {
		*error = NO_LINE;
		return NULL;
	}

	SDL_Rect rectangle;
	char * token = strtok_r(line, " ", &line);
	const t_parser_config * commande = get_cmd(token);
	int args = nb_args(commande);
	char * tmp;
	int rc;

	rectangle.x = -1;
	rectangle.y = -1;
	rectangle.w = -1;
	rectangle.h = -1;

	if (commande == NULL) {
		*error = UNKNOW_NAME;
		return NULL;
	}

	t_parser_out * res = init_p_out(token, NULL, NO_ANGLE, rectangle, error);
	if (res == NULL) {
		return NULL;
	}

	while ((token = strtok_r(line, " ", &line)) != NULL) {
		if (commande->has_name && res->name_file == NULL) {
			res->name_file = dupstr(token);
		}
		else if (commande->has_angle && res->angle == NO_ANGLE) {
			errno = 0;
			rc    = strtol(token, &tmp, 10);
			if (errno == EINVAL || errno == ERANGE || tmp == token) {
				*error = INVALID_ARGUMENT;
				return NULL;
			}

			res->angle = rc;
		}
		else if (commande->has_rect &&
		  (res->rect.x == -1 || res->rect.y == -1 || res->rect.h == -1 || res->rect.w == -1 ) )
		{
			errno = 0;
			rc    = strtol(token, &tmp, 10);
			if (errno == EINVAL || errno == ERANGE || tmp == token) {
				*error = INVALID_ARGUMENT;
				return NULL;
			}
			if (res->rect.x == -1) {
				res->rect.x = rc;
			}
			else if (res->rect.y == -1) {
				res->rect.y = rc;
			}
			else if (res->rect.w == -1) {
				res->rect.w = rc;
			}
			else if (res->rect.h == -1) {
				res->rect.h = rc;
			}
		}

		args--;
	}

	if (args < 0) {
		*error = TOO_MUCH_ARGS;
		free_p_out(res);
		return NULL;
	}

	if (args > 0) {
		*error = NOT_ENOUGH_ARGS;
		free_p_out(res);
		return NULL;
	}

	/**
	 * if(commande->has_rect && (rectangle.x ==-1 || rectangle.y == -1 || rectangle.h == -1  || rectangle.w ==-1 )){
	 * error = INVALID_RECT;
	 *  free_p_out(res);
	 *  return NULL;
	 * }
	 **/
	return res;
} /* parse_line */
