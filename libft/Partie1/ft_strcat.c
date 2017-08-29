char	*ft_strcat(char *dest, const char *src)
{
	int	index[2];

	index[0] = 0;
	index[1] = 0;
	if (src == 0 || *src == 0)
		return (dest);
	if (dest == 0)
		return (0);
	while (dest[index[0]])
		index[0]++;
	while (src[index[1]])
	{
		dest[index[0] + index[1]] = src[index[1]];
		index[1]++;
	}
	dest[index[0] + index[1]] = 0;
	return (dest);
}