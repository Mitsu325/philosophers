/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_philo_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:01:54 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 23:08:04 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

/*	PRINT_MSG
**	------------
**	DESCRIPTION
**	Write in format: timestamp (ms) Philosopher id activity.
**	PARAMETERS
**	#1. The philo struct pointer (philo);
**	#2. The message (msg);
**	RETURN VALUES
**	-
*/
void	print_msg(t_philo *philo, char *msg)
{
	printf("%lld %d %s\n", elapsed_time(philo->data->create_date),
		philo->id, msg);
}

/*	PRINT_LOG
**	------------
**	DESCRIPTION
**	Print the log.
**	PARAMETERS
**	#1. The philo struct pointer (philo);
**	#2. The message (msg);
**	RETURN VALUES
**	-
*/
void	print_log(t_philo *philo, char *msg)
{
	sem_wait(philo->data->print);
	print_msg(philo, msg);
	sem_post(philo->data->print);
}

/*	HOLD_FORK
**	------------
**	DESCRIPTION
**	Hold the two forks.
**	PARAMETERS
**	#1. The philo struct pointed (philo);
**	RETURN VALUES
**	-
*/
void	hold_fork(t_philo *philo)
{
	sem_wait(philo->data->forks);
	sem_wait(philo->data->forks);
	print_log(philo, FORK);
	print_log(philo, FORK);
}

/*	ONE_PHILO_HOLD_FORK
**	------------
**	DESCRIPTION
**	Hold the one fork.
**	PARAMETERS
**	#1. The philo struct pointed (philo);
**	RETURN VALUES
**	-
*/
void	one_philo_hold_fork(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print_log(philo, FORK);
}

/*	DROP_FORK
**	------------
**	DESCRIPTION
**	Drop the two forks.
**	PARAMETERS
**	#1. The philo struct pointed (philo);
**	RETURN VALUES
**	-
*/
void	drop_fork(t_philo *philo)
{
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}
