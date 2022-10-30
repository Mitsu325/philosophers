/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_dinner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:37:57 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/30 15:00:54 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*	GET_AMOUNT_MEAL
**	------------
**	DESCRIPTION
**	Returns a philo's eat counter.
**	PARAMETERS
**	#1. The philo struct pointer (philo);
**	RETURN VALUES
**	Return the eat counter.
*/
int	get_amount_meal(t_philo *philo)
{
	int	amount_meal;

	pthread_mutex_lock(&philo->data->mutex[MEALS]);
	amount_meal = philo->eat_counter;
	pthread_mutex_unlock(&philo->data->mutex[MEALS]);
	return (amount_meal);
}

/*	ALL_PHILO_ATE
**	------------
**	DESCRIPTION
**	Check all philo ate at least the number of times must eat.
**	PARAMETERS
**	#1. The philo struct pointer (philo);
**	RETURN VALUES
**	Return 1 if everyone ate and 0 if not.
*/
static int	all_philo_ate(t_philo *philo)
{
	int	i;
	int	philo_ate;

	if (philo->data->number_must_eat < 0)
		return (FALSE);
	i = -1;
	philo_ate = 0;
	while (++i < philo->data->number_philo)
	{
		if (get_amount_meal(&philo[i]) == philo->data->number_must_eat)
			philo_ate++;
	}
	if (philo_ate == philo->data->number_philo)
		return (TRUE);
	return (FALSE);
}

long long int	get_last_meal_time(t_philo *philo)
{
	long long int	last_meal_time;

	pthread_mutex_lock(&philo->data->mutex[MEALS]);
	last_meal_time = philo->last_eat_date;
	pthread_mutex_unlock(&philo->data->mutex[MEALS]);
	return (last_meal_time);
}

int	check_philo_die(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->number_philo)
	{
		if ((elapsed_time(philo->data->create_date) - get_last_meal_time(&philo[i])) > philo->data->time_die)
		{
			pthread_mutex_lock(&philo->data->mutex[END_DINNER]);
			philo->data->end_of_dinner = TRUE;
			pthread_mutex_unlock(&philo->data->mutex[END_DINNER]);
			print_msg(&philo[i], DIED);
			return (TRUE);
		}
	}
	return (FALSE);
}

/*	MONITOR_DINNER
**	------------
**	DESCRIPTION
**	Monitors if all philo ate at least the number of times must eat.
**	PARAMETERS
**	#1. The philo struct pointer (arg);
**	RETURN VALUES
**	Return NULL
*/
void	*monitor_dinner(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!all_philo_ate(philo))
	{
		if (check_philo_die(philo))
			return (NULL);
	}
	return (NULL);
}
