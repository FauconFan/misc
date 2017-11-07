#include <stdio.h>
#include "libft.h"
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int	main(void)
{
	char tmp[100];
	char *ptr;
	int i;

	/*test*/
	printf("%d\n", isalnum('d'));
	printf("%d\n", isalnum('1'));
	printf("%d\n", isalnum(5));
	printf("%d\n", isalnum(-4));
	printf("%d\n", isalnum(0));
	printf("%d\n", isalnum(128));

	printf("%d\n", isalpha('d'));
	printf("%d\n", isalpha('1'));
	printf("%d\n", isalpha(5));
	printf("%d\n", isalpha(-4));
	printf("%d\n", isalpha(0));
	printf("%d\n", isalpha(128));

	printf("%d\n", isascii('d'));
	printf("%d\n", isascii('1'));
	printf("%d\n", isascii(5));
	printf("%d\n", isascii(-4));
	printf("%d\n", isascii(0));
	printf("%d\n", isascii(128));

	printf("%d\n", isdigit('d'));
	printf("%d\n", isdigit('1'));
	printf("%d\n", isdigit(5));
	printf("%d\n", isdigit(-4));
	printf("%d\n", isdigit(0));
	printf("%d\n", isdigit(128));

	printf("%d\n", isprint('d'));
	printf("%d\n", isprint('1'));
	printf("%d\n", isprint(5));
	printf("%d\n", isprint(-4));
	printf("%d\n", isprint(0));
	printf("%d\n", isprint(128));

	printf("%d\n", atoi("42"));
	printf("%d\n", atoi("salut"));
	printf("%d\n", atoi("-42"));
	printf("%d\n", atoi("-+42"));
	printf("%d\n", atoi("+-42"));
	printf("%d\n", atoi("++42"));
	printf("%d\n", atoi("--42"));
	printf("%d\n", atoi("--42"));
	printf("%d\n", atoi("   15265"));
	printf("%d\n", atoi("15+265"));
	printf("%d\n", atoi("\t15"));

	printf("%lu\n", strlen("15"));
	printf("%lu\n", strlen("salut"));
	printf("%lu\n", strlen(""));

	ptr = strdup("salut");
	printf("%s\n", ptr);
	free(ptr);
	ptr = strdup("");
	printf("%s\n", ptr);
	free(ptr);

	strcpy(tmp, "salut");
	printf("%s\n", tmp);
	strcpy(tmp, "salut les copains");
	printf("%s\n", tmp);
	bzero(tmp, sizeof(tmp));

	strncpy(tmp, "salut", 5);
	printf("%s\n", tmp);
	bzero(tmp, sizeof(tmp));
	strncpy(tmp, "salut", 7);
	printf("%s\n", tmp);
	bzero(tmp, sizeof(tmp));
	strncpy(tmp, "salut", 3);
	printf("%s\n", tmp);
	bzero(tmp, sizeof(tmp));
	strncpy(tmp, "salut", 0);
	printf("%s\n", tmp);
	bzero(tmp, sizeof(tmp));

	strcat(tmp, "salut");
	printf("%s\n", tmp);
	strcat(tmp, " les copains");
	printf("%s\n", tmp);
	strcat(tmp, "");
	printf("%s\n", tmp);
	bzero(tmp, sizeof(tmp));

	strncat(tmp, "salut", 5);
	printf("%s\n", tmp);
	strncat(tmp, " les copains", 3);
	printf("%s\n", tmp);
	strncat(tmp, "", 5);
	printf("%s\n", tmp);
	strncat(tmp, "oui", 0);
	printf("%s\n", tmp);
	bzero(tmp, sizeof(tmp));

	strlcat(tmp, "salut", 5);
	printf("%s\n", tmp);
	strlcat(tmp, " les copains", 3);
	printf("%s\n", tmp);
	strlcat(tmp, "", 5);
	printf("%s\n", tmp);
	strlcat(tmp, "oui", 0);
	printf("%s\n", tmp);

	printf("%s\n", strchr("salut", 'c'));
	printf("%s\n", strchr("salut", 0));
	printf("%s\n", strchr("salut", 'x'));
	printf("%s\n", strchr("blabla", 'l'));
	printf("%s\n", strchr("blabla", 1425));

	printf("%s\n", strrchr("blabla", 'l'));
	printf("%s\n", strchr("salut", 0));

	printf("%s\n", strstr("salut", "lala"));
	printf("%s\n", strstr("salut", "sal"));
	printf("%s\n", strstr("salut", "salut"));
	printf("%s\n", strstr("salut", ""));
	printf("%s\n", strstr("sal", "salut"));
	printf("%s\n", strstr("salut", "Salut"));

	printf("%s\n", strnstr("salut", "salut", 5));
	printf("%s\n", strnstr("salut", "salut", 0));
	printf("%s\n", strnstr("salut", "salut", 1));
	printf("%s\n", strnstr("salut", "sal", 4));
	printf("%s\n", strnstr("salut", "sAl", 3));

	printf("%d\n", strcmp("blabla", "salut"));
	printf("%d\n", strcmp("salut", "salut"));
	printf("%d\n", strcmp("salut", "sal"));
	printf("%d\n", strcmp("Salut", "salut"));
	printf("%d\n", strcmp("sal ut", "salut"));

	printf("%d\n", strncmp("salut", "salut", 5));
	printf("%d\n", strncmp("salut", "salut", 0));
	printf("%d\n", strncmp("salut", "salut", 1));
	printf("%d\n", strncmp("salut", "sal", 4));
	printf("%d\n", strncmp("salut", "sAl", 3));

	printf("%c\n", toupper('c'));
	printf("%c\n", toupper(0));
	printf("%c\n", toupper('C'));
	printf("%c\n", toupper('1'));

	printf("%c\n", tolower('c'));
	printf("%c\n", tolower(0));
	printf("%c\n", tolower('C'));
	printf("%c\n", tolower('1'));

	ptr = malloc(10);
	memset(ptr, 'c', 10);
	i = -1;
	while (++i < 10)
		putchar(ptr[i]);
	memset(ptr, 0, 5);
	i = -1;
	while (++i < 10)
		putchar(ptr[i]);

	strcpy(ptr, "salut");
	printf("%s\n", ptr);
	bzero(ptr, 10);
	printf("%s\n", ptr);
	bzero(ptr, 10);

	memcpy(ptr, "aaa", 3);
	printf("%s\n", ptr);
	bzero(ptr, 10);
	memcpy(ptr, "aaa", 5);
	printf("%s\n", ptr);
	bzero(ptr, 10);
	memcpy(ptr, "aaa", 1);
	printf("%s\n", ptr);
	bzero(ptr, 10);
	memcpy(ptr, "aaa", 0);
	printf("%s\n", ptr);
	bzero(ptr, 10);

	memccpy(ptr, "aaa", 'a', 3);
	printf("%s\n", ptr);
	bzero(ptr, 10);
	memccpy(ptr, "aaa", 'c', 3);
	printf("%s\n", ptr);
	bzero(ptr, 10);
	memccpy(ptr, "aaa", 0, 3);
	printf("%s\n", ptr);
	bzero(ptr, 10);

	memmove(ptr, "aaa", 3);
	printf("%s\n", ptr);
	bzero(ptr, 10);
	memmove(ptr, "aaa", 5);
	printf("%s\n", ptr);
	bzero(ptr, 10);
	memmove(ptr, "aaa", 1);
	printf("%s\n", ptr);
	bzero(ptr, 10);
	memmove(ptr, "aaa", 0);
	printf("%s\n", ptr);
	bzero(ptr, 10);

	strcpy(tmp, "salut");
	printf("%s\n", memchr(tmp, 'c', 5));
	printf("%s\n", memchr(tmp, 's', 0));
	printf("%s\n", memchr(tmp, 's', 3));
	printf("%s\n", memchr(tmp, 'l', 10));
	printf("%s\n", memchr(tmp, 0, 6));

	printf("%d\n", memcmp("salut", "salut", 5));
	printf("%d\n", memcmp("salut", "salut", 0));
	printf("%d\n", memcmp("salut", "salut", 1));
	printf("%d\n", memcmp("salut", "sal", 4));
	printf("%d\n", memcmp("salut", "sAl", 3));

	free(ptr);
}
