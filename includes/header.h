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
# include <sys/time.h>
# include <time.h>
# include <stdlib.h>

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*let_me_write;
	unsigned int	start_time;
	unsigned int	time_since_eat;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				started;
	int				id;
	int				nb_philo;
	int				fake_id;
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
int				check_args(char **argv);
int				ft_atoi(const char *str);
void			parsing(char **str, t_main *main);
void			start_exec(t_main *main);
void			*manage_philo(void *idk);
unsigned int	get_time(void);
void			pass_time(unsigned int duration);

#endif
