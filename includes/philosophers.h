/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:30:26 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 16:59:16 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# define ERR_NUM_ARG "Wrong number of arguments"
# define ERR_TYPE_ARG "All arguments must be numeric"
# define ERR_RANGE_ARG "Argument with value out of range"
# define NO_PHILO "No philosophers for dinner"
# define ZERO_MUST_EAT "Number of times each philosopher should eat must be \
greater than zero"
# define PHILO_ARG "Synopsis: ./philo [number_of_philosophers] [time_to_die] \
[time_to_eat] [time_to_sleep] ([number_of_times_each_philosopher_must_eat])"

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
	int				number_must_eat;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
	int		id;
	int		l_fork;
	int		r_fork;
	t_data	*data;
}	t_philo;

int		check_arg(int argc, char **argv);
int		save_arg(int argc, char **argv, t_data *data);

int		init_forks(t_data *data);
int		init_philo(t_data *data, t_philo **philo);

int		msg_error(char *msg);

int		clear_memory(t_data *data, t_philo **philo, int status);

void	put_msg_fd(char *s, int fd);

int		ft_isdigit(int c);
long	ft_atol(const char *str);

#endif
