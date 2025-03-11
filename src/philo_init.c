/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:13:52 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/11 17:58:16 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

/// @brief Allocate and connect all the philosophers
/// @param prog
/// @param ac
/// @param av
int	start_philos(t_all *prog, int ac, char **av)
{
	t_inp_values	val;
	t_philo			*tmp;
	t_philo			*prev;

	if (!reading_input(&val, av, ac))
		return (ERROR);
	prog->philo = malloc(sizeof(t_philo));
	if (!prog->philo)
		exit (1);
	init_philo_val(prog, prog->philo, val);
	prev = prog->philo;
	while (++val.phl_num <= val.many_philo)
	{
		tmp = malloc(sizeof(t_philo));
		if (!tmp)
			exit (1);
		init_philo_val(prog, tmp, val);
		prev->next = tmp;
		prev = tmp;
	}
	connect_r_fork(prog);
	return (SUCCESS);
}

/// @brief Will read and check all the inputs given
/// @param val
/// @param av
/// @param ac
/// @return (TRUE -> valid inputs) (FALSE -> bad inputs)
int	reading_input(t_inp_values *val, char **av, int ac)
{
	val->phl_num = 1;
	val->many_philo = ft_atoi(av[1]);
	if (ac == 6)
		val->max_eat = ft_atoi(av[5]);
	else
		val->max_eat = -1;
	val->time_die = ft_atoi(av[2]);
	val->time_eat = ft_atoi(av[3]);
	val->time_sleep = ft_atoi(av[4]);
	if (!valid_inputs(*val, ac))
		return (FALSE);
	return (TRUE);
}

/// @brief Start the variable inside a philosopher!
/// @param prog
/// @param philo
/// @param values
void	init_philo_val(t_all *prog, t_philo *philo, t_inp_values val)
{
	philo->eaten = 0;
	philo->on = 0;
	philo->phl_num = val.phl_num;
	philo->max_eat = val.max_eat;
	philo->time_die = val.time_die;
	philo->time_eat = val.time_eat;
	philo->time_sleep = val.time_sleep;
	philo->loop_start = 0 ;
	philo->action_start = 0 ;
	philo->time_now = 0 ;
	philo->time_beg_one_loop = 0;
	philo->life_status = &prog->life_status;
	philo->messager = &prog->messager;
	philo->death = &prog->death;
	pthread_mutex_init(&philo->l_fork, NULL);
	pthread_mutex_init(&philo->on_mutex, NULL); // initializating the mutex
	philo->r_fork = NULL;
	philo->next = NULL;
}

/// @brief Connect the philo's right fork to the next's left fork
/// @param prog
void	connect_r_fork(t_all *prog)
{
	t_philo	*tmp;

	tmp = prog->philo;
	while (tmp->next)
	{
		tmp->r_fork = &tmp->next->l_fork;
		tmp = tmp->next;
	}
	if (prog->many_philo > 1)
		tmp->r_fork = &prog->philo->l_fork;
}

/// @brief Detach mutex and free struct
/// @param prog
void	clean_n_finish(t_all *prog)
{
	t_philo	*tmp;

	pthread_mutex_destroy(&prog->messager);
	pthread_mutex_destroy(&prog->death);
	while (prog->philo)
	{
		pthread_mutex_destroy(&prog->philo->on_mutex);
		pthread_mutex_destroy(&prog->philo->l_fork);
		tmp = prog->philo;
		prog->philo = prog->philo->next;
		free(tmp);
	}
	free(prog);
}
