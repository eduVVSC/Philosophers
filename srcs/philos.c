/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:56:40 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/28 14:28:01 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_eat(t_philo *philo)
{
	//printf("\t\t\t\t%d eat status:%d - %d\n",philo->each_philo, philo->many_to_eat, philo->many_eaten);
	if (philo->many_to_eat != -1 || *philo->dead == DEAD)
		if (philo->many_to_eat <= philo->many_eaten)
			return (1);
	while (*philo->dead == ALIVE)
	{
		//printf("\t\t\t\t%d is trying to eat\n", philo->each_philo);
		if (pthread_mutex_lock(&philo->l_fork) == 0 && *philo->dead == ALIVE)
		{
			if (pthread_mutex_lock(philo->r_fork) == 0 && *philo->dead == ALIVE)
			{
				//printf("forks locked by %d\t➕🍴\n", philo->each_philo);
				printf("eating \t\t%d:\t\t🍔\n\n", philo->each_philo);
				break ;
			}
			else
			{
				pthread_mutex_unlock(&philo->l_fork);
				//printf("\t\t\t\t%d Failed to eat\t❌\n", philo->each_philo);
			}
		}
		//else
			//printf("\n\n%d Failed to eat\t❌\n\n", philo->each_philo);
	}
	usleep(philo->time_to_eat * 1000);
//-----------------------unlocking forks-------------------------------//
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);

	// tenho de acrescentar o reset to time to die;

	//printf("\t\t\t\t%d eat status:%d - %d\n",philo->each_philo, philo->many_to_eat, philo->many_eaten);
	//printf("forks released by %d\t➖🍴\n", philo->each_philo);
	return (0);
}

void	*philo_routine(void *philo_img)
{
	t_philo *philo;

	philo = (t_philo *)philo_img;
	printf("created philo %d\n", philo->each_philo);
	while (*philo->dead == ALIVE && philo->many_eaten <= (philo->many_to_eat - 1))
	{
	//---------------------philosopher eating--------------------------//
		if (philo_eat(philo) == 0)
			philo->many_eaten++;
	//---------------------philosopher sleeping--------------------------//
		gettimeofday(&philo->tv, NULL);
		philo->time_bf_action = philo->tv.tv_usec;
		printf("sleeping \t%d:\t😴\n", philo->each_philo);
		while (philo->tv.tv_usec < (philo->time_to_sleep + philo->time_bf_action))
			gettimeofday(&philo->tv, NULL);
		printf("is awake \t%d:\t😳\n", philo->each_philo);
	}
	return (NULL);
}

/*
Basicamente o programa funciona de uma forma com que o philoso, se conseguir, deve dormir
e comer, se nao conseguir comer, este vai pensar.
*/
