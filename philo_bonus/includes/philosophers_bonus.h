/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:53:37 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 10:13:55 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <limits.h>

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
}	t_data;

/*
**	check_arg.c
*/
int				check_arg(int argc, char **argv);

/*
**	init.c
*/
int				init_data(int argc, char **argv, t_data *data);

/*
**	utils.c
*/
int				ft_isdigit(int c);
long			ft_atol(const char *str);
void			put_msg_fd(char *s, int fd);
int				msg_error(char *msg);

#endif
