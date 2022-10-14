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

#include "../incldues/header.h"

void	parsing(char **str, t_main *main)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
			main->nb_philo = ft_atoi(str[i]);
		else if (i == 1)
			main->t_die = ft_atoi(str[i]);
		else if (i == 2)
			main->t_eat = ft_atoi(str[i]);
		else if (i == 3)
			main->t_sleep = ft_atoi(str[i]);
		else if (i == 4)
			main->nb_eat = ft_atoi(str[i]);
		i++;
	}
}