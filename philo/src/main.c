/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:29:09 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/30 16:33:42 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (check_arg(argc, argv) == FAILURE)
		return (FAILURE);
	init_data(argc, argv, &data);
	if (init_forks(&data) == FAILURE)
		return (FAILURE);
	if (init_mutex(&data) == FAILURE)
		return (FAILURE);
	philo = NULL;
	if (init_philo(&data, &philo) == FAILURE)
		return (clear_memory(&data, &philo, FAILURE));
	if (simulator(&data, philo) == FAILURE)
		return (clear_memory(&data, &philo, FAILURE));
	return (clear_memory(&data, &philo, SUCCESS));
}
