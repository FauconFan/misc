#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;

	index = 0;
	if (len == 0)
		return (NULL);
	if (haystack == 0 || *haystack == 0)
		return (NULL);
	if (needle == 0 || *needle == 0)
		return ((char *)haystack);
	if (*haystack == *needle)
	{
		while (haystack[index] == needle[index] && needle[index] && index != len)
			index++;
		if (needle[index] == 0)
			return ((char *)haystack);
	}
	return (ft_strnstr(haystack + 1, needle, len - 1));
}