/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:55:10 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/21 20:39:30 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_str_from_day_week(int id)
{
	if (id == 0)
		return ("Sun");
	else if (id == 1)
		return ("Mon");
	else if (id == 2)
		return ("Tue");
	else if (id == 3)
		return ("Wed");
	else if (id == 4)
		return ("Thu");
	else if (id == 5)
		return ("Fri");
	return ("Sat");
}

char	*get_str_from_month(int id)
{
	if (id == 0)
		return ("Jan");
	else if (id == 1)
		return ("Feb");
	else if (id == 2)
		return ("Mar");
	else if (id == 3)
		return ("Apr");
	else if (id == 4)
		return ("May");
	else if (id == 5)
		return ("Jun");
	else if (id == 6)
		return ("Jul");
	else if (id == 7)
		return ("Aug");
	else if (id == 8)
		return ("Sep");
	else if (id == 9)
		return ("Oct");
	else if (id == 10)
		return ("Nov");
	return ("Dec");
}
