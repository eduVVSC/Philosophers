/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:15:55 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/03 11:16:10 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	print_philo_info(t_philo *philo)
{
    if (!philo) {
        printf("Error: NULL pointer received.\n");
        return;
    }

    printf("Philosopher Info:\n");
    printf("  Eaten: %d\n", philo->eaten);
    printf("  Philosopher Number: %d\n", philo->phl_num);
    printf("  Max Eat: %d\n", philo->max_eat);
    printf("  Time to Die: %d\n", philo->time_die);
    printf("  Time to Eat: %d\n", philo->time_eat);
    printf("  Time to Sleep: %d\n", philo->time_sleep);
    printf("  Loop Start: %ld\n", philo->loop_start);
    printf("  Action Start: %ld\n", philo->action_start);
    printf("  Time Now: %ld\n", philo->time_now);

    printf("  Life Status Pointer: %p\n", (void *)philo->life_status);
    printf("  Messager Pointer: %p\n", (void *)philo->messager);
    printf("  Left Fork Mutex Address: %p\n", (void *)&philo->l_fork);
    printf("  Right Fork Pointer: %p\n", (void *)philo->r_fork);
    printf("  Next Philosopher Pointer: %p\n", (void *)philo->next);
}

void	printPhilos(t_philo *philo)
{
	while (philo)
	{
		print_philo_info(philo);
		philo = philo->next;
	}

}
