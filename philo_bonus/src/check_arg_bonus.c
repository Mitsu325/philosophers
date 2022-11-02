/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:58:47 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 09:59:01 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
	int		i;
	long	num;

	if (argc < 5 || argc > 6)
	{
		msg_error(ERR_NUM_ARG);
		return (msg_error(PHILO_ARG));
	}
	i = 0;
	while (argv[++i])
	{
		if (!str_is_numeric(argv[i]))
			return (msg_error(ERR_TYPE_ARG));
		num = ft_atol(argv[i]);
		if (num < 0 || num > INT_MAX)
			return (msg_error(ERR_RANGE_ARG));
		if (i == 1 && num == 0)
			return (msg_error(NO_PHILO));
		if (i == 5 && num == 0)
			return (msg_error(ZERO_MUST_EAT));
	}
	return (SUCCESS);
}
