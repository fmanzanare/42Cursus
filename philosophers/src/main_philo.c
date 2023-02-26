/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:34:17 by fmanzana          #+#    #+#             */
/*   Updated: 2023/02/26 21:17:42 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	error_mng(t_data *data)
{
	int	flag;

	flag = 1;
	if (data->n_philos <= 0 || data->death_t <= 0 || data->eat_t <= 0
		|| data->sleep_t <= 0)
		flag = 0;
	if (!data->n_philos)
		ft_putstr_fd("Error: Philosophers cannot be 0", 1);
	else if (!data->death_t)
		ft_putstr_fd("Error: Death Time cannot be 0", 1);
	else if (!data->eat_t)
		ft_putstr_fd("Error: Eating Time cannot be 0", 1);
	else if (!data->sleep_t)
		ft_putstr_fd("Error: Sleeping Time cannot be 0", 1);
	if (!flag)
		exit(1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	**table;

	data_initializer(&data);
	argv_parser(&data, argc, argv);
	error_mng(&data);
	table = table_builder(&data);
	free_table(table);
	return (0);
}
