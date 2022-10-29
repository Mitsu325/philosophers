/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:53:39 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 17:27:20 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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