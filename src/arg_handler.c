/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:51:03 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/30 15:19:15 by pmitsuko         ###   ########.fr       */
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

/*	SAVE_ARG
**	------------
**	DESCRIPTION
**
**	PARAMETERS
**	#1. The number of strings pointed to by argv (argc);
**	#2. The strings pointed (argv);
**	#3. The data struct pointed (data);
**	RETURN VALUES
**	Return 0 if success and 1 if failure
*/
int	save_arg(int argc, char **argv, t_data *data)
{
	data->number_philo = (int)ft_atol(argv[1]);
	data->time_die = (int)ft_atol(argv[2]);
	data->time_eat = (int)ft_atol(argv[3]);
	data->time_sleep = (int)ft_atol(argv[4]);
	data->number_must_eat = -1;
	if (argc == 6)
		data->number_must_eat = (int)ft_atol(argv[5]);
	data->forks = NULL;
	data->mutex = NULL;
	data->time_think = 1 + data->time_eat - data->time_sleep;
	data->create_date = -1;
	data->end_of_dinner = FALSE;
	return (SUCCESS);
}
