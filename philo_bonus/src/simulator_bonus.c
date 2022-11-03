/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:28:44 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/02 23:16:12 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

/*	WAIT_ALL_PIDS
**	------------
**	DESCRIPTION
**	Wait for all child process to die.
**	PARAMETERS
**	#1. The philo struct pointer (philo);
**	RETURN VALUES
**	-
*/
static void	wait_all_pids(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->number_philo)
		waitpid(philo[i].pid, NULL, 0);
	return ;
}

/*	STOP_DINNER
**	------------
**	DESCRIPTION
**	Waits for stop semaphore to kill processes.
**	PARAMETERS
**	#1. The philo struct pointer (arg);
**	RETURN VALUES
**	Return NULL
*/
static void	*stop_dinner(void *arg)
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
**	Create process to simulate philosophers dinner.
**	PARAMETERS
**	#1. The data struct pointer (data);
**	#2. The philo struct pointer (philo);
**	RETURN VALUES
**	-
*/
void	simulator(t_data *data, t_philo *philo)
{
	pthread_t	thread;
	int			i;

	data->create_date = date_now();
	i = -1;
	while (++i < data->number_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			life_philo(&philo[i]);
			clear_memory(data, &philo, SUCCESS);
			exit(SUCCESS);
		}
	}
	pthread_create(&thread, NULL, &stop_dinner, philo);
	pthread_detach(thread);
	wait_all_pids(philo);
	return ;
}
