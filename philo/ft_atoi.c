/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaa <aelbouaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:04:01 by aelbouaa          #+#    #+#             */
/*   Updated: 2023/07/26 11:30:42 by aelbouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	wspace(const char *str)
{
	int	x;

	x = 0;
	while ((str[x] == '\f') || (str[x] == '\t') || (str[x] == '\n')
		|| (str[x] == '\v') || (str[x] == '\r') || (str[x] == ' '))
		x++;
	return (x);
}

int	ft_atoi(const char *str)
{
	int				mines;
	unsigned long	result;

	mines = 1;
	result = 0;
	str = str + wspace(str);
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			mines = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + (*str - 48);
		if (result == __LONG_MAX__ && mines == -1)
			return (1);
		if (result >= __LONG_MAX__ && mines == 1)
			return (-1);
		if (result >= __LONG_MAX__ && mines == -1)
			return (0);
		str++;
	}
	return (result * mines);
}
