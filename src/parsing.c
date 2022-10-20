/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 04:42:52 by abucia            #+#    #+#             */
/*   Updated: 2022/10/13 04:47:50 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	start_exec(t_main *main)
{
	int	i;

	i = 0;
	while (i != main->nb_philo)
	{
		pthread_create(&main->philo[i].thread, NULL, &start_thread, &main->philo[i]);
		i++;
	}
	usleep(main->time_to_eat);
	i = 0;
	while (i != main->nb_philo)
	{
		pthread_join(main->philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i != main->nb_philo)
	{
		pthread_mutex_destroy(&main->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&main->are_you_dead);
	pthread_mutex_destroy(&main->let_me_write);
	free(main->philo);
}

int	mutex_birth(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->nb_philo)
	{
		main->philo[i].left_fork = &(main->fork[i]);
		main->philo[i].right_fork = &(main->fork[(i + 1) % main->nb_philo]);
		main->philo[i].let_me_write = &(main->let_me_write);
		main->philo[i].did_you_miss_me = &(main->are_you_dead);
		i++;
	}
	return (0);
}

int	take_a_pen(t_main *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&(data->fork[i]), NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->let_me_write, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->are_you_dead, NULL) != 0)
		return (1);
	return (mutex_birth(data));
}

int	give_them_book(t_main *data)
{
	int		i;

	i = data->nb_philo;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * i);
	if (!data->philo)
		return (1);
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * i);
	if (!data->fork)
		return (1);
	return (0);
}

int	init_student(t_main *data)
{
	int	i;
	int	init_time;

	i = data->nb_philo;
	if (give_them_book(data))
		return (1);
	init_time = get_time();
	while (i >= 0)
	{
		i--;
		data->philo[i].id = i + 1;
		data->philo[i].time_to_die = data->time_to_die;
		data->philo[i].time_to_eat = data->time_to_eat;
		data->philo[i].time_to_sleep = data->time_to_sleep;
		data->philo[i].nb_eat = data->nb_eat;
		data->philo[i].nb_philo = data->nb_philo;
		data->philo[i].start_time = init_time;
		data->philo[i].time_since_eat = data->philo[i].start_time;
		//dead stuff init here
	}
	return (0);
}

int	parsing(char **str, t_main *main)
{
	main->nb_philo = ft_atoi(str[1]);
	main->time_to_die = ft_atoi(str[2]);
	main->time_to_eat = ft_atoi(str[3]);
	main->time_to_sleep = ft_atoi(str[4]);
	if (str[5])
		main->nb_eat = ft_atoi(str[5]);
	else
		main->nb_eat = -1;
	//main->everyone_ate = 0;
	//main->are_you_dead
	return (init_student(main));
}
