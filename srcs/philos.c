/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:56:40 by edvieira          #+#    #+#             */
/*   Updated: 2024/09/11 15:37:20 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*one_philo_routine(void *philo_info)
{
	t_philo	*philo;

	philo = (t_philo *)philo_info;
	philo->time_start =  get_time();;
	pthread_mutex_lock(&philo->l_fork);
	print_message(philo, "has taken a fork");
	usleep(philo->time_to_die * 1000);
	pthread_mutex_unlock(&philo->l_fork);
	print_message(philo, "died");
	return (NULL);
}

int	philo_eat(t_philo *philo)
{
	if (*philo->dead == DEAD)
		return (ERROR);
	if ((philo->time_now - philo->time_bf_action) >= philo->time_to_die)
	{
		print_message(philo, "died	💀");
		*philo->dead = DEAD;
		return (ERROR);
	}
	print_message(philo, "is thinking		🤔"); // how am i supposed to do it??
	pthread_mutex_lock(&philo->l_fork); //------locking
		print_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork); //------locking
		print_message(philo, "has taken a fork");
		print_message(philo, "is eating		🍅");
		philo->time_bf_action = get_time(); //-----atualizing the time since las eaten here
		usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->l_fork); //------unlocking
	pthread_mutex_unlock(philo->r_fork); //------unlocking
	return (SUCCESS);
}

int	philo_sleep(t_philo *philo)
{
	print_message(philo, "is sleeping");
	while ((philo->time_now - philo->time_bf_action) < philo->time_to_sleep)
	{
		if ((philo->time_now - philo->time_bf_action) >= philo->time_to_die)
		{
			print_message(philo, "died	💀");
			*philo->dead = DEAD;
			return (ERROR);
		}
		if (*philo->dead == DEAD)
			return (ERROR);
		philo->time_now = get_time();
	}
	//print_message(philo, "is thinking		🤔"); // thinking here is correct
	return (SUCCESS);
}

void	*philo_routine(void *philo_img)
{
	t_philo *philo;
	philo = (t_philo *)philo_img;
	philo->time_start = get_time(); // time used to print
	philo->time_bf_action = philo->time_start;
	while (1)
	{
		philo->time_now = get_time();
		if (*philo->dead == DEAD || philo_eat(philo) == ERROR)
			break ;
		philo->many_eaten++;
		if (philo->many_to_eat > 0 && philo->many_eaten == philo->many_to_eat)
			break ;
		if (*philo->dead == DEAD || philo_sleep(philo) == ERROR)
			break ;
		usleep(50); // threads are uphappening each other
	}
	return (NULL);
}

/*
				Time tracking:

	time_bf_action ==> is being refreshed inside the eat function, just after the
	philo ate.

	time_now ==> refreshed at: philo_routine loop, philo_sleep loop;

	time_start ==> got in the beggining of the routine;
*/

/*	--------------------Atualização do progresso:

	- Programa funciona com o adicional de quantas vezes deve-se comer;
	- Programa ja funciona com somente um filosofo;
	- Morte no sleep já funciona perfeitamente;


Falta fazer:
	- monitoring da table/philosofos, para saber quando morreram durente o comer;
	- Arrumar o primeiro print do thinking(tomar cuidado porque isso muda a questao do comer);

BAsicamente falta fazer eles morrerem quando comem, nesse caso tenho de locar as mensagens e matar a porra toda

*/
