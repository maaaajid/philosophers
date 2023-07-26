/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaa <aelbouaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:50:34 by aelbouaa          #+#    #+#             */
/*   Updated: 2023/07/26 11:43:13 by aelbouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1 && p->count_meal)
	{
		pthread_mutex_lock(&p->data->forks[p->id - 1]);
		print_msg(p, "has taken the left fork");
		pthread_mutex_lock(&p->data->forks[p->id % p->data->num_philo]);
		print_msg(p, "has taken the right fork");
		print_msg(p, "is eating");
		pthread_mutex_lock(&p->data->s_e);
		p->start_eat = get_time();
		pthread_mutex_unlock(&p->data->s_e);
		my_sleep(p->data->time_to_e);
		pthread_mutex_unlock(&p->data->forks[p->id % p->data->num_philo]);
		pthread_mutex_unlock(&p->data->forks[p->id - 1]);
		pthread_mutex_lock(&p->data->c_m);
		p->count_meal--;
		pthread_mutex_unlock(&p->data->c_m);
		print_msg(p, "is sleeping");
		my_sleep(p->data->time_to_s);
		print_msg(p, "is thinking");
	}
	return (NULL);
}

void	data_init(t_philo *philo, t_data *data, char **av)
{
	int	x;

	x = 0;
	data->num_philo = ft_atoi(av[1]);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	data->time_to_d = ft_atoi(av[2]);
	data->time_to_e = ft_atoi(av[3]);
	data->time_to_s = ft_atoi(av[4]);
	data->start_time = get_time();
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->s_e, NULL);
	pthread_mutex_init(&data->c_m, NULL);
	while (x < data->num_philo)
	{
		philo[x].start_eat = get_time();
		philo[x].id = x + 1;
		philo[x].data = data;
		pthread_mutex_init(&data->forks[x], NULL);
		philo[x].count_meal = -1;
		if (av[5])
			philo[x].count_meal = ft_atoi(av[5]);
		x++;
	}
}

int	is_dead(t_philo *philo)
{
	int	x;

	x = 0;
	pthread_mutex_lock(&philo->data->s_e);
	while (x < philo->data->num_philo)
	{
		if (get_time() - philo->start_eat >= philo->data->time_to_d)
		{
			x = -1;
			pthread_mutex_lock(&philo->data->c_m);
			while (philo[++x].count_meal == 0)
			{
				if (x == philo->data->num_philo - 1)
					return (1);
			}
			pthread_mutex_lock(&philo->data->print);
			printf("%lld %d %s\n",
				(get_time() - philo->data->start_time), philo->id, "is dead");
			return (1);
		}
		x++;
	}
	pthread_mutex_unlock(&philo->data->s_e);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo		*philo;
	t_data		*data;
	int			x;

	if ((ac != 6 && ac != 5) || !check_arg(av))
		return (printf("error\n"));
	x = -1;
	data = malloc(sizeof(t_data));
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	data_init(philo, data, av);
	while (++x < philo->data->num_philo)
	{
		if (pthread_create(&philo[x].threads, NULL, &routine, &philo[x]))
			return (1);
		if (pthread_detach(philo[x].threads))
			return (1);
		usleep(50);
	}
	while (1)
	{
		if (is_dead(philo))
			break ;
	}
}
