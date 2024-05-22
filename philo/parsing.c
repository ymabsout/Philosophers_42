/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymabsout <ymabsout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:15:20 by ymabsout          #+#    #+#             */
/*   Updated: 2024/01/21 20:59:19 by ymabsout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_def	*parseinfo(char **av, int ac)
{
	t_def	*informs;

	informs = malloc(sizeof(t_def));
	if (!informs)
		return (NULL);
	if (ac == 5)
		informs->numberofmeals = -1;
	else
	{
		informs->numberofmeals = ft_atoi(av[5]);
		if (informs->numberofmeals == -1)
			return (NULL);
	}
	informs->timetodie = ft_atoi(av[2]);
	informs->nump = ft_atoi(av[1]);
	informs->timetoeat = ft_atoi(av[3]);
	informs->timetosleep = ft_atoi(av[4]);
	if (informs->nump <= 0 || informs->timetosleep < 0 \
		|| informs->timetoeat < 0 || informs->timetodie < 0 \
		|| informs->numberofmeals == 0)
		return (NULL);
	return (informs);
}
