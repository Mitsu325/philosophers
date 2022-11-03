/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:07:43 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 23:16:06 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
	data->time_think = 1 + data->time_eat - data->time_sleep;
	data->create_date = -1;
	data->forks = NULL;
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
		(*philo)[i].name = ft_itoa(i);
		(*philo)[i].eat_counter = 0;
		(*philo)[i].last_eat_date = 0;
		sem_unlink((*philo)[i].name);
		(*philo)[i].meals = sem_open((*philo)[i].name, O_CREAT, 0777, 1);
		if ((*philo)[i].meals == SEM_FAILED)
		{
			put_msg_fd("Failed to open semaphore", 2);
			return (FAILURE);
		}
		(*philo)[i].data = data;
	}
	return (SUCCESS);
}

/*	INIT_FORKS
**	------------
**	DESCRIPTION
**	Initialize values from forks and semaphore open.
**	PARAMETERS
**	#1. The data struct pointed (data);
**	RETURN VALUES
**	Return 0 is success and 1 if not.
*/
int	init_semaphore(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/stop");
	data->forks = sem_open("/forks", O_CREAT, 0777, data->number_philo);
	data->print = sem_open("/print", O_CREAT, 0777, 1);
	data->stop = sem_open("/stop", O_CREAT, 0777, 0);
	if (data->forks == SEM_FAILED || data->print == SEM_FAILED
		|| data->stop == SEM_FAILED)
	{
		put_msg_fd("Failed to open semaphore", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}
