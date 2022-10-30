/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:36:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/30 11:03:09 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	pthread_t	monitor;
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
	if (pthread_create(&monitor, NULL, &monitor_dinner, philo))
		return (free(thread), FAILURE);
	i = -1;
	while (++i < data->number_philo)
	{
		if (pthread_join(thread[i], NULL))
			return (free(thread), FAILURE);
	}
	pthread_join(monitor, NULL);
	return (free(thread), SUCCESS);
}
