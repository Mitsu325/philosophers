/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mem_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:04:12 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 11:10:03 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

/*	DESTROY_MUTEX
**	------------
**	DESCRIPTION
**	Destroy all mutex.
**	PARAMETERS
**	#1. The data struct pointed (data);
**	RETURN VALUES
**	-
*/
static void	close_semaphore(t_data *data)
{
	if (data->forks != NULL)
		sem_close(data->forks);
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
int	clear_memory(t_data *data, int status)
{
	close_semaphore(data);
	return (status);
}
