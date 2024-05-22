/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_free_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymabsout <ymabsout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:45:56 by ymabsout          #+#    #+#             */
/*   Updated: 2024/01/21 17:11:22 by ymabsout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*set_semaphore(const char *s, int number)
{
	sem_t	*semaphore;

	semaphore = sem_open(s, O_CREAT, 0666, number);
	if (!semaphore)
		errorhandle(3);
	return (semaphore);
}

void	free_close(t_semstruct *sems, t_defs *infos, t_phis *ph)
{
	sem_close(sems->printsem);
	sem_close(sems->semaphore);
	sem_close(sems->diesem);
	free(sems);
	free(infos);
	free(ph);
}
