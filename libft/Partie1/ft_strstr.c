#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		index;

	index = 0;
	if (haystack == 0 || *haystack == 0)
		return (NULL);
	if (needle == 0 || *needle == 0)
		return ((char *)haystack);
	if (*haystack == *needle)
	{
		while (haystack[index] == needle[index] && needle[index])
			index++;
		if (needle[index] == 0)
			return ((char *)haystack);
	}
	return (ft_strstr(haystack + 1, needle));
}