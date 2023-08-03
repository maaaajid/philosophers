/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaa <aelbouaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:25:39 by aelbouaa          #+#    #+#             */
/*   Updated: 2023/08/03 23:24:35 by aelbouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosopher.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	check_arg(char **av)
{
	int	x;
	int	z;

	x = 1;
	while (av[x])
	{
		z = 0;
		while (av[x][z])
		{
			if (!ft_isdigit(av[x][z]))
			{
				if (z == 0 && av[x][z] == '+')
				{
					z++;
					continue ;
				}
				else
					return (0);
			}
			z++;
		}
		x++;
	}
	return (1);
}

long long	get_time(void)
{
	struct timeval	time;
	long long		ms;

	ms = 0;
	gettimeofday(&time, NULL);
	ms += (time.tv_sec * 1000);
	ms += (time.tv_usec / 1000);
	return (ms);
}

void	my_sleep(long long arg)
{
	long long	old;

	old = get_time();
	while (get_time() - old < arg)
		usleep(50);
}

void	print_msg(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d %s\n",
		(get_time() - philo->data->start_time), philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}
