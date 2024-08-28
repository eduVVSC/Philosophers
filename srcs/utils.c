/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:04:40 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/26 16:44:12 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_philo(t_all *data)
{
	int	i;

	i = 0;
	while (i < data->many_philo)
	{
		free (&data->philo[i]);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	long	num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (num > 2147483647)
		exit (EXIT_FAILURE);
	return ((int)num);
}

int	check_characters(char **str)
{
	int	i;
	int	j;

	j = 1;
	while(str[j] != 0)
	{
		i = -1;
		while(str[j][++i] != 0)
			if(str[j][i] > '9' || str[j][i] < '0')
				return (1);
		j++;
	}
	return (0);
}

void	print_philo_info(t_all *data)
{
	printf("many_philosophers: %d\n", data->philo[0].many_philo);
	printf("time_to_die: %d\n", data->philo[0].time_to_die);
	printf("time_to_eat: %d\n", data->philo[0].time_to_eat);
	printf("time_to_sleep: %d\n", data->philo[0].time_to_sleep);
	printf("many_to_eat :%d\n", data->philo[0].many_to_eat);
	printf("\n\n--philosophers:\n");
	for (int i = 0; i < data->many_philo; i++)
	{
		printf("philo %d has eaten %d times\n", i, data->philo[i].many_eaten);
		printf("\tleft_fork:|%p| right_fork:|%p|\n", &data->philo[i].l_fork, data->philo[i].r_fork);
	}
	printf("time_started: %ld\n", data->philo[0].time_start);
	gettimeofday(&data->tv , NULL);
	printf("time_now: %ld\n", data->tv.tv_usec);
}
