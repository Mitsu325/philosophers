/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:29:09 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 16:23:27 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (check_arg(argc, argv) == FAILURE)
		return (FAILURE);
	save_arg(argc, argv, &data);
	philo = NULL;
	if (init_philo(&data, &philo) == FAILURE)
		return (FAILURE);
	return (clear_memory(&philo, SUCCESS));
}
