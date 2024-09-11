/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:06:47 by edvieira          #+#    #+#             */
/*   Updated: 2024/09/11 15:12:07 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	one_philo(t_all *data, char **av)
{
	data->philo[0].time_to_die = ft_atoi(av[2]);
	data->philo[0].message = &data->message;
	data->philo[0].dead = &data->dead;
	pthread_mutex_init(&data->philo[0].l_fork, NULL);
	pthread_create(&data->philo[0].thread, NULL,
		one_philo_routine, &data->philo[0]);
	pthread_join(data->philo[0].thread, NULL);
	pthread_mutex_destroy(&data->philo[0].l_fork);
	exit (SUCCESS);
}

void	starting_forks(t_all *data)
{
	int	i;

	i = -1;
	while (++i < data->many_philo)
		pthread_mutex_init(&data->philo[i].l_fork, NULL);
	while (--i >= 0)
	{
		if (i == (data->many_philo - 1))
			data->philo[i].r_fork = &data->philo[0].l_fork;
		else
			data->philo[i].r_fork = &data->philo[i + 1].l_fork;
	}
}

void	initializing_values(t_all *data, int flag, char **av)
{
	int	i;

	i = -1;
	data->many_philo = ft_atoi(av[1]);
	data->dead = ALIVE;
	pthread_mutex_init(&data->message, NULL);
	if (data->many_philo == 1)
		one_philo(data, av);
	while (++i < data->many_philo)
	{
		data->philo[i].many_philo = data->many_philo;
		data->philo[i].time_to_die = ft_atoi(av[2]);
		data->philo[i].time_to_eat = ft_atoi(av[3]);
		data->philo[i].time_to_sleep = ft_atoi(av[4]);
		data->philo[i].many_to_eat = -1;
		data->philo[i].each_philo = i;
		data->philo[i].dead = &data->dead;
		data->philo[i].message = &data->message;
		if (flag == 0)
			data->philo[i].many_to_eat = ft_atoi(av[5]);
		pthread_create(&data->philo[i].thread, NULL, philo_routine, &data->philo[i]);
	}
	starting_forks(data);
}

void starting_table(t_all *data)
{
	int	i;

	i = -1;
	pthread_create(&data->table, NULL, table_routine, &data);
	pthread_join(data->table, NULL);
	while (++i < data->many_philo)
		pthread_join(data->philo[i].thread, NULL);
}

int	main(int ac, char **av)
{
	t_all	data;

	if (ac == 5 || ac == 6)
	{
		if (check_characters(av) == 1)
			return (write(1, "E", 1));
		if (ac == 5)
			initializing_values(&data, 1, av);
		else
			initializing_values(&data, 0, av);
		starting_table(&data);
	}
	else
		return (1);
	return (0);
}
