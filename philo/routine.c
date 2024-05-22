/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymabsout <ymabsout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:26:28 by ymabsout          #+#    #+#             */
/*   Updated: 2024/01/18 17:51:46 by ymabsout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timeexec(void)
{
	struct timeval	t;
	long			t1;

	if (gettimeofday(&t, NULL) == -1)
		return (0);
	t1 = ((t.tv_sec * 1000) + (t.tv_usec / 1000));
	return (t1);
}

void	sleepy(t_infs *p, int time)
{
	long	i;

	if (gettimeofday(&p->t_time, NULL) == -1)
		return ;
	i = (p->t_time.tv_sec * 1000 + p->t_time.tv_usec / 1000);
	while (p->init_time - i < time)
	{
		usleep(10);
		settime(p);
	}
}

void	print(t_infs *p, char *s)
{
	pthread_mutex_lock(p->print);
	printf("%ld %d %s\n", timeexec() - p->keep_time, p->ph, s);
	pthread_mutex_unlock(p->print);
}

void	lock(t_infs *p)
{
	while (1)
	{
		print(p, "is thinking");
		pthread_mutex_lock(p->t1);
		print(p, "has taken a fork");
		print(p, "is thinking");
		pthread_mutex_lock(p->t2);
		print(p, "has taken a fork");
		print(p, "is eating");
		pthread_mutex_lock(p->meals);
		p->last_meal = timeexec() - p->keep_time;
		p->infs.numberofmeals--;
		pthread_mutex_unlock(p->meals);
		sleepy(p, p->infs.timetoeat);
		pthread_mutex_unlock(p->t2);
		pthread_mutex_unlock(p->t1);
		if (p->infs.numberofmeals == 0)
			break ;
		print(p, "is sleeping");
		sleepy(p, p->infs.timetosleep);
	}
}
