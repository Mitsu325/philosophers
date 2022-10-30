/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:30:09 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/30 16:47:55 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*	INIT_DATA
**	------------
**	DESCRIPTION
**	Initialize values from data struct.
**	PARAMETERS
**	#1. The number of strings pointed to by argv (argc);
**	#2. The strings pointed (argv);
**	#3. The data struct pointed (data);
**	RETURN VALUES
**	Return 0 if success and 1 if failure
*/
int	init_data(int argc, char **argv, t_data *data)
{
	data->number_philo = (int)ft_atol(argv[1]);
	data->time_die = (int)ft_atol(argv[2]);
	data->time_eat = (int)ft_atol(argv[3]);
	data->time_sleep = (int)ft_atol(argv[4]);
	data->number_must_eat = -1;
	if (argc == 6)
		data->number_must_eat = (int)ft_atol(argv[5]);
	data->forks = NULL;
	data->mutex = NULL;
	data->time_think = 1 + data->time_eat - data->time_sleep;
	data->create_date = -1;
	data->end_of_dinner = FALSE;
	return (SUCCESS);
}

/*	INIT_PHILO
**	------------
**	DESCRIPTION
**	Initialize values from philo struct.
**	PARAMETERS
**	#1. The data struct pointed (data);
**	#2. The philo struct pointed (philo);
**	RETURN VALUES
**	Return 0 is success and 1 if not.
*/
int	init_philo(t_data *data, t_philo **philo)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * data->number_philo);
	if (*philo == NULL)
		return (FAILURE);
	i = -1;
	while (++i < data->number_philo)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].l_fork = i;
		if (i - 1 < 0)
			(*philo)[i].r_fork = data->number_philo - 1;
		else
			(*philo)[i].r_fork = i - 1;
		(*philo)[i].eat_counter = 0;
		(*philo)[i].last_eat_date = 0;
		(*philo)[i].data = data;
	}
	return (SUCCESS);
}

/*	INIT_FORKS
**	------------
**	DESCRIPTION
**	Initialize values from forks and mutex init.
**	PARAMETERS
**	#1. The data struct pointed (data);
**	RETURN VALUES
**	Return 0 is success and 1 if not.
*/
int	init_forks(t_data *data)
{
	int	i;

	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->number_philo);
	if (data->forks == NULL)
		return (FAILURE);
	i = -1;
	while (++i < data->number_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	return (SUCCESS);
}

/*	INIT_MUTEX
**	------------
**	DESCRIPTION
**	Initialize values from mutex and mutex init.
**	PARAMETERS
**	#1. The data struct pointed (data);
**	RETURN VALUES
**	Return 0 is success and 1 if not.
*/
int	init_mutex(t_data *data)
{
	int	i;

	data->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* NUM_MUTEX);
	if (data->mutex == NULL)
		return (FAILURE);
	i = -1;
	while (++i < NUM_MUTEX)
		pthread_mutex_init(&data->mutex[i], NULL);
	return (SUCCESS);
}
