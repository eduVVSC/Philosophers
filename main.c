/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:04:34 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/05 15:07:33 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

/// @brief This will pick each philosopher in the struct
/// @brief and create each thread and join them
/// @param prog
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

/// @brief Read inputs and initializate the program structure vars
/// @param ac
/// @param av
/// @return (Prog struct) (null -> if not good inputs)
t_all	*init_prog_struct(int ac, char **av)
{
	t_all	*prog;

	prog = malloc(sizeof(t_all));
	if (!prog)
		exit (ft_printf("Malloc error!\n"));
	prog->many_philo = ft_atoi(av[1]);
	if (prog->many_philo <= 0)
		return (free(prog), NULL);
	pthread_mutex_init(&prog->messager, NULL);
	pthread_mutex_init(&prog->death, NULL); // new mutex declaration
	prog->life_status = ALIVE;
	prog->philo = NULL;
	if (start_philos(prog, ac, av) == ERROR)
		exit (1);
	return (prog);
}

/// @brief Read users input, create the struct,
/// @brief and run philo threads
void	table(int ac, char **av)
{
	t_all	*prog;

	prog = init_prog_struct(ac, av);
	if (!prog)
		exit (1);
	if (prog->many_philo == 1)
	{
		pthread_create(&prog->philo->thread,
			NULL, one_philo_routine, prog->philo);
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
		table(ac, av);
	else
		return (1);
	return (0);
}
