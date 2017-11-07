#include <stdio.h>
#include "libft.h"
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	char tmp[100];
	char *ptr;
	int i;

	/*test*/
	printf("%d\n", ft_isalnum('d'));
	printf("%d\n", ft_isalnum('1'));
	printf("%d\n", ft_isalnum(5));
	printf("%d\n", ft_isalnum(-4));
	printf("%d\n", ft_isalnum(0));
	printf("%d\n", ft_isalnum(128));

	printf("%d\n", ft_isalpha('d'));
	printf("%d\n", ft_isalpha('1'));
	printf("%d\n", ft_isalpha(5));
	printf("%d\n", ft_isalpha(-4));
	printf("%d\n", ft_isalpha(0));
	printf("%d\n", ft_isalpha(128));

	printf("%d\n", ft_isascii('d'));
	printf("%d\n", ft_isascii('1'));
	printf("%d\n", ft_isascii(5));
	printf("%d\n", ft_isascii(-4));
	printf("%d\n", ft_isascii(0));
	printf("%d\n", ft_isascii(128));

	printf("%d\n", ft_isdigit('d'));
	printf("%d\n", ft_isdigit('1'));
	printf("%d\n", ft_isdigit(5));
	printf("%d\n", ft_isdigit(-4));
	printf("%d\n", ft_isdigit(0));
	printf("%d\n", ft_isdigit(128));

	printf("%d\n", ft_isprint('d'));
	printf("%d\n", ft_isprint('1'));
	printf("%d\n", ft_isprint(5));
	printf("%d\n", ft_isprint(-4));
	printf("%d\n", ft_isprint(0));
	printf("%d\n", ft_isprint(128));

	printf("%d\n", ft_atoi("42"));
	printf("%d\n", ft_atoi("salut"));
	printf("%d\n", ft_atoi("-42"));
	printf("%d\n", ft_atoi("-+42"));
	printf("%d\n", ft_atoi("+-42"));
	printf("%d\n", ft_atoi("++42"));
	printf("%d\n", ft_atoi("--42"));
	printf("%d\n", ft_atoi("--42"));
	printf("%d\n", ft_atoi("   15265"));
	printf("%d\n", ft_atoi("15+265"));
	printf("%d\n", ft_atoi("\t15"));

	printf("%lu\n", ft_strlen("15"));
	printf("%lu\n", ft_strlen("salut"));
	printf("%lu\n", ft_strlen(""));

	ptr = ft_strdup("salut");
	printf("%s\n", ptr);
	free(ptr);
	ptr = ft_strdup("");
	printf("%s\n", ptr);
	free(ptr);

	ft_strcpy(tmp, "salut");
	printf("%s\n", tmp);
	ft_strcpy(tmp, "salut les copains");
	printf("%s\n", tmp);
	bzero(tmp, sizeof(tmp));

	ft_strncpy(tmp, "salut", 5);
	printf("%s\n", tmp);
	bzero(tmp, sizeof(tmp));
	ft_strncpy(tmp, "salut", 7);
	printf("%s\n", tmp);
	bzero(tmp, sizeof(tmp));
	ft_strncpy(tmp, "salut", 3);
	printf("%s\n", tmp);
	bzero(tmp, sizeof(tmp));
	ft_strncpy(tmp, "salut", 0);
	printf("%s\n", tmp);
	bzero(tmp, sizeof(tmp));

	ft_strcat(tmp, "salut");
	printf("%s\n", tmp);
	ft_strcat(tmp, " les copains");
	printf("%s\n", tmp);
	ft_strcat(tmp, "");
	printf("%s\n", tmp);
	bzero(tmp, sizeof(tmp));

	ft_strncat(tmp, "salut", 5);
	printf("%s\n", tmp);
	ft_strncat(tmp, " les copains", 3);
	printf("%s\n", tmp);
	ft_strncat(tmp, "", 5);
	printf("%s\n", tmp);
	ft_strncat(tmp, "oui", 0);
	printf("%s\n", tmp);
	bzero(tmp, sizeof(tmp));

	ft_strlcat(tmp, "salut", 5);
	printf("%s\n", tmp);
	ft_strlcat(tmp, " les copains", 3);
	printf("%s\n", tmp);
	ft_strlcat(tmp, "", 5);
	printf("%s\n", tmp);
	ft_strlcat(tmp, "oui", 0);
	printf("%s\n", tmp);

	printf("%s\n", ft_strchr("salut", 'c'));
	printf("%s\n", ft_strchr("salut", 0));
	printf("%s\n", ft_strchr("salut", 'x'));
	printf("%s\n", ft_strchr("blabla", 'l'));
	printf("%s\n", ft_strchr("blabla", 1425));

	printf("%s\n", ft_strrchr("blabla", 'l'));
	printf("%s\n", ft_strchr("salut", 0));

	printf("%s\n", ft_strstr("salut", "lala"));
	printf("%s\n", ft_strstr("salut", "sal"));
	printf("%s\n", ft_strstr("salut", "salut"));
	printf("%s\n", ft_strstr("salut", ""));
	printf("%s\n", ft_strstr("sal", "salut"));
	printf("%s\n", ft_strstr("salut", "Salut"));

	printf("%s\n", ft_strnstr("salut", "salut", 5));
	printf("%s\n", ft_strnstr("salut", "salut", 0));
	printf("%s\n", ft_strnstr("salut", "salut", 1));
	printf("%s\n", ft_strnstr("salut", "sal", 4));
	printf("%s\n", ft_strnstr("salut", "sAl", 3));

	printf("%d\n", ft_strcmp("blabla", "salut"));
	printf("%d\n", ft_strcmp("salut", "salut"));
	printf("%d\n", ft_strcmp("salut", "sal"));
	printf("%d\n", ft_strcmp("Salut", "salut"));
	printf("%d\n", ft_strcmp("sal ut", "salut"));

	printf("%d\n", ft_strncmp("salut", "salut", 5));
	printf("%d\n", ft_strncmp("salut", "salut", 0));
	printf("%d\n", ft_strncmp("salut", "salut", 1));
	printf("%d\n", ft_strncmp("salut", "sal", 4));
	printf("%d\n", ft_strncmp("salut", "sAl", 3));

	printf("%c\n", ft_toupper('c'));
	printf("%c\n", ft_toupper(0));
	printf("%c\n", ft_toupper('C'));
	printf("%c\n", ft_toupper('1'));

	printf("%c\n", ft_tolower('c'));
	printf("%c\n", ft_tolower(0));
	printf("%c\n", ft_tolower('C'));
	printf("%c\n", ft_tolower('1'));

	ptr = malloc(10);
	ft_memset(ptr, 'c', 10);
	i = -1;
	while (++i < 10)
		putchar(ptr[i]);
	ft_memset(ptr, 0, 5);
	i = -1;
	while (++i < 10)
		putchar(ptr[i]);

	strcpy(ptr, "salut");
	printf("%s\n", ptr);
	ft_bzero(ptr, sizeof(ptr));
	printf("%s\n", ptr);
	bzero(ptr, 10);

	ft_memcpy(ptr, "aaa", 3);
	printf("%s\n", ptr);
	ft_bzero(ptr, sizeof(ptr));
	ft_memcpy(ptr, "aaa", 5);
	printf("%s\n", ptr);
	ft_bzero(ptr, sizeof(ptr));
	ft_memcpy(ptr, "aaa", 1);
	printf("%s\n", ptr);
	ft_bzero(ptr, sizeof(ptr));
	ft_memcpy(ptr, "aaa", 0);
	printf("%s\n", ptr);
	ft_bzero(ptr, sizeof(ptr));

	ft_memccpy(ptr, "aaa", 'a', 3);
	printf("%s\n", ptr);
	ft_bzero(ptr, sizeof(ptr));
	ft_memccpy(ptr, "aaa", 'c', 3);
	printf("%s\n", ptr);
	ft_bzero(ptr, sizeof(ptr));
	ft_memccpy(ptr, "aaa", 0, 3);
	printf("%s\n", ptr);
	ft_bzero(ptr, sizeof(ptr));

	ft_memmove(ptr, "aaa", 3);
	printf("%s\n", ptr);
	ft_bzero(ptr, sizeof(ptr));
	ft_memmove(ptr, "aaa", 5);
	printf("%s\n", ptr);
	ft_bzero(ptr, sizeof(ptr));
	ft_memmove(ptr, "aaa", 1);
	printf("%s\n", ptr);
	ft_bzero(ptr, sizeof(ptr));
	ft_memmove(ptr, "aaa", 0);
	printf("%s\n", ptr);
	ft_bzero(ptr, sizeof(ptr));

	strcpy(tmp, "salut");
	printf("%s\n", ft_memchr(tmp, 'c', 5));
	printf("%s\n", ft_memchr(tmp, 's', 0));
	printf("%s\n", ft_memchr(tmp, 's', 3));
	printf("%s\n", ft_memchr(tmp, 'l', 10));
	printf("%s\n", ft_memchr(tmp, 0, 6));

	printf("%d\n", ft_memcmp("salut", "salut", 5));
	printf("%d\n", ft_memcmp("salut", "salut", 0));
	printf("%d\n", ft_memcmp("salut", "salut", 1));
	printf("%d\n", ft_memcmp("salut", "sal", 4));
	printf("%d\n", ft_memcmp("salut", "sAl", 3));
	
	free(ptr);
}
