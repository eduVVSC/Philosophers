/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:59:26 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/05 13:07:39 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

/// @brief Join the thread on odd positions
/// @param philo
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

/// @brief Join the thread on even positions
/// @param philo
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

/* void	change_life_status(t_philo *philo)
{
	pthread_mutex_lock(philo->die);
	if (philo->life_status != DEAD)
		*philo->life_status == DEAD;
	pthread_mutex_unlock(philo->die);
} */

/*void	print_philo_info(t_philo *philo)
{
	if (!philo)
	{
		printf("Error: NULL pointer received.\n");
		return ;
	}
	printf("Philosopher Info:\n");
	printf("  Eaten: %d\n", philo->eaten);
	printf("  Philosopher Number: %d\n", philo->phl_num);
	printf("  Max Eat: %d\n", philo->max_eat);
	printf("  Time to Die: %d\n", philo->time_die);
	printf("  Time to Eat: %d\n", philo->time_eat);
	printf("  Time to Sleep: %d\n", philo->time_sleep);
	printf("  Loop Start: %ld\n", philo->loop_start);
	printf("  Action Start: %ld\n", philo->action_start);
	printf("  Time Now: %ld\n", philo->time_now);
	printf("  Life Status Pointer: %p\n", (void *)philo->life_status);
	printf("  Messager Pointer: %p\n", (void *)philo->messager);
	printf("  Left Fork Mutex Address: %p\n", (void *)&philo->l_fork);
	printf("  Right Fork Pointer: %p\n", (void *)philo->r_fork);
	printf("  Next Philosopher Pointer: %p\n", (void *)philo->next);
}

void	print_philos(t_philo *philo)
{
	while (philo)
	{
		print_philo_info(philo);
		philo = philo->next;
	}
}*/
