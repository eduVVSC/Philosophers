/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:04:34 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/03 14:29:48 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	start_game(int ac, char **av)
{
	t_all	*prog;

	prog = init_prog_struct(ac, av);

}

t_all	*init_prog_struct(int ac, char **av)
{
	t_all	*prog;

	prog = malloc(sizeof(t_all));
	if (!prog)
		exit (ft_printf("Malloc error!\n"));
	prog->many_philo = ft_atoi(av[1]);
	prog->life_status = ALIVE;
	pthread_mutex_init(&prog->messager, NULL);
	prog->philo = NULL;
	start_philos(prog, ac, av);
	return (prog);
}

int	main(int ac, char **av)
{
	if (ac >= 5 && check_only_nums(av))
		start_game(ac, av);
	else
		return (1);
	return (0);
}
