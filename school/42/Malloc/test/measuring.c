/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measuring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:49:30 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 15:10:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

long			g_ru_minflt = 0;
long			g_ru_majflt = 0;

static int		itoa_buff(int i, char buff[42])
{
	int s;
	int t;

	s = 1;
	t = i;
	while (t /= 10)
		++s;
	t = s;
	buff[s] = '\0';
	while (t--)
	{
		buff[t] = i % 10 + '0';
		i /= 10;
	}
	return (s);
}

void			start_test(void)
{
	struct rusage rusage;

	getrusage(RUSAGE_SELF, &rusage);
	g_ru_minflt = rusage.ru_minflt;
	g_ru_majflt = rusage.ru_majflt;
}

void			end_test(void)
{
	struct rusage	rusage;
	long			eff_minflt;
	long			eff_majflt;
	char			buff[42];
	int				s;

	getrusage(RUSAGE_SELF, &rusage);
	eff_minflt = rusage.ru_minflt - g_ru_minflt;
	eff_majflt = rusage.ru_majflt - g_ru_majflt;
	write(1, "\t\tpage reclaims / faults : ", 29);
	s = itoa_buff(eff_minflt, buff);
	write(1, buff, s);
	write(1, " / ", 3);
	s = itoa_buff(eff_majflt, buff);
	write(1, buff, s);
	write(1, "\n", 1);
}
