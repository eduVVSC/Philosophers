/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:59:26 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/05 10:29:50 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	join_odds(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (tmp)
	{
		pthread_join(tmp->thread, NULL);
		if (tmp->next && tmp->next->next)
			tmp = tmp->next->next;
		else
			break ;
	}
}

void	join_even(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	tmp = tmp->next;
	while (tmp)
	{
		pthread_join(tmp->thread, NULL);
		if (tmp->next && tmp->next->next)
			tmp = tmp->next->next;
		else
			break ;
	}
}
