#include "cimp.h"

/**
 * Prend un buffer et sa taille en argument (sous forme de pointeurs)
 * et realloue un espace 2 fois plus gros, libère la mémoire du buffer et le remplace
 * par un buffer 2 fois plus gros
 * @param  str_ptr      pointeur sur le buffer
 * @param  size_max_ptr pointeur vers la taille du buffer
 * @return              un booléen qui indique si ça s'est bien passé
 */
static int      extend_buffer(char ** str_ptr, size_t * size_max_ptr) {
	char * next_buffer;

	next_buffer = malloc(*size_max_ptr * 2);
	if (next_buffer == NULL)
		return (1);

	memcpy(next_buffer, *str_ptr, *size_max_ptr);
	memset(next_buffer + *size_max_ptr, 0, *size_max_ptr);
	free(*str_ptr);
	*str_ptr       = next_buffer;
	*size_max_ptr *= 2;
	return (0);
}

/**
 * cimp_readline demande une entrée à l'utilisateur et renvoie une chaîne
 * de caractères allouée contenant l'entrée donnée par l'utilisateur.
 * @return  un pointeur vers la chaîne allouée.
 */
char * cimp_readline(void) {
	char * res;
	size_t len;
	size_t size_max;
	int ret;

	len      = 0;
	size_max = 256;
	res      = malloc(size_max);
	if (res == NULL)
		return (NULL);

	memset(res, 0, size_max);
	write(1, CIMP_PROMPT, strlen(CIMP_PROMPT));
	while ((ret = read(0, res + len, 1)) > 0) {
		if (res[len] == '\n') {
			res[len] = '\0';
			break;
		}
		len++;
		if (len == size_max) {
			if (extend_buffer(&res, &size_max)) {
				free(res);
				return (NULL);
			}
		}
	}
	if (ret < 0) {
		free(res);
		return (NULL);
	}
	return (res);
} /* cimp_readline */
