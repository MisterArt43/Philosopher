/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:31:05 by abucia            #+#    #+#             */
/*   Updated: 2022/10/21 06:13:56 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_main	v_main;

	if (argc > 4 && argc < 7)
	{
		if (check_args(argv))
		{
			if (parsing(argv, &v_main))
				return (print_error("Error invalid format\n"));
			if (take_a_pen(&v_main))
				return (print_error("Error invalid format\n"));
			start_exec(&v_main);
		}
		else
			return (print_error("Error invalid format\n"));
	}
	else
		return (print_error("invalid argument(s), try :\n./philo <nb_philo>") \
		+ print_error("<time_to_eat> <time_to_sleep> <time_to_die>") - \
		print_error(" [nb_of_eat]\n"));
	return (EXIT_SUCCESS);
}
