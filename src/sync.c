/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:03:54 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/05 19:37:20 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

/// @brief Function for inside each thread so it will
/// @brief be forced to wait in for the other ones bf start
/// @param philo
void	force_sync(t_philo *philo)
{
	philo->on = TRUE;
	while (*philo->life_status == WAITING)
	{
	}
	if (philo->phl_num % 2 == 0)
		usleep(500);
}

/// @brief Routine dor table, that will basecally
/// @brief wait for all the threads to be setted
/// @param prog_img
void	*waiting_sync(void *prog_img)
{
	t_all	*prog;
	t_philo	*tmp;
	int		sync;

	sync = 1;
	prog = (t_all *)prog_img;
	while (sync == 1)
	{
		tmp = prog->philo;
		sync = 0;
		while (tmp)
		{
			if (tmp->on == FALSE)
			{
				sync = 1;
				break ;
			}
			tmp = tmp->next;
		}
	}
	prog->life_status = ALIVE;
	return (NULL);
}
