/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:47:02 by fmanzana          #+#    #+#             */
/*   Updated: 2023/03/03 20:24:49 by fmanzana         ###   ########.fr       */
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

void	mutex_arr_destroyer(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}

void	mutex_arr_initializer(t_data *data)
{
	int		i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->n_philos);
	while (i < data->n_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	data_initializer(t_data *data)
{
	data->n_philos = 0;
	data->death_t = 0;
	data->eat_t = 0;
	data->sleep_t = 0;
	data->total_eat = 0;
}

static long int	ft_atoli(char *str)
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
	return (num);
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
		data->n_philos = (int)ft_atoli(argv[1]);
		data->death_t = ft_atoli(argv[2]);
		data->eat_t = ft_atoli(argv[3]);
		data->sleep_t = ft_atoli(argv[4]);
		if (argc == 6)
			data->total_eat = (int)ft_atoli(argv[5]);
	}
}
