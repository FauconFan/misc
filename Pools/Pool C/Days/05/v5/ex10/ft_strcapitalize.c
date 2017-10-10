/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 14:10:56 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/07 11:40:03 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_low_case(char c)
{
	return ((c >= 'a' && c <= 'z') ? 1 : 0);
}

int		is_up_case(char c)
{
	return ((c >= 'A' && c <= 'Z') ? 1 : 0);
}

int		is_numeric(char c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}

void	do_not_capitalize(int *capitalize, char *str)
{
	char	c;

	c = str[0];
	if (is_up_case(c) == 0)
	{
		if (is_low_case(c) == 0)
		{
			if (is_numeric(c) == 0)
			{
				*capitalize = 1;
			}
		}
	}
	else
	{
		str[0] = c + 'a' - 'A';
	}
}

char	*ft_strcapitalize(char *str)
{
	int		index;
	int		need_capitalize;

	index = 0;
	need_capitalize = 1;
	while (str[index] != '\0')
	{
		if (need_capitalize == 1)
		{
			if (is_low_case(str[index]) == 1)
			{
				str[index] = str[index] - 'a' + 'A';
				need_capitalize = 0;
			}
			else if (is_up_case(str[index]) == 1)
				need_capitalize = 0;
			else if (is_numeric(str[index]) == 1)
				need_capitalize = 0;
		}
		else
			do_not_capitalize(&need_capitalize, str + index);
		index++;
	}
	return (str);
}
