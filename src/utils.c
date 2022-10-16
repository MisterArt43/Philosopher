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

void	ft_putnbr_fd(int nb, int fd)
{
	char c;

	if (fd >= 0)
	{
		if (nb < 0)
		{
			if (nb == -2147483648)
				write(fd, "-2147483648", 11);
			else
			{
				write(fd, "-", 1);
				ft_putnbr_fd(nb * -1, fd);
			}
		}
		else
		{
			if (nb > 9)
				ft_putnbr_fd(nb / 10, fd);
			c = nb % 10 + '0';
			write(fd, &c, 1);
		}
	}
}

unsigned int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec * 0.001));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_mutex(t_philo *philo, char *msg, int first, int second)
{
	pthread_mutex_lock(philo->let_me_write);
	ft_putnbr_fd(first, 1);
	write(1, " ", 1);
	ft_putnbr_fd(second, 1);
	write(1, msg, ft_strlen(msg));
	pthread_mutex_unlock(philo->let_me_write);
}
