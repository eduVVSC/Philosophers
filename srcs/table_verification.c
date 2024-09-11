/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:29:43 by edvieira          #+#    #+#             */
/*   Updated: 2024/09/11 14:59:25 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_alive(t_all *table)
{
	int	i;

	i = -1;
	while(++i < table->many_philo)
	{
		if (table->philo[i].time_to_die <= (table->philo[i].time_now - table->philo[i].time_bf_action))
			return (DEAD);
	}
	return (ALIVE);
}

void	*table_routine(void	*table_info)
{
	t_all	*table;

	table = (t_all *) table_info;
	while(table->dead == ALIVE)
	{
		if (check_alive(table) == DEAD)
		{
			for (int i = 0; i < table->many_philo; i++)
			{
				pthread_detach(table->philo[i].thread);
			}

		}
	}
	return (NULL);
}

/*
the checker of how many time the philophers have eaten is already done in their routines (working)
*/
