/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:03:54 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/11 18:55:14 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

/// @brief Function for inside each thread so it will
/// @brief be forced to wait in for the other ones bf start
/// @param philo
void	force_sync(t_philo *philo)
{
	access_on_var(SET, philo);
	while (life_status(CHECK, philo) == WAITING)
	{
	}
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
			if (!access_on_var(CHECK, tmp))
			{
				sync = 1;
				break ;
			}
			tmp = tmp->next;
		}
	}
	pthread_mutex_lock(prog->philo->death);
	prog->life_status = ALIVE;
	pthread_mutex_unlock(prog->philo->death);
	return (NULL);
}

/// @brief Function to access the on var to make sync
/// @param action
/// @param philo
/// @return (status of on var)
int	access_on_var(int action, t_philo *philo)
{
	int	status;

	status = 0;
	pthread_mutex_lock(&philo->on_mutex);
	if (action == SET)
		philo->on = TRUE;
	status = philo->on;
	pthread_mutex_unlock(&philo->on_mutex);
	return (status);
}

/// @brief Will detach all the threads in the program
/// @param tmp
void	detach(t_philo *tmp)
{
	while (tmp)
	{
		pthread_detach(tmp->thread);
		tmp = tmp->next;
	}
}
