/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:04:15 by fmanzana          #+#    #+#             */
/*   Updated: 2023/03/12 13:04:15 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

static int	ft_atoi(char *str)
{
	long int	num;
	int			sign;

	sign = 1;
	num = 0;
	if (!*str)
		return (0);
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	num *= sign;
	if (num > INT_MIN && num < INT_MAX)
		return ((int)num);
	return (-1);
}

void	argv_parser(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Error: Wrong nbr of arguments!", 1);
		exit(1);
	}
	else
	{
		data->n_philos = ft_atoi(argv[1]);
		data->death_t = ft_atoi(argv[2]) * 1000;
		data->eat_t = ft_atoi(argv[3]) * 1000;
		data->sleep_t = ft_atoi(argv[4]) * 1000;
		if (argc == 6)
			data->total_eat = ft_atoi(argv[5]);
	}
}
