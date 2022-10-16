/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 05:01:30 by abucia            #+#    #+#             */
/*   Updated: 2022/10/14 05:58:13 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	time_to_sleep(t_philo *philo)
{
	printf("%d %d is slseeping\n", get_time() - philo->start_time, philo->id);
	pass_time((unsigned int)philo->time_to_sleep);
	printf("%d %d is thinking\n", get_time() - philo->start_time, philo->id);
}

void	time_to_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("%d %d has taken a fork\n", get_time() - philo->start_time, philo->id);
	pthread_mutex_lock(philo->right_fork);
	printf("%d %d has taken a fork\n", get_time() - philo->start_time, philo->id);
	printf("%d %d is eating\n", get_time() - philo->start_time, philo->id);
	pass_time((unsigned int)philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	pass_time(unsigned int duration)
{
	unsigned int	init;

	init = get_time() + duration;
	while (get_time() < init)
		usleep(10);
}

void	*manage_philo(void *idk)
{
	t_philo	*philo;

	philo = idk;
	while (1)
	{
		if (philo->started == 0)
		{
			philo->start_time = get_time();
			philo->started = 1;
		}
		if (philo->id % 2 == 1 && philo->id != philo->nb_philo + 1)
		{
			time_to_eat(philo);
			philo->fake_id++;
			if (philo->fake_id == philo->nb_philo)
				philo->fake_id = 1;
			time_to_sleep(philo);
		}
		else
		{
			printf("%d %d is thinking\n", get_time() - philo->start_time, philo->id);
			pass_time(philo->time_to_eat);
			philo->fake_id++;
			if (philo->fake_id == philo->nb_philo)
				philo->fake_id = 1;
		}
	}
}
