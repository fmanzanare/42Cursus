/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:34:17 by fmanzana          #+#    #+#             */
/*   Updated: 2023/03/03 20:24:54 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	error_mng(t_data *data)
{
	int	flag;

	flag = 1;
	if (data->n_philos <= 0 || data->death_t <= 0 || data->eat_t <= 0
		|| data->sleep_t <= 0 || data->total_eat < 0)
		flag = 0;
	if (data->n_philos <= 0)
		ft_putstr_fd("Error: Philosophers cannot be 0 or negative", 1);
	else if (data->death_t <= 0)
		ft_putstr_fd("Error: Death Time cannot be 0 or negative", 1);
	else if (data->eat_t <= 0)
		ft_putstr_fd("Error: Eating Time cannot be 0 or negative", 1);
	else if (data->sleep_t <= 0)
		ft_putstr_fd("Error: Sleeping Time cannot be 0 or negative", 1);
	else if (data->total_eat < 0)
		ft_putstr_fd("Error: Times to Eat cannot be less than 0", 1);
	if (!flag)
		exit(1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data_initializer(&data);
	argv_parser(&data, argc, argv);
	mutex_arr_initializer(&data);
	error_mng(&data);
	table_builder(&data);
	mutex_arr_destroyer(&data);
	//free(&data);
	return (0);
}
