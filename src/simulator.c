/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:36:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 18:31:07 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_log(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->mutex[PRINT]);
	printf("Philosopher %d %s\n", philo->id, msg);
	pthread_mutex_unlock(&philo->data->mutex[PRINT]);
}

void	*life_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_log(philo, "think");
	return (NULL);
}

int	simulator(t_data *data, t_philo *philo)
{
	pthread_t	*thread;
	int			i;

	thread = (pthread_t *)malloc(sizeof(pthread_t) * data->number_philo);
	if (thread == NULL)
		return (FAILURE);
	i = -1;
	while (++i < data->number_philo)
	{
		if (pthread_create(&thread[i], NULL, &life_philo, &philo[i]))
			return (free(thread), FAILURE);
	}
	i = -1;
	while (++i < data->number_philo)
	{
		if (pthread_join(thread[i], NULL))
			return (free(thread), FAILURE);
	}
	return (free(thread), SUCCESS);
}
