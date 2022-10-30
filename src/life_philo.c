/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:34:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/30 11:28:27 by pmitsuko         ###   ########.fr       */
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

/*	PRINT_LOG
**	------------
**	DESCRIPTION
**	Write log in format: timestamp (ms) Philosopher id activity.
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
	pthread_mutex_lock(&philo->data->mutex[PRINT]);
	printf("%6lld %4d %s\n", elapsed_time(philo->data->create_date),
		philo->id, msg);
	pthread_mutex_unlock(&philo->data->mutex[PRINT]);
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
	while (!end_of_dinner(philo))
	{
		hold_fork(philo);
		eat(philo);
		if (get_amount_meal(philo) == philo->data->number_must_eat)
		{
			drop_fork(philo);
			return (NULL);
		}
		print_log(philo, SLEEP);
		drop_fork(philo);
		msleep(philo->data->time_sleep);
		print_log(philo, THINK);
	}
	return (NULL);
}
