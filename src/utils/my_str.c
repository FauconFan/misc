#include "irc_udp.h"

char	*strnew(size_t size)
{
	char	*s;
	size_t	index;

	index = 0;
	if ((s = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
        return (NULL);
	while (index < size)
	{
		s[index] = 0;
		index++;
	}
	s[index] = 0;
	return (s);
}

char	*strjoin(const char *s1, const char *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	len_tot;
	char			*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_tot = strlen(s1) + strlen(s2);
	if ((res = (char *)malloc(sizeof(char) * (len_tot + 1))) == NULL)
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

// static char		*split_ignorechr(char *s, char c)
// {
// 	while (*s != 0 && *s == c)
// 		s++;
// 	return (s);
// }

// static char		*split_ignoreword(char *s, char c)
// {
// 	while (*s != 0 && *s != c)
// 		s++;
// 	return (s);
// }

// static int		split_len_words(char *s, char c, int *num)
// {
// 	int		res;

// 	*num = 0;
// 	res = 0;
// 	s = split_ignorechr(s, c);
// 	while (*s)
// 	{
// 		s = split_ignoreword(s, c);
// 		s = split_ignorechr(s, c);
// 		res++;
// 	}
// 	return (res);
// }

// static int		split_len_word(char *s, char c, int *num)
// {
// 	int		length;

// 	*num = 0;
// 	length = 0;
// 	while (s[length] && s[length] != c)
// 		length++;
// 	return (length);
// }

// char			**strtab_strsplit(char const *s, char c)
// {
// 	int		length_tot;
// 	int		length_word;
// 	int		index[2];
// 	char	*tmp;
// 	char	**res;

// 	if (s == 0)
// 		return (NULL);
// 	length_tot = split_len_words((char *)s, c, index);
// 	tmp = split_ignorechr((char *)s, c);
// 	if ((res = (char **)malloc(sizeof(char *) * (length_tot + 1))) == NULL)
// 		return (NULL);
// 	while (index[0] < length_tot)
// 	{
// 		length_word = split_len_word(tmp, c, index + 1);
// 		if ((res[index[0]] = (char *)malloc(sizeof(char) * (length_word + 1))) == NULL)
// 			return (NULL);
// 		while (index[1] < length_word)
// 			res[index[0]][index[1]++] = *(tmp++);
// 		res[index[0]++][index[1]] = 0;
// 		tmp = split_ignorechr(tmp, c);
// 	}
// 	res[index[0]] = 0;
// 	return (res);
// }