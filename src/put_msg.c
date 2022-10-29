/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:10:15 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 12:22:09 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*	PUT_MSG_FD
**	------------
**	DESCRIPTION
**	Write message to the file descriptor and break line.
**	PARAMETERS
**	#1. The output message (msg);
**	#2. The file descriptor (fd);
**	RETURN VALUES
**	-
*/
void	put_msg_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
