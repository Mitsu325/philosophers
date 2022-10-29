/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:49:25 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 12:44:17 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

/*	STR_IS_NUMERIC
**	------------
**	DESCRIPTION
**	Checks if the string is a numeric value.
**	PARAMETERS
**	#1. The string (str);
**	RETURN VALUES
**	Return 1 if it is and 0 if not
*/
static int	str_is_numeric(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

int	check_arg(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		put_msg_fd(ERR_NUM_ARG, STDERR_FILENO);
		put_msg_fd(PHILO_ARG, STDERR_FILENO);
		return (FAILURE);
	}
	i = 0;
	while (argv[++i])
	{
		if (!str_is_numeric(argv[i])) {
			put_msg_fd(ERR_TYPE_ARG, STDERR_FILENO);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
