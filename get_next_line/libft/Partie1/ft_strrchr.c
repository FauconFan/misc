#include <string.h>

static char	*ft_strrchr_recu(const char *s, int c, const char *res_actu)
{
	if (s == 0 || *s == 0)
		return ((c == '\0') ? (char *)s : (char *)res_actu);
	if (*s == c)
		return (ft_strrchr_recu(s + 1, c, s));
	return (ft_strrchr_recu(s + 1, c, res_actu));
}

char		*ft_strrchr(const char *s, int c)
{
	return (ft_strrchr_recu(s, c, NULL));
}