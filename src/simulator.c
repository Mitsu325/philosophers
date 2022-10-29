/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:36:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/10/29 19:20:01 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_log(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->mutex[PRINT]);
	printf("Philosopher %d %s\n", philo->id, msg);
	pthread_mutex_unlock(&philo->data->mutex[PRINT]);
}

int	min_fork(int l_fork, int r_fork)
{
	if (l_fork < r_fork)
		return (l_fork);
	return (r_fork);
}

int	max_fork(int l_fork, int r_fork)
{
	if (l_fork > r_fork)
		return (l_fork);
	return (r_fork);
}

void	hold_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[min_fork(philo->l_fork, philo->r_fork)]);
	print_log(philo, FORK);
	pthread_mutex_lock(&philo->data->forks[max_fork(philo->l_fork, philo->r_fork)]);
	print_log(philo, FORK);
}

void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[min_fork(philo->l_fork, philo->r_fork)]);
	pthread_mutex_unlock(&philo->data->forks[max_fork(philo->l_fork, philo->r_fork)]);
}

void	*life_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(500);
	hold_fork(philo);
	print_log(philo, EAT);
	print_log(philo, SLEEP);
	drop_fork(philo);
	print_log(philo, THINK);
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
