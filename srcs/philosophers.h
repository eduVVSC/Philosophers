/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:07:12 by edvieira          #+#    #+#             */
/*   Updated: 2024/09/11 14:53:54 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

# define DEAD 1
# define ALIVE 0
# define SUCCESS 0
# define ERROR 1

typedef struct philo_s
{
	int				many_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				many_eaten;
	int				many_to_eat;
	int				eating;
	int				each_philo; // thjis maybe going of later, dont know
	int				*dead;
	long			time_start;
	long			time_bf_action;
	long			time_now;
	pthread_t		thread;
	pthread_mutex_t	*message;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork; // its a pointer because it is going to point to the next philosopher fork
	struct timeval	tv;
}					t_philo;

typedef struct	all_s
{
	struct timeval	tv;
	int				dead;
	int				many_philo;
	pthread_t		table;
	pthread_mutex_t	message;
	t_philo			philo[1000];
}					t_all;

size_t	get_time(void);

void	free_philo(t_all *data);
void	starting_forks(t_all *data);
void	print_philo_info(t_all *data);
void	*philo_routine(void *philo_img);
void	*table_routine(void	*table_info);	
void	*one_philo_routine(void *philo_img);
void	print_message(t_philo *philo ,char *message);
void	initializing_values(t_all *data, int flag, char **av);

int		ft_atoi(const char *str);
int		check_characters(char **str);

#endif

/* 	int				to_eat;
	int			time_start;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep; */
