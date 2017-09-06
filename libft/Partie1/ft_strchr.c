#include <string.h>

 char	*ft_strchr(const char *s, int c)
 {
 	if (s == 0 || *s == 0)
 	{
 		if (*s == c)
 			return ((char *)s);
 		return (NULL);
 	}
 	if (*s == c)
 		return ((char *)s);
 	return (ft_strchr(s + 1, c));
 }