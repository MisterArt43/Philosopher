/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:28:18 by abucia            #+#    #+#             */
/*   Updated: 2022/10/21 06:02:37 by abucia           ###   ########lyon.fr   */
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
	unsigned int	start_time;
	unsigned int	time_since_eat;
	int				id;
	int				nb_philo;
	int				nb_eat;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*let_me_write;
	pthread_mutex_t	*did_you_miss_me;
	pthread_t		thread;
}	t_philo;

/**
 * @param nb_philo {int} nombre de philosopher
 * @param t_eat {int} temps de miam miam
 * @param t_sleep {int} temps de dodo
 * @param t_die {int} DIE POTATOES !
 * @param nb_eat {int} nombre de fois il miam miam
 * @param philo {t_philo} je pense donc je fuis
 */
typedef struct s_main
{
	int				nb_philo;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				nb_eat;
	pthread_mutex_t	let_me_write;
	pthread_mutex_t	are_you_dead;
	pthread_mutex_t	*fork;
	struct s_philo	*philo;
}	t_main;

/**
 * check if argument are valid (if they are only numeric)
 * @name check_args
 * @param {char **} argv
**/
int				check_args(char **argv);
int				ft_atoi(const char *str);
int				parsing(char **str, t_main *main);
int				take_a_pen(t_main *data);
void			start_exec(t_main *main);
//-------------------------------------------------//
void			manage_philo(t_philo *philo);
void			*start_thread(void *undefined);
unsigned int	get_time(void);
int				check_dead(t_philo *philo);
int				pass_time(unsigned int duration, t_philo *philo, int type);
void			print_mutex(t_philo *philo, unsigned int first, int type);

#endif
