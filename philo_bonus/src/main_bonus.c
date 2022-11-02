/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:55:25 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 11:08:15 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_arg(argc, argv) == FAILURE)
		return (FAILURE);
	init_data(argc, argv, &data);
	if (init_forks(&data) == FAILURE)
		return (clear_memory(&data, FAILURE));
	return (clear_memory(&data, SUCCESS));
}
