/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:04:37 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/05 11:40:58 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

/// @brief Use the messager mutex to print a given message
/// @param philo
/// @param message
void	print_message(t_philo *philo, char *message)
{
	philo->time_now = get_time();
	pthread_mutex_lock(philo->messager);
	if (*philo->life_status != DEAD)
		printf("%ld %d %s\n", (philo->time_now - philo->loop_start),
			philo->phl_num, message);
	pthread_mutex_unlock(philo->messager);
}

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

/// @brief Detach mutex and free struct
/// @param prog
void	clean_n_finish(t_all *prog)
{
	t_philo	*tmp;

	pthread_mutex_destroy(&prog->messager);
	while (prog->philo)
	{
		pthread_mutex_destroy(&prog->philo->l_fork);
		tmp = prog->philo;
		prog->philo = prog->philo->next;
		free(tmp);
	}
	free(prog);
}
