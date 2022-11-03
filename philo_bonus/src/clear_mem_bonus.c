/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mem_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:04:12 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 22:51:00 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

/*	CLOSE_SEMAPHORE
**	------------
**	DESCRIPTION
**	Close all semaphore.
**	PARAMETERS
**	#1. The data struct pointed (data);
**	RETURN VALUES
**	-
*/
void	close_semaphore(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->print);
	sem_close(data->stop);
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/stop");
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
	int	i;

	i = -1;
	close_semaphore(data);
	if (*philo)
	{
		while (++i < data->number_philo)
		{
			sem_close((*philo)[i].meals);
			sem_unlink((*philo)[i].name);
			free((*philo)[i].name);
		}
		free(*philo);
		*philo = NULL;
	}
	return (status);
}
