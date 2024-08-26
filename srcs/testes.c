/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:06:47 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/26 11:45:13 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


// pode ser que aqui esteja faltando um ponteiro para o garfo do filosofo, nao tenho certeza se eh com o &
void	threads_n_mutex(t_all *data)
{
	int	i;

	i = -1;
	while (++i < data->many_philo)
	{
		pthread_mutex_init(&data->philo[i].l_fork, NULL);
		//pthread_create(&data->philo[i].thread, NULL, run, NULL); //avaliar como usa-lo, creio que tenho de colocar a funcao que vai ter as acoes ds filosofos
	}
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
	gettimeofday(&data->tv , &data->tz);
	data->time_start = data->tv.tv_usec;
	data->many_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->to_eat = 2747419;
	if (flag == 0)
		data->to_eat = ft_atoi(av[5]);
	data->philo = malloc(sizeof(t_philo) * data->many_philo);
	if (!data->many_philo)
	{
		free(data->philo);
		exit (EXIT_FAILURE);
	}
	threads_n_mutex(data);
	print_philo_info(data);
}

int	main(int ac, char **av)
{
	t_all	data;

	if (ac == 5)
	{
		if (check_characters(av) == 1)
			return (write(1, "E", 1));
		initializing_values(&data, 1, av);
	}
	else if(ac == 6)
	{
		if (check_characters(av) == 1)
			return (write(1, "E", 1));
		initializing_values(&data, 0, av);
	}
	else
		return (0);
	return (0);
}
