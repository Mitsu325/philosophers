/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:55:25 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 22:52:39 by pmitsuko         ###   ########.fr       */
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
	philo = NULL;
	if (init_semaphore(&data) == FAILURE)
		return (clear_memory(&data, &philo, FAILURE));
	if (init_philo(&data, &philo) == FAILURE)
		return (clear_memory(&data, &philo, FAILURE));
	simulator(&data, philo);
	return (clear_memory(&data, &philo, SUCCESS));
}
