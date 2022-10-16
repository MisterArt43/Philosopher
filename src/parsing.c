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

void	parsing(char **str, t_main *main)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (i == 1)
			main->nb_philo = ft_atoi(str[i]);
		else if (i == 2)
			main->t_die = ft_atoi(str[i]);
		else if (i == 3)
			main->t_eat = ft_atoi(str[i]);
		else if (i == 4)
			main->t_sleep = ft_atoi(str[i]);
		else if (i == 5)
			main->nb_eat = ft_atoi(str[i]);
		i++;
	}
}

t_philo	new_philo(int i, t_main *main)
{
	t_philo new;

	new.id = i + 1;
	new.fake_id = new.id;
	new.started = 0;
	new.mortem = 0;
	new.time_to_eat = main->t_eat;
	new.time_to_die = main->t_die;
	new.time_to_sleep = main->t_sleep;
	new.nb_philo = main->nb_philo;
	if (i == 0)
	{
		new.left_fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(new.left_fork, NULL);
	}
	else
		new.left_fork = main->philo[i - 1].right_fork;
	if (i != main->nb_philo)
	{
		new.right_fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(new.right_fork, NULL);
	}
	else
		new.right_fork = main->philo[0].left_fork;
	return (new);
}

int	make_philo(t_main *main)
{
	int				i;
	pthread_mutex_t	*write;

	write = malloc(sizeof(pthread_mutex_t));
	main->philo = malloc(sizeof(t_philo) * (main->nb_philo + 1));
	if (!main->philo)
		return (0);
	i = 0;
	while (i != main->nb_philo)
	{
		main->philo[i] = new_philo(i, main);
		main->philo[i].let_me_write = write;
		i++;
	}
	return (1);
}

void	start_exec(t_main *main)
{
	int				i;

	make_philo(main);
	i = 0;
	while (i != main->nb_philo)
	{
		pthread_create(&main->philo[i].thread, NULL, &manage_philo, &main->philo[i]);
		i++;
	}
	i = 0;
	while (i != main->nb_philo)
	{
		pthread_join(main->philo[i].thread, NULL);
		i++;
	}
	free(main->philo);
}
