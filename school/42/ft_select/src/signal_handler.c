/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:50:46 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/16 12:01:26 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		handle_sigstop(void)
{
	reset_termios();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

void		handle_sigcont(void)
{
	setup_termios();
	init_signal_handlers();
	display_column();
}

void		stop_program(void)
{
	reset_termios();
	free_select(&g_select);
	exit(EXIT_SUCCESS);
}

void		signal_handler(int signo)
{
	if (signo == SIGTSTP)
		handle_sigstop();
	else if (signo == SIGCONT)
		handle_sigcont();
	else if (signo == SIGINT || signo == SIGABRT || signo == SIGSTOP
			|| signo == SIGKILL || signo == SIGQUIT)
		stop_program();
	else if (signo == SIGWINCH)
		display_column();
}

void		init_signal_handlers(void)
{
	signal(SIGWINCH, signal_handler);
	signal(SIGABRT, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGSTOP, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGQUIT, signal_handler);
}
