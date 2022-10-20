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

int	main(int argc, char **argv)
{
	t_main v_main;

	if (argc > 4 && argc < 7)
	{
		if (check_args(argv))
		{
			parsing(argv, &v_main);
			if (take_a_pen(&v_main) == 0)
			{
				//er
			}
			start_exec(&v_main);
			return (0);
		}
	}
	else
		printf("invalid argument(s), try :\n%s%s", \
	"./philo <nb_philo> <time_to_eat> <time_to_sleep> ", \
	"<time_to_die> [nb_of_eat]\n");
}
//todo verif si > a 0