/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:28:18 by abucia            #+#    #+#             */
/*   Updated: 2022/10/14 01:32:56 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				id;
	char			mortem;
}	t_philo;


typedef struct s_main
{
	int	nb_philo;
	int	t_eat;
	int	t_sleep;
	int	t_die;
	int	nb_eat;
	struct s_philo	*philo;
}	t_main;

/**
 * check if argument are valid (if they are only numeric)
 * @name check_args
 * @param {char **} argv
**/
int		check_args(char **argv);
int		ft_atoi(const char *str);
void	parsing(char **str, t_main *main);

#endif
