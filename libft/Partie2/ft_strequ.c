int		ft_strequ(char const *s1, char const *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}