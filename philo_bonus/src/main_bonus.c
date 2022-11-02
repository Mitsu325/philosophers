/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:55:25 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 19:27:35 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (check_arg(argc, argv) == FAILURE)
		return (FAILURE);
	init_data(argc, argv, &data);
	if (init_semaphore(&data) == FAILURE)
		return (FAILURE);
	philo = NULL;
	if (init_philo(&data, &philo) == FAILURE)
		return (clear_memory(&data, &philo, FAILURE));
	if (simulator(&data, philo) == FAILURE)
		return (clear_memory(&data, &philo, FAILURE));
	return (clear_memory(&data, &philo, SUCCESS));
}
