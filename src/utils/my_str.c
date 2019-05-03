#include "irc_udp.h"

char * strnew(size_t size) {
	char * s;
	size_t index;

	index = 0;
	if ((s = (char *) malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);

	while (index < size) {
		s[index] = 0;
		index++;
	}
	s[index] = 0;
	return (s);
}

char * strjoin(const char * s1, const char * s2) {
	unsigned int len1;
	unsigned int len2;
	unsigned int len_tot;
	char * res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);

	len_tot = strlen(s1) + strlen(s2);
	if ((res = (char *) malloc(sizeof(char) * (len_tot + 1))) == NULL)
		return (NULL);

	len1 = 0;
	len2 = 0;
	while (s1[len1]) {
		res[len1] = s1[len1];
		len1++;
	}
	while (s2[len2]) {
		res[len1 + len2] = s2[len2];
		len2++;
	}
	res[len1 + len2] = 0;
	return (res);
}

void strreplace(char ** str, char * pattern, char * with) {
	char * res;
	char * tmp[2];
	size_t len_res;
	size_t index;
	size_t len_pattern;
	size_t len_with;

	if (str == NULL || *str == NULL || pattern == NULL || with == NULL)
		return;

	len_pattern = strlen(pattern);
	len_with    = strlen(with);
	len_res     = 0;
	tmp[0]      = *str;
	while ((tmp[1] = strstr(tmp[0], pattern)) != NULL) {
		len_res += tmp[1] - tmp[0];
		len_res += len_with;
		tmp[0]   = tmp[1] + len_pattern;
	}
	len_res += strlen(tmp[0]);
	res      = strnew(len_res);
	index    = 0;
	tmp[0]   = *str;
	while ((tmp[1] = strstr(tmp[0], pattern)) != NULL) {
		strncpy(res + index, tmp[0], tmp[1] - tmp[0]);
		index += tmp[1] - tmp[0];
		strncpy(res + index, with, len_with);
		index += len_with;
		tmp[0] = tmp[1] + len_pattern;
	}
	strncpy(res + index, tmp[0], strlen(tmp[0]));
	free(*str);
	*str = res;
} /* strreplace */
