/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philof.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymabsout <ymabsout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:52:36 by ymabsout          #+#    #+#             */
/*   Updated: 2024/01/17 14:42:09 by ymabsout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroymutex(t_infs *p, t_mutexes *mutx, char *s, int i)
{
	pthread_mutex_lock(mutx->printt);
	if (s)
		printf("%ld %d %s\n", timeexec() - p[i].keep_time, p[i].ph, s);
	pthread_mutex_destroy(mutx->mealsp);
	pthread_mutex_destroy(mutx->nummeals);
	pthread_mutex_destroy(mutx->printt);
	return (0);
}

int	mainthread(t_infs *p, t_mutexes *mutx)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < p->infs.nump)
		{
			pthread_mutex_lock(p[i].meals);
			if (timeexec() - p[i].keep_time \
				- p[i].last_meal >= p[i].infs.timetodie)
				return (destroymutex(p, mutx, "died", i));
			pthread_mutex_unlock(p[i].meals);
			pthread_mutex_lock(p[i].meals);
			if (p[i].infs.numberofmeals != 0)
			{
				pthread_mutex_unlock(p[i].meals);
				break ;
			}
			if (p[i].infs.numberofmeals == 0 && i == p->infs.nump - 1)
				return (destroymutex(p, mutx, NULL, 0));
			pthread_mutex_unlock(p[i].meals);
		}
	}
	return (0);
}

void	launch(t_infs *p, t_mutexes *mutx, t_def *data)
{
	int	i;

	i = -1;
	while (++i < data->nump)
	{
		if (pthread_create(&p[i].philo, NULL, &table, &p[i]) != 0 \
			|| pthread_detach(p[i].philo) != 0)
			return ;
		usleep(50);
	}
	mainthread(p, mutx);
}

void	fillphilo(t_infs *p, t_mutexes *mutx, t_def *data)
{
	unsigned long	st;
	int				i;

	i = -1;
	st = timeexec();
	while (++i < data->nump)
	{
		gettimeofday(&p[i].current_time, NULL);
		p[i].meals = mutx->mealsp;
		p[i].numeals = mutx->nummeals;
		p[i].keep_time = st;
		p[i].last_meal = timeexec() - st;
		p[i].infs = *data;
		p[i].ph = i + 1;
	}
	launch(p, mutx, data);
}

int	philosfunc(t_infs *p, t_def *data)
{
	t_mutexes		*mutx;
	pthread_mutex_t	*mut;
	pthread_mutex_t	*printt;
	pthread_mutex_t	*mealsp;
	pthread_mutex_t	*nummeals;

	mutx = malloc(sizeof(t_mutexes));
	if (!mutx)
		return (0);
	printt = malloc(sizeof(pthread_mutex_t) * 1);
	mut = malloc(sizeof(pthread_mutex_t) * data->nump);
	mealsp = malloc(sizeof(pthread_mutex_t) * 1);
	nummeals = malloc(sizeof(pthread_mutex_t) * 1);
	if (!printt || !mut || !mealsp || !nummeals)
		return (0);
	if (pthread_mutex_init(printt, NULL) != 0 \
		|| pthread_mutex_init(mealsp, NULL) != 0 \
		|| pthread_mutex_init(nummeals, NULL) != 0)
		return (0);
	mutx->mealsp = mealsp;
	mutx->mut = mut;
	mutx->printt = printt;
	mutx->nummeals = nummeals;
	return (fillmut(mutx, p, data), fillphilo(p, mutx, data), \
		free(mut), free(mealsp), free(nummeals), free(mutx), free(printt), 0);
}
