/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:31:42 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/11 18:44:22 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	philo_thinking(t_philo *philo)
{
	print_message(philo, THINKING_M);
}

int	philo_sleeping(t_philo *philo)
{
	philo->action_start = get_time();
	print_message(philo, SLEEPING_M);
	while ((philo->time_now - philo->action_start) < philo->time_sleep)
	{
		if (life_status(CHECK, philo) == DEAD)
			return (FALSE);
		if (!alive(philo))
		{
			life_status(SET, philo);
			return (FALSE);
		}
		usleep(100);
	}
	return (TRUE);
}

int	philo_eating(t_philo *philo)
{
	get_forks(philo);
	print_message(philo, EATING_M);
	philo->action_start = get_time();
	while ((philo->time_now - philo->action_start) < philo->time_eat)
	{
		if (life_status(CHECK, philo) == DEAD)
		{
			let_forks(philo);
			return (FALSE);
		}
		if (!alive(philo))
		{
			life_status(SET, philo);
			let_forks(philo);
			return (FALSE);
		}
		usleep(50);
	}
	let_forks(philo);
	philo->time_beg_one_loop = get_time();
	philo->eaten++;
	return (TRUE);
}

void	*philo_routine(void *philo_img)
{
	t_philo	*philo;

	philo = (t_philo *)philo_img;
	force_sync(philo);
	philo->loop_start = get_time();
	if (philo->phl_num % 2 == 1)
		usleep(150);
	philo->time_beg_one_loop = philo->loop_start;
	while (life_status(CHECK, philo) == ALIVE)
	{
		philo->time_now = get_time();
		if (life_status(CHECK, philo) == ALIVE)
			philo_thinking(philo);
		if (!philo_eating(philo))
			break ;
		if (philo->max_eat != -1 && philo->eaten == philo->max_eat)
			break ;
		if (!philo_sleeping(philo))
			break ;
		usleep(50);
	}
	//printf("===end thread %d ok\n", philo->phl_num);
	return (NULL);
}

void	*one_philo_routine(void *philo_img)
{
	t_philo	*philo;

	philo = (t_philo *)philo_img;
	philo->loop_start = get_time();
	philo_thinking(philo);
	pthread_mutex_lock(&philo->l_fork);
	print_message(philo, FORK_M);
	usleep(philo->time_die * 1000);
	pthread_mutex_unlock(&philo->l_fork);
	print_message(philo, DEAD_M);
	return (NULL);
}
