/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaa <aelbouaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:52:31 by aelbouaa          #+#    #+#             */
/*   Updated: 2023/07/26 11:49:06 by aelbouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <sys/time.h>
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<pthread.h>

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	s_e;
	pthread_mutex_t	c_m;
	int				time_to_e;
	int				time_to_s;
	int				time_to_d;
	int				num_philo;
	long long		start_time;
}	t_data;

typedef struct s_philo
{
	t_data		*data;
	pthread_t	threads;
	long long	start_eat;
	int			count_meal;
	int			id;
}	t_philo;

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			check_arg(char **av);
long long	get_time(void);
void		my_sleep(long long arg);
void		print_msg(t_philo *philo, char *str);

#endif
