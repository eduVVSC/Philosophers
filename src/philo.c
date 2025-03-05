/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:31:42 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/05 11:42:28 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	philo_thinking(t_philo *philo)
{
	print_message(philo, THINKING_M);
}

void	philo_sleeping(t_philo *philo)
{
	philo->action_start = get_time();
	print_message(philo, SLEEPING_M);
	while ((philo->time_now - philo->action_start) < philo->time_sleep)
	{
		if (*philo->life_status == DEAD)
			break ;
		philo->time_now = get_time();
		if ((philo->time_now - philo->time_beg_one_loop) >= philo->time_die)
		{
			print_message(philo, DEAD_M);
			*philo->life_status = DEAD;
			break ;
		}
		philo->time_now = get_time();
	}
}

void	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	print_message(philo, FORK_M);
	pthread_mutex_lock(philo->r_fork);
	print_message(philo, FORK_M);
	print_message(philo, EATING_M);
	philo->action_start = get_time();
	while ((philo->time_now - philo->action_start) < philo->time_eat)
	{
		if (*philo->life_status == DEAD)
			break ;
		if ((philo->time_now - philo->time_beg_one_loop) >= philo->time_die)
		{
			print_message(philo, DEAD_M);
			*philo->life_status = DEAD;
			break ;
		}
		philo->time_now = get_time();
	}
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*philo_routine(void *philo_img)
{
	t_philo	*philo;

	philo = (t_philo *)philo_img;
	philo->loop_start = get_time();
	philo->time_beg_one_loop = philo->loop_start;
	while (*philo->life_status == ALIVE)
	{
		philo->time_now = get_time();
		if (*philo->life_status == ALIVE)
			philo_thinking(philo);
		if (*philo->life_status == ALIVE)
			philo_eating(philo);
		philo->eaten++;
		philo->time_beg_one_loop = get_time();
		if (*philo->life_status == ALIVE)
			philo_sleeping(philo);
		if (*philo->life_status == ALIVE)
			usleep(10);
		if (philo->max_eat != -1 && philo->eaten == philo->max_eat)
		{
			printf("---------- philo %d ate %d times\n", philo->phl_num, philo->eaten);
			break ;
		}
	}
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
