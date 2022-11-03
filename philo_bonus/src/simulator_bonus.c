/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:28:44 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 21:57:18 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	wait_all_pids(t_philo *philo, int id)
{
	int	i;

	i = -1;
	while (++i < id)
	{
		waitpid(philo[i].pid, NULL, 0);
	}
	return ;
}

void	*stop_dinner(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	sem_wait(philo->data->stop);
	i = 0;
	while (i < philo->data->number_philo)
		kill(philo[i++].pid, SIGKILL);
	return (NULL);
}


/*	SIMULATOR
**	------------
**	DESCRIPTION
**	.
**	PARAMETERS
**	#1. The data struct pointer (data);
**	#2. The philo struct pointer (philo);
**	RETURN VALUES
**	Return 0 if success and 0 if not.
*/
int	simulator(t_data *data, t_philo *philo)
{
	int	i;
	int	exit_code;
	pthread_t	thread;

	data->create_date = date_now();
	i = -1;
	while (++i < data->number_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			exit_code = life_philo(&philo[i]);
			clear_memory(data, &philo, SUCCESS);
			exit(exit_code);
		}
	}
	pthread_create(&thread, NULL, &stop_dinner, philo);
	pthread_detach(thread);
	wait_all_pids(philo, i);
	return (SUCCESS);
}
