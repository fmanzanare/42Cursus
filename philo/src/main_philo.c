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

static void	one_philo_case(t_data *data)
{
	printf("0ms 1 has taken a fork\n");
	usleep(data->death_t * 1000);
	printf("%dms 1 died\n", data->death_t);
}

static int	error_mng(t_data *data)
{
	int	flag;

	flag = 1;
	if (data->n_philos <= 1 || data->death_t <= 0 || data->eat_t <= 0
		|| data->sleep_t <= 0 || data->total_eat < 0)
		flag = 0;
	if (data->n_philos <= 0)
		ft_putstr_fd("Error: Philosophers cannot be 0 or negative", 1);
	else if (data->n_philos == 1)
		one_philo_case(data);
	else if (data->death_t <= 0)
		ft_putstr_fd("Error: Death Time cannot be 0 or negative", 1);
	else if (data->eat_t <= 0)
		ft_putstr_fd("Error: Eating Time cannot be 0 or negative", 1);
	else if (data->sleep_t <= 0)
		ft_putstr_fd("Error: Sleeping Time cannot be 0 or negative", 1);
	else if (data->total_eat < 0)
		ft_putstr_fd("Error: Times to Eat cannot be less than 0", 1);
	return (flag);
}

static void	world_destroyer(t_data *data)
{
	mutex_arr_destroyer(data);
	pthread_mutex_destroy(&data->status);
	pthread_mutex_destroy(&data->get_death_philo);
	free_table(data->table);
	free(data->philos_ids);
	free(data->forks);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		flag;

	data_initializer(&data);
	if (!argv_parser(&data, argc, argv) || !error_mng(&data))
		return (1);
	pthread_mutex_init(&data.status, NULL);
	pthread_mutex_init(&data.get_death_philo, NULL);
	if (mutex_arr_initializer(&data))
		return (1);
	flag = table_builder(&data);
	if (flag == 2)
	{
		world_destroyer(&data);
		return (1);
	}
	world_destroyer(&data);
	return (0);
}
