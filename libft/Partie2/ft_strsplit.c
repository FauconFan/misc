#include <stdlib.h>

static char		*ignorechr(char *s, char c)
{
	while (*s != 0 && *s == c)
		s++;
	return (s);
}

static char		*ignoreword(char *s, char c)
{
	while (*s != 0 && *s != c)
		s++;
	return (s);
}

static int		len_words(char *s, char c)
{
	int		res;

	res = 0;
	s = ignorechr(s, c);
	while (*s)
	{
		s = ignoreword(s, c);
		s = ignorechr(s, c);
		res++;
	}
	return (res);
}

static int		len_word(char *s, char c)
{
	int		length;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	return (length);
}

char			**ft_strsplit(char const *s, char c)
{
	int 	length_tot;
	int 	index[2];
	char 	*tmp;
	char 	**res;
	int 	length_word;

	tmp = (char *)s;
	length_tot = len_words(tmp, c);
	tmp = ignorechr(tmp, c);
	index[0] = 0;
	if ((res = (char **)malloc(sizeof(char *) * (length_tot + 1))) == NULL)
		return (NULL);
	while (index[0] < length_tot)
	{
		index[1] = 0;
		length_word = len_word(tmp, c);
		if ((res[index[0]] = (char *)malloc(sizeof(char) * (length_word + 1))) == NULL)
			return (NULL);
		while (index[1] < length_word)
			res[index[0]][index[1]++] = *(tmp++);
		res[index[0]][index[1]] = 0;
		index[0]++;
		tmp = ignorechr(tmp, c);
	}
	res[index[0]] = 0;
	return (res);
}