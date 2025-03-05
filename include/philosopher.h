#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

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

# define SUCCESS 0
# define ERROR 1

/* # define FORK_M "has taken a fork"
# define DEAD_M "died"
# define EATING_M "is eating"
# define SLEEPING_M "is sleeping"
# define THINKING_M "is thinking"*/


# define FORK_M "has taken a fork	🍴"
# define DEAD_M "died			💀"
# define EATING_M "is eating		🍅"
# define SLEEPING_M "is sleeping	💤"
# define THINKING_M "is thinking	🤔"

/// @brief Struct that will hold all the users inputs
typedef struct	s_inp_values
{
	int				many_philo;
	int				phl_num;
	int				max_eat;
	int				time_die;
	int				time_eat;
	int				time_sleep;
}				t_inp_values;

typedef struct	s_philo
{
	// philosopher characteristics
	int				eaten;
	int				phl_num;
	int				max_eat;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	//time variables to see die
	long			time_now; // for whole program
	long			loop_start; // for all loop
	long			action_start; // for each action, to see when it has to end
	long			time_beg_one_loop; // to see throught out the action when he is going to die!
	// game variables
	int				*life_status;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*messager;
	struct s_philo	*next;
}				t_philo;

typedef struct	s_all
{
	struct timeval	tv;
	int				many_philo;
	int				life_status;
	pthread_mutex_t	*table;
	pthread_mutex_t	messager;
	t_philo			*philo;
}				t_all;

//----------program initialization
void	connect_r_fork(t_all *prog);
t_all	*init_prog_struct(int ac, char **av);
int	start_philos(t_all *prog, int ac, char **av);
void	init_philo_val(t_all *prog, t_philo *philo, t_inp_values val);
int		reading_input(t_inp_values *val, char **av, int ac);

//----------Debug Helper
void	printPhilos(t_philo *philo);

//-----------Utils

size_t	get_time(void);
void	join_even(t_philo *philo);
void	join_odds(t_philo *philo);
int		check_only_nums(char **str);
void	clean_n_finish(t_all *prog);
int		valid_inputs(t_inp_values val, int ac);
void	print_message(t_philo *philo ,char *message);

//-----------Philo routine

void	philo_eating(t_philo *philo);
void	philo_thinking(t_philo *philo);
void	philo_sleeping(t_philo *philo);
void	*philo_routine(void *philo_img);
void	*one_philo_routine(void *philo_img);

#endif
