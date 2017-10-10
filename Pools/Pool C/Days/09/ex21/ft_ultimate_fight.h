/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_fight.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 16:20:55 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 16:29:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ULTIMATE_FIGHT_H
# define FT_ULTIMATE_FIGHT_H

# include <unistd.h>

# define KICK1 "judo chop ichi"
# define KICK2 "judo chop ni"
# define KICK3 "judo chop san"
# define KICK4 "judo chop shi"
# define KICK5 "judo chop go"
# define KICK6 "judo chop roku"
# define KICK7 "judo chop shishi"
# define KICK8 "judo chop hachi"
# define KICK9 "judo chop ku"
# define KICK10 "judo chop ju"
# define KICK11 "judo chop hyaku"
# define KICK12 "judo chop sen"

typedef struct		s_perso
{
	char	*name;
	float	life;
	int		age;
	char	*profession;
}					t_perso;

#endif
