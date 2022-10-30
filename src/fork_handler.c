/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:02:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 21:03:57 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*	MIN_FORK
**	------------
**	DESCRIPTION
**	Compare the left and right forks and return smallest.
**	PARAMETERS
**	#1. The index left fork (l_fork);
**	#2. The index right fork (r_fork);
**	RETURN VALUES
**	The smaller fork.
*/
static int	min_fork(int l_fork, int r_fork)
{
	if (l_fork < r_fork)
		return (l_fork);
	return (r_fork);
}

/*	MAX_FORK
**	------------
**	DESCRIPTION
**	Compare the left and right forks and return highest.
**	PARAMETERS
**	#1. The index left fork (l_fork);
**	#2. The index right fork (r_fork);
**	RETURN VALUES
**	The biggest fork.
*/
static int	max_fork(int l_fork, int r_fork)
{
	if (l_fork > r_fork)
		return (l_fork);
	return (r_fork);
}

/*	HOLD_FORK
**	------------
**	DESCRIPTION
**	Hold the smaller fork and then the larger one.
**	PARAMETERS
**	#1. The philo struct pointed (philo);
**	RETURN VALUES
**	-
*/
void	hold_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[min_fork(philo->l_fork,
			philo->r_fork)]);
	print_log(philo, FORK);
	pthread_mutex_lock(&philo->data->forks[max_fork(philo->l_fork,
			philo->r_fork)]);
	print_log(philo, FORK);
}

/*	DROP_FORK
**	------------
**	DESCRIPTION
**	Drop the smaller fork and then the larger one.
**	PARAMETERS
**	#1. The philo struct pointed (philo);
**	RETURN VALUES
**	-
*/
void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[min_fork(philo->l_fork,
			philo->r_fork)]);
	pthread_mutex_unlock(&philo->data->forks[max_fork(philo->l_fork,
			philo->r_fork)]);
}
