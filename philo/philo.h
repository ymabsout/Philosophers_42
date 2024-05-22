/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymabsout <ymabsout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:27:22 by ymabsout          #+#    #+#             */
/*   Updated: 2024/01/16 23:44:01 by ymabsout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_criteria
{
	int	timetodie;
	int	timetoeat;
	int	timetosleep;
	int	nump;
	int	numberofmeals;
}	t_def;

typedef struct s_mut
{
	pthread_mutex_t	*mut;
	pthread_mutex_t	*printt;
	pthread_mutex_t	*mealsp;
	pthread_mutex_t	*nummeals;
}	t_mutexes;

typedef struct s_informations
{
	long			first_exec;
	long			init_time;
	long			keep_time;
	struct timeval	innit_time;
	struct timeval	t_time;
	long			last_meal;
	int				ph;
	pthread_t		philo;
	struct timeval	current_time;
	pthread_mutex_t	*t1;
	pthread_mutex_t	*t2;
	pthread_mutex_t	*print;
	pthread_mutex_t	*meals;
	pthread_mutex_t	*numeals;
	t_def			infs;
}	t_infs;

int		error(int num);
void	fillmut(t_mutexes *mutx, t_infs *p, t_def *data);
int		ft_atoi(char *str);
int		taker(char *s, int sign);
t_def	*parseinfo(char **av, int ac);
void	fillphilo(t_infs *p, t_mutexes *mutx, t_def *data);
int		philosfunc(t_infs *p, t_def *data);
void	sleepy(t_infs *p, int time);
void	settime(t_infs *p);
void	print(t_infs *p, char *s);
void	*table(void *d);
long	timeexec(void);
void	lock(t_infs *p);

#endif