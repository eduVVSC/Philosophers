/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:52:13 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/11 19:01:49 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "libft.h"
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

# define FALSE 0
# define TRUE 1

# define ALIVE 0
# define DEAD 1
# define WAITING 2

# define SUCCESS 0
# define ERROR 1

# define CHECK 0
# define SET 1

# define FORK_M "has taken a fork"
# define DEAD_M "died"
# define EATING_M "is eating"
# define SLEEPING_M "is sleeping"
# define THINKING_M "is thinking"

/* # define FORK_M "has taken a fork	🍴"
# define DEAD_M "died			💀"
# define EATING_M "is eating		🍅"
# define SLEEPING_M "is sleeping	💤"
# define THINKING_M "is thinking	🤔" */

/// @brief Struct that will hold all the users inputs
typedef struct s_inp_values
{
	int				many_philo;
	int				phl_num;
	int				max_eat;
	int				time_die;
	int				time_eat;
	int				time_sleep;
}				t_inp_values;

/// @brief Has all the philosopher attributes
typedef struct s_philo
{
	// philosopher characteristics
	int				on; //
	int				eaten; //
	int				phl_num;//
	int				max_eat;//
	int				time_die;
	int				time_eat;
	int				time_sleep;
	//time variables to see die
	long			time_now; // for whole program
	long			loop_start; // for all loop
	long			action_start; // for each action, to see when it has to end
	long			time_beg_one_loop; // time loop started
	// game variables
	int				*life_status;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	on_mutex;
	pthread_mutex_t	*r_fork; //ref
	pthread_mutex_t	*messager; //ref
	pthread_mutex_t	*death; //ref
	struct s_philo	*next;
}				t_philo;

typedef struct s_all
{
	struct timeval	tv;
	int				many_philo;
	int				life_status;
	pthread_t		table;
	pthread_mutex_t	messager;
	pthread_mutex_t	death;
	t_philo			*philo;
}				t_all;

//----------program initialization
void	connect_r_fork(t_all *prog);
t_all	*init_prog_struct(int ac, char **av);
int		start_philos(t_all *prog, int ac, char **av);
void	init_philo_val(t_all *prog, t_philo *philo, t_inp_values val);
int		reading_input(t_inp_values *val, char **av, int ac);

//----------Debug Helper
void	print_philos(t_philo *philo);

//-----------Utils
size_t	get_time(void);
void	join(t_philo *philo);
int		alive(t_philo *philo);
void	detach(t_philo *philo);
void	get_forks(t_philo *philo);
void	let_forks(t_philo *philo);
int		check_only_nums(char **str);
void	clean_n_finish(t_all *prog);
int		valid_inputs(t_inp_values val, int ac);
int		life_status(int action, t_philo *philo);
void	print_message(t_philo *philo, char *message);

//-----------Philo routine
int		philo_eating(t_philo *philo);
void	philo_thinking(t_philo *philo);
int		philo_sleeping(t_philo *philo);
void	*philo_routine(void *philo_img);
void	*one_philo_routine(void *philo_img);

//-----------Sync
void	force_sync(t_philo *philo);
void	*waiting_sync(void *prog_img);
int		access_on_var(int action, t_philo *philo);

#endif
