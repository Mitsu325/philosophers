/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:19:34 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 18:30:45 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*	DESTROY_MUTEX
**	------------
**	DESCRIPTION
**	Destroy all mutex.
**	PARAMETERS
**	#1. The data struct pointed (data);
**	RETURN VALUES
**	-
*/
static void	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_philo)
		pthread_mutex_destroy(&data->forks[i]);
	i = -1;
	while (++i < NUM_MUTEX)
		pthread_mutex_destroy(&data->mutex[i]);
}

/*	CLEAR_MEMORY
**	------------
**	DESCRIPTION
**	Free all memory allocated.
**	PARAMETERS
**	#1. The data struct pointed (data);
**	#2. The philo struct pointed (philo);
**	#3. The return value (status);
**	RETURN VALUES
**	Return status value.
*/
int	clear_memory(t_data *data, t_philo **philo, int status)
{
	if (*philo)
	{
		free(*philo);
		*philo = NULL;
	}
	destroy_mutex(data);
	if (data->forks)
	{
		free(data->forks);
		data->forks = NULL;
	}
	if (data->mutex)
	{
		free(data->mutex);
		data->mutex = NULL;
	}
	return (status);
}
