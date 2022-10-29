/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:49:25 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 12:28:54 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		put_msg_fd(ERR_NUM_ARG, STDERR_FILENO);
		put_msg_fd(PHILO_ARG, STDERR_FILENO);
		return (FAILURE);
	}
	(void)argv;
	return (SUCCESS);
}
