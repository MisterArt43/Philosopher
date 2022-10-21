/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:57:10 by abucia            #+#    #+#             */
/*   Updated: 2022/10/21 06:02:18 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	pass_time(unsigned int duration, t_philo *philo, int type)
{
	unsigned int	init;

	init = get_time() + duration;
	while (get_time() <= init)
	{
		usleep(200);
		if (type == 1 && check_dead(philo))
			return (1);
	}
	return (0);
}

int	check_dead(t_philo *philo)
{
	int	wait;

	if (philo->did_you_miss_me->__opaque[24] != 0)
		return (1);
	else if (philo->time_to_die <= get_time() - philo->time_since_eat)
	{
		if (philo->did_you_miss_me->__opaque[24] == 0)
		{
			pthread_mutex_lock(philo->did_you_miss_me);
			usleep(150);
			usleep(150);
			print_mutex(philo, get_time() - philo->start_time, 4);
		}
		return (1);
	}
	return (0);
}

void	print_mutex(t_philo *philo, unsigned int first, int type)
{
	if (type == 0)
		printf("%d %d has taken a fork\n", first, philo->id);
	else if (type == 1)
		printf("%d %d is eating\n", first, philo->id);
	else if (type == 2)
		printf("%d %d is sleeping\n", first, philo->id);
	else if (type == 3)
		printf("%d %d is thinking\n", first, philo->id);
	else if (type == 4)
		printf("%d %d died\n", first, philo->id);
}

void	*start_thread(void *undefined)
{
	t_philo	*philo;

	philo = undefined;
	if (philo->nb_eat == 0)
		return (NULL);
	if (philo->id % 2 == 0 || \
	(philo->id % 2 == 1 && \
	philo->id == philo->nb_philo))
	{
		if (philo->id == 1)
		{
			pass_time(philo->time_to_die, philo, 1);
			return (NULL);
		}
		print_mutex(philo, (get_time() - philo->start_time), 3);
		usleep(60);
	}
	manage_philo(philo);
	return (NULL);
}
