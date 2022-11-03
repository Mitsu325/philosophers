/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:10:35 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 23:10:35 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static char	*n_convert(char *str,
						size_t size,
						unsigned int num,
						unsigned int is_negative)
{
	str[size] = '\0';
	while (size--)
	{
		str[size] = (num % 10) + 48;
		num /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}

static size_t	nb_size(int num)
{
	size_t	len;

	len = 1;
	if (num < 0)
		len++;
	num /= 10;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

/*	FT_ITOA
**	------------
**	DESCRIPTION
**	Convert a int to a string.
**	PARAMETERS
**	#1. The integer to convert (n);
**	RETURN VALUES
**	Return a string.
*/
char	*ft_itoa(int n)
{
	size_t			n_digits;
	unsigned int	is_negative;
	char			*str;

	n_digits = nb_size(n);
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	str = malloc(sizeof(char) * (n_digits + 1));
	if (str == NULL)
		return (NULL);
	return (n_convert(str, n_digits, (unsigned int)n, is_negative));
}
