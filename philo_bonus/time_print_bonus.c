/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_print_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymabsout <ymabsout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:56:28 by ymabsout          #+#    #+#             */
/*   Updated: 2024/01/21 17:39:19 by ymabsout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	timeexec(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000 + t.tv_usec / 1000));
}

void	sleepy(t_phis *philos, int time)
{
	long	i;

	(void)philos;
	i = timeexec();
	while (timeexec() - i < time)
		;
}

void	print(t_phis *philos, char *s)
{
	sem_wait(philos->print);
	printf("%ld %d %s\n", timeexec() - philos->starting, philos->id, s);
	sem_post(philos->print);
}

void	*checkdeath(void *philos)
{
	t_phis	*ph;

	ph = (t_phis *)philos;
	while (1)
	{
		if (timeexec() - ph->last_meal >= ph->infos.timetodie)
		{
			sem_wait(ph->print);
			printf("%ld %d died\n", timeexec() - ph->starting, ph->id);
			sem_post(ph->die);
			exit(0);
		}
	}
	return (NULL);
}
