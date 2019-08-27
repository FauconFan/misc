/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:12:49 by dwald             #+#    #+#             */
/*   Updated: 2017/11/26 16:14:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework.h"

static	void		ft_process_status(t_test *test, int status)
{
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) != 0)
			test->success = -1;
		else
			test->success = 0;
	}
	if (WIFSIGNALED(status) || status == SIGABRT ||
	status == SIGBUS || status == SIGSEGV)
	{
		test->success = -1;
		test->signal = status;
	}
}

void				test_function(t_test *test)
{
	pid_t					process;
	int						status;

	if ((process = fork()) == -1)
	{
		my_putstr("error in forking, exit\n");
		exit(1);
	}
	if (process > 0)
	{
		wait(&status);
		ft_process_status(test, status);
	}
	else
	{
		exit(test->fptr());
	}
}
