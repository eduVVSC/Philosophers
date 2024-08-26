/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:07:12 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/26 11:20:12 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

typedef struct philo_s
{
	int				time_eat;
	int				many_eaten;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork; // its a pointer because it is going to point to the next philosopher fork
}					t_philo;

typedef struct	all_s
{
	struct timeval	tv;
	struct timezone	tz;
	int				to_eat;
	int				many_philo;
	long			time_start;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	t_philo			*philo;
}					t_all;

void	running(t_all *data);
void	free_philo(t_all *data);
void	threads_n_mutex(t_all *data);
void	print_philo_info(t_all *data);
void	initializing_values(t_all *data, int flag, char **av);

int		ft_atoi(const char *str);
int		check_characters(char **str);

#endif
