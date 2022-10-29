/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:19:34 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 16:50:57 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*	CLEAR_MEMORY
**	------------
**	DESCRIPTION
**	Free all memory allocated.
**	PARAMETERS
**	#1. The philo struct pointed (philo);
**	#2. The return value (status);
**	RETURN VALUES
**	Return status value.
*/
int	clear_memory(t_philo **philo, int status)
{
	if (*philo)
	{
		free(*philo);
		*philo = NULL;
	}
	return (status);
}
