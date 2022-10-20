/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 04:36:53 by abucia            #+#    #+#             */
/*   Updated: 2022/10/13 04:39:10 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	ft_atoi(const char *str)
{
	int i;
	int neg;
	int res;

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

void	print_mutex(t_philo *philo, unsigned int first, int type)
{
	pthread_mutex_lock(philo->let_me_write);
	if (type == 0)
		printf("%d %d has taken a fork\n%d %d has taken a fork\n", first, philo->id, first, philo->id);
	else if (type == 1)
		printf("%d %d is eating\n", first, philo->id);
	else if (type == 2)
		printf("%d %d is sleeping\n", first, philo->id);
	else if (type == 3)
		printf("%d %d is thinking\n", first, philo->id);
	else if (type == 4)
		printf("%d %d is dead\n", first, philo->id);
	pthread_mutex_unlock(philo->let_me_write);
}
