/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:49:25 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 13:10:07 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str))
		return (FALSE);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

/*	CHECK_ARG
**	------------
**	DESCRIPTION
**	Checks the number of arguments and if they are numeric values within
**	the range from 0 to 2147483647.
**	PARAMETERS
**	#1. The number of strings pointed to by argv (argc);
**	#2. The strings pointed (argv);
**	RETURN VALUES
**	Return 0 if success and 1 if failure
*/
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
		if (!str_is_numeric(argv[i]))
		{
			put_msg_fd(ERR_TYPE_ARG, STDERR_FILENO);
			return (FAILURE);
		}
		if (ft_atol(argv[i]) < 0 || ft_atol(argv[i]) > INT_MAX)
		{
			put_msg_fd(ERR_RANGE_ARG, STDERR_FILENO);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
