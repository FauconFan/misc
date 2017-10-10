/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 15:27:50 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 16:31:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIGHT_H
# define FT_FIGHT_H

# include <unistd.h>

# define KICK		15
# define PUNCH		5
# define HEADBUTT	20

typedef struct		s_perso
{
	char	*name;
	float	life;
	int		age;
	char	*profession;
}					t_perso;

#endif
