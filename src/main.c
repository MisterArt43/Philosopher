/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:31:05 by abucia            #+#    #+#             */
/*   Updated: 2022/10/13 05:00:54 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	init_main(t_main *new_main)
{
	new_main->nb_philo = -1;
	new_main->t_die = -1;
	new_main->t_eat = -1;
	new_main->t_sleep = -1;
	new_main->nb_eat = -1;
}

int	main(int argc, char **argv)
{
	t_main v_main;

	init_main(&v_main);
	if (argc > 3 && argc < 6)
	{
		if (check_args(argv))
		{
			parsing(argv, &v_main);
			start_exec(&v_main);
			return (0);
		}
	}
	else
		printf("invalid argument(s), try :\n%s%s", \
	"./philo <nb_philo> <time_to_eat> <time_to_sleep> ", \
	"<time_to_die> [nb_of_eat]\n");
}
