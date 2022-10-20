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
	print_mutex(philo, (get_time() - philo->start_time), 2);
	pass_time(philo->time_to_sleep);
}

void	time_to_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	print_mutex(philo, (get_time() - philo->start_time), 0);

	print_mutex(philo, (get_time() - philo->start_time), 1);
	pass_time(philo->time_to_eat);
	philo->time_since_eat = get_time();
	
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	pass_time(unsigned int duration)
{
	unsigned int	init;

	init = get_time() + duration;
	while (get_time() < init)
		usleep(5);
}

void	*start_thread(void *undefined)
{
	t_philo	*philo;

	philo = undefined;
	if (philo->id % 2 == 0 || (philo->id % 2 == 1 && philo->id == philo->nb_philo))
	{
		print_mutex(philo, (get_time() - philo->start_time), 3);
		usleep(60);
	}
	manage_philo(philo);
	return (NULL);
}

void	manage_philo(t_philo *philo)
{
	while (1)
	{
		time_to_eat(philo);
		time_to_sleep(philo);
		print_mutex(philo, (get_time() - philo->start_time), 3);
		pass_time(50);
	}
}
