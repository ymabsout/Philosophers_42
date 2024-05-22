/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymabsout <ymabsout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:41:44 by ymabsout          #+#    #+#             */
/*   Updated: 2024/01/21 17:42:49 by ymabsout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <signal.h>

typedef struct s_criteri
{
	int	timetodie;
	int	timetoeat;
	int	timetosleep;
	int	nump;
	int	numberofmeals;
}	t_defs;

typedef struct s_sem
{
	sem_t	*semaphore;
	sem_t	*printsem;
	sem_t	*diesem;
}	t_semstruct;

typedef struct s_ph
{
	struct timeval	t_time;
	struct timeval	innit_time;
	long			init_time;
	int				p_id;
	int				id;
	long			last_meal;
	sem_t			*sema;
	sem_t			*die;
	sem_t			*print;
	sem_t			*meals;
	sem_t			*threaddeath;
	long			timetokeep;
	t_defs			infos;
	long			starting;
	pid_t			pid_philo;
	pthread_t		th_check;
}	t_phis;

void	errorhandle(int num);
t_defs	*parsebonus(char **av, int ac);
int		ft_atoi(char *str);
int		taker(char *s, int sign);
t_phis	*simulation(t_defs *informs, t_semstruct *sems);
sem_t	*set_semaphore(const char *s, int number);
void	free_close(t_semstruct *sems, t_defs *infos, t_phis *ph);
void	*checkdeath(void *philos);
long	timeexec(void);
void	sleepy(t_phis *philos, int time);
void	print(t_phis *philos, char *s);
void	*checkdeath(void *philos);

#endif