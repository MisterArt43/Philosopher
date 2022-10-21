/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 04:36:53 by abucia            #+#    #+#             */
/*   Updated: 2022/10/21 06:16:01 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	neg = 1;
	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * neg);
}

unsigned int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec * 0.001));
}

void	start_exec(t_main *main)
{
	int	i;

	i = -1;
	while (++i != main->nb_philo)
		pthread_create(&main->philo[i].thread, \
		NULL, &start_thread, &main->philo[i]);
	usleep(main->time_to_eat);
	i = -1;
	while (++i != main->nb_philo)
		pthread_join(main->philo[i].thread, NULL);
	i = -1;
	while (++i != main->nb_philo)
		pthread_mutex_destroy(&main->fork[i]);
	pthread_mutex_destroy(&main->are_you_dead);
	pthread_mutex_destroy(&main->let_me_write);
	free(main->philo);
	free(main->fork);
}
