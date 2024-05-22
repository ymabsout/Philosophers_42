/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymabsout <ymabsout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:12:39 by ymabsout          #+#    #+#             */
/*   Updated: 2024/01/21 17:41:23 by ymabsout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_defs	*parsebonus(char **av, int ac)
{
	t_defs	*informs;

	if (ac != 5 && ac != 6)
		errorhandle(1);
	informs = malloc(sizeof(t_defs));
	if (!informs)
		return (NULL);
	if (ac == 5)
		informs->numberofmeals = -1;
	else
		informs->numberofmeals = ft_atoi(av[5]);
	informs->timetodie = ft_atoi(av[2]);
	informs->nump = ft_atoi(av[1]);
	informs->timetoeat = ft_atoi(av[3]);
	informs->timetosleep = ft_atoi(av[4]);
	if (!informs || informs->nump <= 0 || informs->timetosleep < 0 \
		|| informs->timetoeat < 0 || informs->timetodie < 0)
		errorhandle(2);
	return (informs);
}
