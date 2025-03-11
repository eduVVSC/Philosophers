/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:59:26 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/11 16:05:55 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

/// @brief Use the messager mutex to print a given message
/// @param philo
/// @param message
void	print_message(t_philo *philo, char *message)
{
	// transform it to int type of function in order to deal with the error
	// return (ERROR) if couldnt write the message, in this case means that some of the existing philos died
	philo->time_now = get_time();
	pthread_mutex_lock(philo->messager);
	if (*philo->life_status != DEAD)
		printf("%ld %d %s\n", (philo->time_now - philo->loop_start),
			philo->phl_num, message);
	pthread_mutex_unlock(philo->messager);
}

/// @brief Access and manipulate the variable life_status
/// @param action SET change life status -CHECK- returns the status
/// @param philo
/// @return (life_status)
int	life_status(int action, t_philo *philo)
{
	int	status;

	status = 0;
	pthread_mutex_lock(philo->death);
	if (action == SET)
	{
		if (*philo->life_status != DEAD)
		{
			*philo->life_status = DEAD;
			printf("%ld %d %s\n", (philo->time_now - philo->loop_start),
			philo->phl_num, DEAD_M);
		}
	}
	status = *philo->life_status;
	pthread_mutex_unlock(philo->death);
	return (status);
}

/// @brief Refresh time now and check if the philo is
/// @brief still alive
/// @param philo
/// @return (TRUE -> philo is alive) (FALSE -> philo is dead)
int	alive(t_philo *philo)
{
	philo->time_now = get_time();
	if ((philo->time_now - philo->time_beg_one_loop) >= philo->time_die)
		return (FALSE);
	return (TRUE);
}

/// @brief Join the thread on even positions
/// @param philo
void	join(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	tmp = tmp->next;
	while (tmp)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
	}
}

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
