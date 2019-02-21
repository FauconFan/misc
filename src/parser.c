#include "cimp.h"

t_parser_config g_command_list[] = {
	{"help",      0, 0},
	{"open",      1, 0},
	{"close",     1, 0},
	{"list",      0, 0},
	{"sym_verti", 0, 0},
	{"sym_horti", 0, 0},
	{"rotate",    0, 1},
};

size_t g_command_list_size = sizeof(g_command_list) / sizeof(*g_command_list);

char * g_error_parser_strings [] = {
	"Il y a trop d'arguments pour cette commande",
	"Il y a trop peu d'arguments pour cette commande",
	"Le nom de la commande n'est pas connu",
	"Le malloc a echoue",
};

/*Une fonction qui cree un pointeur vers un t_parser_config avec les champs nm pour name,  hn pour has_name et ha pour has_angle
 * t_parser_config * init_p_config (char * n, short hn, short ha){
 * t_parser_config * res = malloc(sizeof(t_parser_config));
 * if(res == NULL){
 *  perror("malloc");
 *  exit(1);
 * }
 *
 * res->name = n;
 * res->has_name = hn;
 * res->has_angle = hr;
 * return res;
 * }
 */


/*Une fonction qui cree un pointeur vers un t_parser_out avec les champs c pour cmd, nf pour name_file et a pour angle*/
t_parser_out * init_p_out(char * c, char * nf, int a, t_error_parser * error) {
	t_parser_out * res = malloc(sizeof(t_parser_out));

	if (res == NULL) {
		*error = MALLOC_EST_LE_MAILLON_FAIBLE;
		return NULL;
	}

	res->cmd       = dupstr(c);
	res->name_file = dupstr(nf);
	res->angle     = a;
	return res;
}

/*Une fonction qui libere la memoire allouee au t_parser_out cmd*/
void free_p_out(t_parser_out * cmd) {
	free(cmd->cmd);
	free(cmd->name_file);
	free(cmd);
}

/*Renvoie le t_parser_config correspondant a la commande cmd et NULL si elle n'existe pas*/
t_parser_config * get_cmd(char * cmd) {
	for (int i = 0; i < (int) g_command_list_size; i++) {
		if (strcmp(cmd, g_command_list[i].name) == 0) {
			return g_command_list + i;
		}
	}
	return NULL;
}

/*Renvoie le nombre d'arguments correspondant a la commande cmd ou -1 si elle vaut NULL*/
int nb_args(t_parser_config * cmd) {
	int res = 0;

	if (cmd == NULL) {
		return -1;
	}

	if (cmd->has_name) res++;
	if (cmd->has_angle) res++;
	return res;
}

/*Renvoie l'explication de l'erreur correspondant a error*/
char * get_error(t_error_parser error) {
	return g_error_parser_strings[error];
}

/*Une fonction qui renvoie un pointeur vers un t_parser_out correspondant a la commande correspondant a line si la commande existe;
 * si elle n'existe pas ou que le nombre d'arguments ne correspond pas on met a jour le champs error et on renvoie NULL*/
t_parser_out * parse_line(char * line, t_error_parser * error) {
	char * token = strtok_r(line, " ", &line);
	t_parser_config * commande = get_cmd(token);
	int args = nb_args(commande);

	if (commande == NULL) {
		*error = UNKNOW_NAME;
		return NULL;
	}

	t_parser_out * res = init_p_out(token, NULL, NO_ANGLE, error);
	if (res == NULL) {
		return NULL;
	}

	while ((token = strtok_r(line, " ", &line)) != NULL) {
		if (commande->has_name && res->name_file == NULL) {
			res->name_file = token;
		}
		else if (commande->has_angle && res->angle == NO_ANGLE) {
			res->angle = atoi(token);
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

	return res;
} /* parse_line */
