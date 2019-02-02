
#include "cimp.h"

/**
 * strjoin renvoie la concaténation de deux chaînes de charactères
 * @param  s1
 * @param  s2
 * @return    un pointeur allouée
 */
char		*strjoin(const char *s1, const char *s2)
{
	size_t			len1;
	size_t			len2;
	size_t			len_tot;
	char			*res;

	len_tot = strlen(s1) + strlen(s2);
	res = (char *)malloc(sizeof(char) * (len_tot + 1));
	if (res == NULL)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (s1[len1])
	{
		res[len1] = s1[len1];
		len1++;
	}
	while (s2[len2])
	{
		res[len1 + len2] = s2[len2];
		len2++;
	}
	res[len1 + len2] = 0;
	return (res);
}

/**
 * strjoin_c renvoie la concaténation de la première chaîne de charactères,
 * d'un charactère dit de connexion, et d'une seconde chaîne de charactères.
 * @param  dir    la première chaîne de charactères.
 * @param  file   la seconde chaîne de charactères.
 * @param  joiner le charactère dit de connexion.
 * @return        un pointerur allouée
 */
char		*strjoin_c(const char *dir, const char *file, const char joiner)
{
	size_t		len1;
	size_t		len2;
	size_t		len_tot;
	char		*res;

	len1 = strlen(dir);
	len_tot = len1 + strlen(file) + 1;
	res = (char *)malloc(sizeof(char) * (len_tot + 1));
	if (res == NULL)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (dir[len1])
	{
		res[len1] = dir[len1];
		len1++;
	}
	res[len1] = joiner;
	len1++;
	while (file[len2])
	{
		res[len1 + len2] = file[len2];
		len2++;
	}
	res[len1 + len2] = 0;
	return (res);
}
