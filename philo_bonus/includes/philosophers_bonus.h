/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:53:37 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 23:16:23 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <limits.h>
# include <fcntl.h>
# include <signal.h>

# define ERR_NUM_ARG "Wrong number of arguments"
# define ERR_TYPE_ARG "All arguments must be numeric"
# define ERR_RANGE_ARG "Argument with value out of range"
# define NO_PHILO "No philosophers for dinner"
# define ZERO_MUST_EAT "Number of times each philosopher should eat must be \
greater than zero"
# define PHILO_ARG "Synopsis: ./philo [number_of_philosophers] [time_to_die] \
[time_to_eat] [time_to_sleep] ([number_of_times_each_philosopher_must_eat])"
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

typedef enum e_exit
{
	SUCCESS,
	FAILURE
}	t_exit;

typedef enum e_boolean
{
	FALSE,
	TRUE
}	t_boolean;

typedef struct s_data
{
	int				number_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_think;
	int				number_must_eat;
	long long int	create_date;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*stop;
}	t_data;

typedef struct s_philo
{
	int				id;
	char			*name;
	pid_t			pid;
	int				eat_counter;
	sem_t			*meals;
	long long int	last_eat_date;
	t_data			*data;
}	t_philo;

/*
**	check_arg_bonus.c
*/
int				check_arg(int argc, char **argv);

/*
**	init_bonus.c
*/
int				init_data(int argc, char **argv, t_data *data);
int				init_philo(t_data *data, t_philo **philo);
int				init_semaphore(t_data *data);

/*
**	simulator_bonus.c
*/
void			simulator(t_data *data, t_philo *philo);

/*
**	life_philo_bonus.c
*/
void			life_philo(t_philo *philo);

/*
**	life_philo_utils_bonus.c
*/
void			print_msg(t_philo *philo, char *msg);
void			print_log(t_philo *philo, char *msg);
void			hold_fork(t_philo *philo);
void			one_philo_hold_fork(t_philo *philo);
void			drop_fork(t_philo *philo);

/*
**	time_bonus.c
*/
long long int	date_now(void);
long long int	elapsed_time(long long int start_time);
int				msleep(long long int time_in_ms);

/*
**	clear_mem_bonus.c
*/
int				clear_memory(t_data *data, t_philo **philo, int status);

/*
**	utils_bonus.c
*/
int				ft_isdigit(int c);
long			ft_atol(const char *str);
void			put_msg_fd(char *s, int fd);
int				msg_error(char *msg);

/*
**	itoa_bonus.c
*/
char			*ft_itoa(int n);

#endif
