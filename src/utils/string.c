#include "atpt.h"

char			*replace_in_string(char *format, char car, char *by)
{
	char	*res;
	char	*ptr_res;
	size_t	l;
	size_t	s;

	l = -1;
	s = 0;
	while (format[++l])
	{
		if (format[l] == car)
			++s;
	}
	l += s * (strlen(by) - 1);
	if ((res = (char *)malloc(sizeof(char) * (l + 1))) == NULL)
		return (NULL);
	memset(res, 0, l + 1);
	ptr_res = res;
	l = -1;
	while (format[++l])
	{
		if (format[l] == car)
		{
			s = 0;
			while (by[s])
				*(ptr_res++) = by[s++];
		}
		else
			*(ptr_res++) = format[l];
	}
	return (res);
}
