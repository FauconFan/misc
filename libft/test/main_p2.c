#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void	my_toupper(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c += 'A' - 'a';
}

void	my_toupper_if(unsigned int i, char *c)
{
	if (i == 9)
		*c += 'A' - 'a';
}

char	my_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c -= 'A' - 'a';
	return (c);
}

char	my_tolower_if(unsigned int i, char c)
{
	if (i == 9)
		c -= 'A' - 'a';
	return (c);
}

void	print_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		printf("%s\n", tab[i]);
}

void	free_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	print_list(t_list *list)
{
	printf("list :\n");
	while(list)
	{
		printf("%s\n", (char*)list->content);
		list = list->next;
	}
}

void	testlist(void)
{
	t_list *list;
	char maillon1[] = "maillon 1";
	char maillon2[] = "maillon 2";
	char maillon3[] = "maillon 3";

	list = NULL;
	printf("test lstnew :\n");
	list = ft_lstnew(maillon1, sizeof(maillon1));
	print_list(list);
	printf("Size of 10 : %lu\n", list->content_size);
	printf("test lstadd :\n");
	ft_lstadd(&list, ft_lstnew(maillon2, sizeof(maillon2)));
	ft_lstadd(&list, ft_lstnew(maillon3, sizeof(maillon3)));
	print_list(list);
	printf("test lstdelone :\n");
	
}

int	main(void)
{
	char *ptr;
	char *ptr2;
	int i;
	char **tab;

	ptr = ft_memalloc(10);
	i = -1;
	printf("{");
	while (++i < 10)
		printf("%c", ptr[i]);
	printf("}\n");
	free(ptr);

	ptr = (char*)malloc(10);
	strcpy(ptr, "test memdel");
	printf("%s\n", ptr);
	ft_memdel((void*)&ptr);
	printf("%s\n", ptr);
	ft_memdel((void*)&ptr);
	printf("%s\n", ptr);
	free(ptr);

	ptr = ft_strnew(10);
	i = -1;
	printf("{");
	while (++i < 10)
		printf("%c", ptr[i]);
	printf("}\n");
	free(ptr);

	ptr = (char*)malloc(10);
	strcpy(ptr, "test strdel");
	printf("%s\n", ptr);
	ft_strdel((void*)&ptr);
	printf("%s\n", ptr);
	ft_strdel((void*)&ptr);
	printf("%s\n", ptr);
	free(ptr);

	ptr = (char*)malloc(10);
	strcpy(ptr, "test strclr");
	printf("{%s}\n", ptr);
	ft_strclr(ptr);
	printf("{%s}\n", ptr);
	free(ptr);

	ptr = (char*)malloc(50);
	strcpy(ptr, "chaine en mettre en maj");
	printf("{%s}\n", ptr);
	ft_striter(ptr, &my_toupper);
	printf("{%s}\n", ptr);

	bzero(ptr, 50);
	strcpy(ptr, "en maj : a");
	printf("{%s}\n", ptr);
	ft_striteri(ptr, &my_toupper_if);
	printf("{%s}\n", ptr);

	bzero(ptr, 50);
	strcpy(ptr, "Attention a copier le dernier \\0");
	printf("{%s}\n", ptr);
	ptr2 = ft_strmap(ptr, &my_tolower);
	printf("{%s}\n", ptr2);
	free(ptr2);

	bzero(ptr, 50);
	strcpy(ptr, "apply TO LOWER");
	printf("{%s}\n", ptr);
	ptr2 = ft_strmap(ptr, &my_tolower);
	printf("{%s}\n", ptr2);
	free(ptr2);

	bzero(ptr, 50);
	strcpy(ptr, "en min : A");
	printf("{%s}\n", ptr);
	ptr2 = ft_strmapi(ptr, &my_tolower_if);
	printf("{%s}\n", ptr2);
	free(ptr2);

	printf("deux chaines equivalentes : %d\n", ft_strequ("salut", "salut"));
	printf("deux chaines differentes : %d\n", ft_strequ("salut", "sal"));
	printf("deux chaines vides : %d\n", ft_strequ("", ""));

	printf("deux chaines id : %d\n", ft_strnequ("salut", "salut", 1));
	printf("deux chaines diff mais n < : %d\n", ft_strnequ("salut", "salUT", 3));
	printf("deux chaines diff : %d\n", ft_strnequ("salut", "salUT", 4));

	bzero(ptr, 50);
	strcpy(ptr, "test strsub");
	printf("{%s}\n", ptr);
	ptr2 = ft_strsub(ptr, 5, 6);
	printf("{%s}\n", ptr2);
	free(ptr2);

	bzero(ptr, 50);
	strcpy(ptr, "test strsub");
	printf("{%s}\n", ptr);
	ptr2 = ft_strsub(ptr, 5, 0);
	printf("{%s}\n", ptr2);
	free(ptr2);

	bzero(ptr, 50);
	strcpy(ptr, "test strjoin");
	printf("{%s}\n", ptr);
	ptr2 = ft_strjoin(ptr, " fonctionnel");
	printf("{%s}\n", ptr2);
	free(ptr2);

	bzero(ptr, 50);
	strcpy(ptr, "   test strtrim\n\t");
	printf("{%s}\n", ptr);
	ptr2 = ft_strtrim(ptr);
	printf("{%s}\n", ptr2);
	free(ptr2);

	bzero(ptr, 50);
	strcpy(ptr, "test strtrim sans espace");
	printf("{%s}\n", ptr);
	ptr2 = ft_strtrim(ptr);
	printf("{%s}\n", ptr2);
	free(ptr2);

	bzero(ptr, 50);
	strcpy(ptr, "/test/strsplit////bla/bla/  //oui/");
	printf("{%s}\n", ptr);
	tab = ft_strsplit(ptr, '/');
	print_tab(tab);
	free_tab(tab);

	printf("test itoa 42 : %s\n", ft_itoa(42));
	printf("test itoa -42 : %s\n", ft_itoa(-42));
	printf("test itoa 0 : %s\n", ft_itoa(0));
	printf("test itoa INTMAX : %s\n", ft_itoa(INT_MAX));
	printf("test itoa INTMIN : %s\n", ft_itoa(INT_MIN));

	ft_putchar('c');
	ft_putchar('\n');
	ft_putchar(0);
	ft_putchar('\n');

	ft_putstr("test ft_putstr\n");
	ft_putendl("test ft_putendl");
	ft_putnbr(42);
	ft_putchar('\n');
	ft_putnbr(-42);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(INT_MAX);
	ft_putchar('\n');
	ft_putnbr(INT_MIN);
	ft_putchar('\n');

	testlist();
	return (0);
}
