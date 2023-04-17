/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:04:15 by fmanzana          #+#    #+#             */
/*   Updated: 2023/04/10 18:21:23 by fmanzana         ###   ########.fr       */
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

static int	nodigit_fdr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_atoi(char *str)
{
	long int			num;
	int					sign;
	int					num_str;

	num_str = nodigit_fdr(str);
	sign = 1;
	num = 0;
	if (!*str)
		return (0);
	while (ft_isspecialchar(*str))
		str++;
	if (ft_issign(*str) == -1)
		sign = -1;
	if (ft_issign(*str))
		str++;
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (!num_str || num < INT_MIN || num > INT_MAX)
		return (-1);
	num *= sign;
	return ((int)num);
}

int	argv_parser(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Error: Wrong nbr of arguments!", 1);
		return (0);
	}
	else
	{
		data->n_philos = ft_atoi(argv[1]);
		data->death_t = ft_atoi(argv[2]);
		data->eat_t = ft_atoi(argv[3]);
		data->sleep_t = ft_atoi(argv[4]);
		if (argc == 6)
			data->total_eat = ft_atoi(argv[5]);
	}
	return (1);
}
