/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:07:43 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 10:08:13 by pmitsuko         ###   ########.fr       */
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
	return (SUCCESS);
}
