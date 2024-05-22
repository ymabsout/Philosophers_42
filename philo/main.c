/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymabsout <ymabsout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:20:09 by ymabsout          #+#    #+#             */
/*   Updated: 2024/01/16 22:51:14 by ymabsout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	settime(t_infs *p)
{
	gettimeofday(&p->innit_time, NULL);
	p->init_time = (p->innit_time.tv_sec * 1000) \
		+ (p->innit_time.tv_usec / 1000);
}

void	*table(void *d)
{
	t_infs	*p;

	p = (t_infs *)d;
	settime(p);
	lock(p);
	return (NULL);
}

void	fillmut(t_mutexes *mutx, t_infs *p, t_def *data)
{
	int	i;

	i = -1;
	while (++i < data->nump)
	{
		p[i].print = mutx->printt;
		if (pthread_mutex_init(&mutx->mut[i], NULL) != 0)
			return ;
	}
	i = -1;
	while (++i < data->nump)
	{
		p[i].t1 = &mutx->mut[i];
		p[i].t2 = &mutx->mut[(i + 1) % data->nump];
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_infs	*p;
	t_def	*data;

	i = 0;
	if (ac != 5 && ac != 6)
		return (error(4));
	data = parseinfo(av, ac);
	if (!data)
		return (0);
	p = malloc(sizeof(t_infs) * ft_atoi(av[1]));
	if (!p)
		return (0);
	philosfunc(p, data);
	free(data);
	free(p);
	return (0);
}
