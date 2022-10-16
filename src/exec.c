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
	print_mutex(philo, " is sleeping\n", get_time() - philo->start_time, philo->id);
	pass_time((unsigned int)philo->time_to_sleep);
}

void	time_to_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_mutex(philo, " has taken a fork\n", get_time() - philo->start_time, philo->id);
	pthread_mutex_lock(philo->right_fork);
	print_mutex(philo, " has taken a fork\n", get_time() - philo->start_time, philo->id);
	print_mutex(philo, " is eating\n", get_time() - philo->start_time, philo->id);
	pass_time((unsigned int)philo->time_to_eat);
	philo->time_since_eat = get_time();
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	pass_time(unsigned int duration)
{
	unsigned int	init;

	init = get_time() + duration;
	while (get_time() < init)
		usleep(1);
}

void	*manage_philo(void *idk)
{
	t_philo	*philo;

	philo = idk;
	philo->has_thinked = 0;
	philo->start_time = get_time();
	if (philo->fake_id == philo->nb_philo)
		print_mutex(philo, " is thinking\n", get_time() - philo->start_time, philo->id);
	//print_mutex(philo, " is thinking\n", get_time() - philo->start_time, philo->id);//debug start
	while (1)
	{
		if (philo->fake_id % 2 == 1 && philo->fake_id != philo->nb_philo)
		{
			time_to_eat(philo);
			philo->fake_id++;
			if (philo->fake_id == philo->nb_philo)
				philo->fake_id = 1;
			time_to_sleep(philo);
			philo->has_thinked = 0;
		}
		else if (philo->has_thinked == 0 || philo->fake_id == philo->nb_philo)
		{
			philo->has_thinked = 1;
			if (!(philo->fake_id == philo->nb_philo))
			{
				print_mutex(philo, " is thinking\n", get_time() - philo->start_time, philo->id);
				pass_time(1);
			}
			philo->fake_id++;
			if (philo->fake_id > philo->nb_philo)
			{
				//print_mutex(philo, "DEBUG LAST IS :\n", philo->fake_id, philo->id);
				pass_time(philo->time_to_eat - 1);
				philo->fake_id = 1;
			}
		}
	}
}
