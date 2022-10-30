/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:36:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 21:08:48 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*	PRINT_LOG
**	------------
**	DESCRIPTION
**	Write log in format: timestamp (ms) Philosopher id activity.
**	PARAMETERS
**	#1. The philo struct pointer (philo);
**	#2. The message (msg);
**	RETURN VALUES
**	-
*/
void	print_log(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->mutex[PRINT]);
	printf("%lld Philosopher %d %s\n", elapsed_time(philo->data->create_date),
		philo->id, msg);
	pthread_mutex_unlock(&philo->data->mutex[PRINT]);
}

/*	LIFE_FILE
**	------------
**	DESCRIPTION
**	The life of a philo: eating, sleeping and thinking.
**	PARAMETERS
**	#1. The philo struct pointer (arg);
**	RETURN VALUES
**	Return NULL
*/
void	*life_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		msleep(5);
	hold_fork(philo);
	print_log(philo, EAT);
	msleep(philo->data->time_eat);
	print_log(philo, SLEEP);
	drop_fork(philo);
	msleep(philo->data->time_sleep);
	print_log(philo, THINK);
	return (NULL);
}

/*	SIMULATOR
**	------------
**	DESCRIPTION
**	Thread creation to simulate philosophers dinner.
**	PARAMETERS
**	#1. The data struct pointer (data);
**	#2. The philo struct pointer (philo);
**	RETURN VALUES
**	Return 0 if success and 0 if not.
*/
int	simulator(t_data *data, t_philo *philo)
{
	pthread_t	*thread;
	int			i;

	data->create_date = date_now();
	thread = (pthread_t *)malloc(sizeof(pthread_t) * data->number_philo);
	if (thread == NULL)
		return (FAILURE);
	i = -1;
	while (++i < data->number_philo)
	{
		if (pthread_create(&thread[i], NULL, &life_philo, &philo[i]))
			return (free(thread), FAILURE);
	}
	i = -1;
	while (++i < data->number_philo)
	{
		if (pthread_join(thread[i], NULL))
			return (free(thread), FAILURE);
	}
	return (free(thread), SUCCESS);
}
