/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:30:26 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 13:01:27 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <limits.h>

# define ERR_NUM_ARG "Wrong number of arguments"
# define ERR_TYPE_ARG "All arguments must be numeric"
# define ERR_RANGE_ARG "Argument with value out of range"
# define PHILO_ARG "Synopsis: ./philo [number_of_philosophers] [time_to_die]\
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
	int	number_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	number_must_eat;
}	t_data;

int		check_arg(int argc, char **argv);
void	put_msg_fd(char *s, int fd);
int		ft_isdigit(int c);
long	ft_atol(const char *str);

#endif
