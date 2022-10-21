/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 05:01:30 by abucia            #+#    #+#             */
/*   Updated: 2022/10/21 06:04:10 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	time_to_sleep(t_philo *philo)
{
	print_mutex(philo, (get_time() - philo->start_time), 2);
	if (pass_time(philo->time_to_sleep, philo, 1))
		return (1);
	return (0);
}

int	take_fork(t_philo *philo)
{
	if (check_dead(philo))
		return (1);
	pthread_mutex_lock(philo->right_fork);
	if (check_dead(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	print_mutex(philo, (get_time() - philo->start_time), 0);
	pthread_mutex_lock(philo->left_fork);
	if (check_dead(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	print_mutex(philo, (get_time() - philo->start_time), 0);
	return (0);
}

int	time_to_eat(t_philo *philo)
{
	if (take_fork(philo))
		return (1);
	print_mutex(philo, (get_time() - philo->start_time), 1);
	if (philo->nb_eat > 0)
		philo->nb_eat--;
	if (pass_time(philo->time_to_eat, philo, 1) || philo->nb_eat == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	philo->time_since_eat = get_time();
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

void	manage_philo(t_philo *philo)
{
	while (1)
	{
		if (time_to_eat(philo))
			return ;
		if (time_to_sleep(philo))
			return ;
		print_mutex(philo, (get_time() - philo->start_time), 3);
		if (pass_time(2, philo, 1))
			return ;
	}
}
