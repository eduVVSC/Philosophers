/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:04:34 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/05 10:30:18 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	thread_creat_n_join(t_all *prog)
{
	t_philo	*tmp;

	tmp = prog->philo;
	while (tmp)
	{
		pthread_create(&tmp->thread, NULL, philo_routine, tmp);
		tmp = tmp->next;
	}
	join_odds(prog->philo);
	join_even(prog->philo);
}

t_all	*init_prog_struct(int ac, char **av)
{
	t_all	*prog;

	prog = malloc(sizeof(t_all));
	if (!prog)
		exit (ft_printf("Malloc error!\n"));
	prog->many_philo = ft_atoi(av[1]);
	if (prog->many_philo <= 0)
		return (free(prog), NULL);
	prog->life_status = ALIVE;
	pthread_mutex_init(&prog->messager, NULL);
	prog->philo = NULL;
	start_philos(prog, ac, av);
	return (prog);
}

void	start_game(int ac, char **av)
{
	t_all	*prog;

	prog = init_prog_struct(ac, av);
	if (!prog)
	{
		ft_printf("Need to enter a valid quantity of philosophers(greater than 0)!\n");
		exit (1);
	}
	if (prog->many_philo == 1)
	{
		pthread_create(&prog->philo->thread, NULL, one_philo_routine, prog->philo);
		pthread_join(prog->philo->thread, NULL);
	}
	else
		thread_creat_n_join(prog);
	clean_n_finish(prog);
	exit (SUCCESS);
}

int	main(int ac, char **av)
{
	if (ac >= 5 && check_only_nums(av))
		start_game(ac, av);
	else
		return (1);
	return (0);
}
