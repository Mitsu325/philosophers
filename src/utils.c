/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:10:22 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 13:10:32 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*	FT_ISDIGIT
**	------------
**	DESCRIPTION
**	Checks if the character is a digit.
**	PARAMETERS
**	#1. The character (c);
**	RETURN VALUES
**	Return 1 if it is and 0 if not
*/
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

/*	FT_ATOL
**	------------
**	DESCRIPTION
**	Convert a string to a long integer value.
**	PARAMETERS
**	#1. The string to convert (str);
**	RETURN VALUES
**	Return a long integer value.
*/
long	ft_atol(const char *str)
{
	long	number;
	long	sign;

	sign = 1;
	number = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		number = (*str - '0') + (number * 10);
		str++;
	}
	return (number * sign);
}
