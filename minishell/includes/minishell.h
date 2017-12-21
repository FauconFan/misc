/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:15:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/21 09:22:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define	CST_EXIT	"exit"

typedef struct			s_ms_couple
{
	char				*index;
	char				*value;
	struct s_ms_couple	*next;
}						t_ms_couple;

typedef struct			s_ms_env
{
	t_ms_couple			*cpy_env;
}						t_ms_env;

t_ms_env				*init_ms_env(char **env);
void					free_ms_env(t_ms_env **ms_env);

char					*read_from_input(void);
int						treat_cmd(char *s);

t_ms_couple				*build_cpy_env(char **env);
void					free_cpy_env(t_ms_couple **head);

#endif
