/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:58:03 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 23:15:43 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

/*	EAT
**	------------
**	DESCRIPTION
**	Print the log and count the meals.
**	PARAMETERS
**	#1. The philo struct pointer (philo);
**	RETURN VALUES
**	-
*/
static void	eat(t_philo *philo)
{
	print_log(philo, EAT);
	philo->eat_counter++;
	sem_wait(philo->meals);
	philo->last_eat_date = elapsed_time(philo->data->create_date);
	sem_post(philo->meals);
	msleep(philo->data->time_eat);
}

/*	GO_SLEEP
**	------------
**	DESCRIPTION
**	Print the log and drop forks.
**	PARAMETERS
**	#1. The philo struct pointer (philo);
**	RETURN VALUES
**	-
*/
static void	go_sleep(t_philo *philo)
{
	print_log(philo, SLEEP);
	drop_fork(philo);
	msleep(philo->data->time_sleep);
}

/*	MONITOR_DINNER
**	------------
**	DESCRIPTION
**	Monitors if a philo has died.
**	PARAMETERS
**	#1. The philo struct pointer (arg);
**	RETURN VALUES
**	Return NULL
*/
static void	*monitor_dinner(void *arg)
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
void	life_philo(t_philo *philo)
{
	pthread_t	monitor;

	if (philo->id % 2 == 0)
		msleep(5);
	if (pthread_create(&monitor, NULL, &monitor_dinner, philo))
		return ;
	pthread_detach(monitor);
	if (philo->data->number_philo == 1)
		one_philo_hold_fork(philo);
	while (1)
	{
		hold_fork(philo);
		eat(philo);
		if (philo->eat_counter == philo->data->number_must_eat)
		{
			go_sleep(philo);
			return ;
		}
		go_sleep(philo);
		print_log(philo, THINK);
		msleep(philo->data->time_think);
	}
}
