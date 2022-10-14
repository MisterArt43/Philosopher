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

#include "../incldues/header.h"

void	manage_philo(void *idk, t_philo philo)
{
	if ()
}

void	think()
{
	
}

void	eat(int time, t_philo *philo)
{
	
}

t_philo	new_philo(int i, t_main *main)
{
	t_philo new;
	int		j;

	j = 0;
	new.id = i + 1;
	new.mortem = 0;
	if (i == 0)
		pthread_mutex_init(&new.left_fork, NULL);
	else
		new.left_fork = main->philo[i - 1].right_fork;
	if (i != main->nb_philo)
		pthread_mutex_init(&new.right_fork, NULL);
	else
		new.right_fork = main->philo[0].left_fork;
	return (new);
}

int	make_philo(t_main *main)
{
	int	i;

	main->philo = malloc(sizeof(t_philo) * (main->nb_philo + 1));
	if (!main->philo)
		return ;
	i = 0;
	while (i != main->nb_philo)
	{
		main->philo[i] = new_philo(i, main);
		i++;
	}
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
}

void	start_exec(t_main *main)
{
	make_philo(main);
}