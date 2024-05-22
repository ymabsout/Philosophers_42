/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymabsout <ymabsout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:18:26 by ymabsout          #+#    #+#             */
/*   Updated: 2024/01/21 17:43:18 by ymabsout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	errorhandle(int num)
{
	if (num == 1)
		printf("Number of arguments is wrong\nPlesase insert correct infos\n");
	else if (num == 2)
		printf("Wrong format of input, Enter Correct input please\n");
	else if (num == 3)
		printf("Function failure\n");
	exit(EXIT_FAILURE);
}
