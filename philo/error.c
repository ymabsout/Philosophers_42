/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymabsout <ymabsout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:54:33 by ymabsout          #+#    #+#             */
/*   Updated: 2024/01/21 20:53:28 by ymabsout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(int num)
{
	if (num == 1)
		(write(2, "wrong number of arguments\n", 26));
	else if (num == 2)
		(write(2, "Negative number\n", 16));
	else if (num == 4)
		(write(1, "Wrong number of arguments\n", 26));
	else if (num == 5)
		write(1, "wrong format of argumets!\n", 26);
	return (0);
}
