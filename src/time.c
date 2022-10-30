/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:00:35 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 21:18:33 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*	DATE_NOW
**	------------
**	DESCRIPTION
**	Current date in milliseconds in timestamp format.
**	PARAMETERS
**	-
**	RETURN VALUES
**	Return current date in milliseconds
*/
long long int	date_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/*	ELAPSED_TIME
**	------------
**	DESCRIPTION
**	Calculates the time that has elapsed since the beginning of the philo's
**	dinner.
**	PARAMETERS
**	#1. time that dinner started (start_time);
**	RETURN VALUES
**	Return relative timestamp in milliseconds.
*/
long long int	elapsed_time(long long int start_time)
{
	return ((date_now() - start_time));
}

/*	MSLEEP
**	------------
**	DESCRIPTION
**	Suspend execution for milliseconds intervals.
**	PARAMETERS
**	#1. the time in milliseconds (time_in_ms);
**	RETURN VALUES
**	Return 0 on success and -1 on error.
*/
int	msleep(long long int time_in_ms)
{
	return (usleep(time_in_ms * 1000));
}
