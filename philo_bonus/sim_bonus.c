/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymabsout <ymabsout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:31:51 by ymabsout          #+#    #+#             */
/*   Updated: 2024/01/21 17:38:30 by ymabsout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine(t_phis *philos)
{
	philos->last_meal = timeexec();
	while (1)
	{
		print(philos, "is thinking");
		sem_wait(philos->sema);
		print(philos, "has taken a fork");
		print(philos, "is thinking");
		sem_wait(philos->sema);
		print(philos, "has taken a fork");
		print(philos, "is eating");
		philos->infos.numberofmeals--;
		philos->last_meal = timeexec();
		sleepy(philos, philos->infos.timetoeat);
		sem_post(philos->sema);
		sem_post(philos->sema);
		if (philos->infos.numberofmeals == 0)
			exit (0);
		sem_post(philos->meals);
		print(philos, "is sleeping");
		sleepy(philos, philos->infos.timetosleep);
	}
}

void	createprocess(t_phis *philos)
{
	if (pthread_create(&philos->th_check, NULL, &checkdeath, &philos[0]) != 0
		|| pthread_detach(philos->th_check) != 0)
		errorhandle(3);
	routine(philos);
}

t_phis	*philos_create(int size)
{
	t_phis	*p;

	p = malloc(sizeof(t_phis) * size);
	if (!p)
		errorhandle(3);
	return (p);
}

t_phis	*simulation(t_defs *informs, t_semstruct *sems)
{
	t_phis	*philos;
	int		i;
	pid_t	p_id;
	long	start;

	philos = philos_create(informs->nump);
	i = -1;
	start = timeexec();
	p_id = 1;
	while (++i < informs->nump)
	{
		if (p_id > 0)
			p_id = fork();
		philos[i].id = i + 1;
		philos[i].sema = sems->semaphore;
		philos[i].infos = *informs;
		philos[i].die = sems->diesem;
		philos[i].starting = start;
		philos[i].last_meal = start;
		philos[i].print = sems->printsem;
		philos[i].pid_philo = p_id;
		if (p_id == 0)
			return (createprocess(&philos[i]), NULL);
	}
	return (philos);
}
