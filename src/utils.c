/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:04:37 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/11 18:45:05 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

/// @brief Get the time and round it
/// @return (time value)
size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("error in gettimeofday\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/// @brief Check the user's input for non-num
/// @param str
/// @return (TRUE -> only nums) (FALSE -> another character)
int	check_only_nums(char **str)
{
	int	i;
	int	j;

	j = 1;
	while (str[j] != 0)
	{
		i = -1;
		while (str[j][++i] != 0)
			if (str[j][i] > '9' || str[j][i] < '0')
				return (FALSE);
		j++;
	}
	return (TRUE);
}

/// @brief Check if the inputs given are valid
/// @brief (positive numbers)
/// @param val
/// @param ac
/// @return (TRUE -> valid inputs) (FALSE -> invalid inputs)
int	valid_inputs(t_inp_values val, int ac)
{
	if (val.many_philo <= 0)
		return (FALSE);
	if (val.time_die < 0)
		return (FALSE);
	if (val.time_sleep < 0)
		return (FALSE);
	if (val.time_eat < 0)
		return (FALSE);
	if (val.max_eat <= 0 && ac == 6)
		return (FALSE);
	return (TRUE);
}

/// @brief Get both forks to eat, in a non inversion way
/// @param philo
void	let_forks(t_philo *philo)
{
	if (philo->phl_num % 2 == 0)
	{
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(&philo->l_fork);
	}
}

/// @brief Get both forks to eat, in a non inversion way
/// @param philo
void	get_forks(t_philo *philo)
{
	if (philo->phl_num % 2 == 0)
	{
		pthread_mutex_lock(&philo->l_fork);
		print_message(philo, FORK_M);
		pthread_mutex_lock(philo->r_fork);
		print_message(philo, FORK_M);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_message(philo, FORK_M);
		pthread_mutex_lock(&philo->l_fork);
		print_message(philo, FORK_M);
	}
}
