/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:37:07 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 15:39:37 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*	MSG_ERROR
**	------------
**	DESCRIPTION
**	Write message to the standard error file descriptor.
**	PARAMETERS
**	#1. The output message (msg);
**	RETURN VALUES
**	Return 1.
*/
int	msg_error(char *msg)
{
	put_msg_fd(msg, STDERR_FILENO);
	return (FAILURE);
}
