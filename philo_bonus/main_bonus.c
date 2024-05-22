/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymabsout <ymabsout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:11:37 by ymabsout          #+#    #+#             */
/*   Updated: 2024/01/21 18:16:23 by ymabsout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*checker(void *st)
{
	t_phis	*philoss;
	int		i;

	philoss = (t_phis *)st;
	i = -1;
	sem_wait(philoss[0].die);
	while (++i < philoss->infos.nump)
		kill(philoss[i].pid_philo, SIGKILL);
	return (NULL);
}

int	main(int ac, char *av[])
{
	t_defs		*informs;
	t_phis		*philoss;
	t_semstruct	*sems;
	pthread_t	t1;
	int			i;

	i = -1;
	informs = parsebonus(av, ac);
	sems = malloc(sizeof(t_semstruct));
	if (!sems)
		errorhandle(3);
	(sem_unlink("die"), sem_unlink("semprint"), sem_unlink("sem"));
	sems->printsem = set_semaphore("semprint", 1);
	sems->semaphore = set_semaphore("sem", informs->nump);
	sems->diesem = set_semaphore("die", 0);
	philoss = simulation(informs, sems);
	if (pthread_create(&t1, NULL, checker, philoss) != 0
		|| pthread_detach(t1) != 0)
		errorhandle(3);
	while (++i < informs->nump)
		waitpid(philoss[i].pid_philo, 0, 0);
	return (sem_post(sems->diesem), free_close(sems, informs, philoss), \
		sem_unlink("semprint"), sem_unlink("sem"), sem_unlink("die"), 0);
}
