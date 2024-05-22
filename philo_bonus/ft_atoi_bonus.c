/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymabsout <ymabsout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:35:27 by ymabsout          #+#    #+#             */
/*   Updated: 2024/01/17 20:20:17 by ymabsout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	taker(char *s, int sign)
{
	int	nbr;
	int	nb;
	int	i;

	i = 1;
	nb = 0;
	nbr = 0;
	while (*s >= '0' && *s <= '9')
	{
		nb = nbr * 10 + (*s - '0');
		if (i == 9 && *s == 9)
			errorhandle(2);
		if (nb < nbr && sign == 1)
			errorhandle(2);
		else if (nb < nbr && sign == -1 && nb != -2147483648)
			errorhandle(2);
		nbr = nb;
		s++;
		i++;
	}
	if ((*s) != '\0')
		errorhandle(2);
	return ((int)nbr * sign);
}

int	ft_atoi(char *str)
{
	char	*s;
	int		sign;

	sign = 1;
	s = (char *)str;
	while (*s == ' ')
		s++;
	if (*s == '+' && *(s + 1) != '\0')
		s++;
	else if (*s == '-' && *(s + 1) != '\0')
	{
		sign = -1;
		s++;
	}
	return (taker(s, sign));
}
