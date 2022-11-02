/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:58:03 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 19:26:11 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_msg(t_philo *philo, char *msg)
{
	printf("%lld %d %s\n", elapsed_time(philo->data->create_date),
		philo->id, msg);
}

void	print_log(t_philo *philo, char *msg)
{
	sem_wait(philo->data->print);
	print_msg(philo, msg);
	sem_post(philo->data->print);
}

void	hold_fork(t_philo *philo)
{
	sem_wait(philo->data->forks);
	sem_wait(philo->data->forks);
	print_log(philo, FORK);
	print_log(philo, FORK);
}

void	drop_fork(t_philo *philo)
{
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

int	eat(t_philo *philo)
{
	print_log(philo, EAT);
	philo->eat_counter++;
	sem_wait(philo->meals);
	philo->last_eat_date = elapsed_time(philo->data->create_date);
	sem_post(philo->meals);
	msleep(philo->data->time_eat);
	return (SUCCESS);
}

void	*monitor_dinner(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->meals);
		if ((elapsed_time(philo->data->create_date)
				- philo->last_eat_date) > philo->data->time_die)
		{
			sem_wait(philo->data->print);
			print_msg(philo, DIED);
			sem_post(philo->data->stop);
			return (NULL);
		}
		sem_post(philo->meals);
		msleep(1);
	}
	return (NULL);
}

/*	LIFE_FILE
**	------------
**	DESCRIPTION
**	The life of a philo: eating, sleeping and thinking.
**	PARAMETERS
**	#1. The philo struct pointer (philo);
**	RETURN VALUES
**	-
*/
int	life_philo(t_philo *philo)
{
	pthread_t	monitor;

	if (philo->id % 2 == 0)
		msleep(5);
	if (pthread_create(&monitor, NULL, &monitor_dinner, philo))
		return (FAILURE);
	pthread_detach(monitor);
	while (1)
	{
		hold_fork(philo);
		eat(philo);
		if (philo->eat_counter == philo->data->number_must_eat)
		{
			print_log(philo, SLEEP);
			drop_fork(philo);
			msleep(philo->data->time_sleep);
			return (SUCCESS);
		}
		print_log(philo, SLEEP);
		drop_fork(philo);
		msleep(philo->data->time_sleep);
		print_log(philo, THINK);
		msleep(philo->data->time_think);
	}
	return (SUCCESS);
}
