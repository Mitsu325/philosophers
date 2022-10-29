/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:11:26 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 16:49:49 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		(*philo)[i].data = data;
	}
	return(SUCCESS);
}
