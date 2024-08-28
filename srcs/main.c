/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:06:47 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/28 13:13:04 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// pode ser que aqui esteja faltando um ponteiro para o garfo do filosofo, nao tenho certeza se eh com o &

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
	gettimeofday(&data->tv , NULL);
	data->many_philo = ft_atoi(av[1]);
	data->dead = ALIVE;
	while (++i < ft_atoi(av[1]))
	{
		data->philo[i].time_start = data->tv.tv_usec;
		data->philo[i].many_philo = ft_atoi(av[1]);
		data->philo[i].time_to_die = ft_atoi(av[2]);
		data->philo[i].time_to_eat = ft_atoi(av[3]);
		data->philo[i].time_to_sleep = ft_atoi(av[4]);
		data->philo[i].many_to_eat = -1;
		data->philo[i].each_philo = i;
		data->philo[i].dead = &data->dead;
		if (flag == 0)
			data->philo[i].many_to_eat = ft_atoi(av[5]);
		pthread_create(&data->philo->thread, NULL, philo_routine, &data->philo[i]);
	}
	starting_forks(data);
}

void	starting_even(t_all *table)
{
	int	i;

	i = -2;
	while((i += 2) < table->many_philo)
		pthread_join(table->philo[i].thread, NULL);
	i--;
	while((i -= 2) > 0)
		pthread_join(table->philo[i].thread, NULL);
}

void	starting_odd(t_all *table)
{
	int	i;

	i = -2;
	while((i += 2) < table->many_philo)
		pthread_join(table->philo[i].thread, NULL);
	i--;
	while((i -= 2) > 0)
		pthread_join(table->philo[i].thread, NULL);
}

void	*table(void *data)
{
	t_all	*table;
	int		i;

	i = -1;
	table = (t_all *)data;
/* 	while (table->philo[0].dead == ALIVE)
	{
		gettimeofday(&table->tv, NULL);
	} */
/* 	if(table->many_philo / 2 == 1)
		starting_odd(table);
	else
		starting_even(table); */
	return (NULL);
}

void	starting_table(t_all *data)
{
	pthread_create(&data->table, NULL, table, &data);
	if(data->many_philo % 2 == 1)
		starting_odd(data);
	else
		starting_even(data);
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
		//print_philo_info(&data);
	}
	else
		return (1);
	return (0);
}
