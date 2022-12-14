/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:34:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/30 17:45:30 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	pthread_mutex_lock(&philo->data->mutex[MEALS]);
	philo->eat_counter++;
	philo->last_eat_date = elapsed_time(philo->data->create_date);
	pthread_mutex_unlock(&philo->data->mutex[MEALS]);
	msleep(philo->data->time_eat);
}

/*	END_OF_DINNER
**	------------
**	DESCRIPTION
**	Returns the end of dinner value.
**	PARAMETERS
**	#1. The philo struct pointer (philo);
**	RETURN VALUES
**	Return 1 at the end of the dinner and 0 at the continuation.
*/
static int	end_of_dinner(t_philo *philo)
{
	int	end_dinner;

	pthread_mutex_lock(&philo->data->mutex[END_DINNER]);
	end_dinner = philo->data->end_of_dinner;
	pthread_mutex_unlock(&philo->data->mutex[END_DINNER]);
	return (end_dinner);
}

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
	pthread_mutex_lock(&philo->data->mutex[PRINT]);
	printf("%lld %d %s\n", elapsed_time(philo->data->create_date),
		philo->id, msg);
	pthread_mutex_unlock(&philo->data->mutex[PRINT]);
}

/*	PRINT_LOG
**	------------
**	DESCRIPTION
**	Check the end of dinner and print the log.
**	PARAMETERS
**	#1. The philo struct pointer (philo);
**	#2. The message (msg);
**	RETURN VALUES
**	-
*/
void	print_log(t_philo *philo, char *msg)
{
	if (end_of_dinner(philo))
		return ;
	print_msg(philo, msg);
}

/*	LIFE_FILE
**	------------
**	DESCRIPTION
**	The life of a philo: eating, sleeping and thinking.
**	PARAMETERS
**	#1. The philo struct pointer (arg);
**	RETURN VALUES
**	Return NULL
*/
void	*life_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		msleep(5);
	if (philo->data->number_philo == 1)
		return (one_philo_hold_fork(philo));
	while (!end_of_dinner(philo))
	{
		hold_fork(philo);
		eat(philo);
		if (get_amount_meal(philo) == philo->data->number_must_eat)
		{
			print_log(philo, SLEEP);
			drop_fork(philo);
			msleep(philo->data->time_sleep);
			return (NULL);
		}
		print_log(philo, SLEEP);
		drop_fork(philo);
		msleep(philo->data->time_sleep);
		print_log(philo, THINK);
		msleep(philo->data->time_think);
	}
	return (NULL);
}
