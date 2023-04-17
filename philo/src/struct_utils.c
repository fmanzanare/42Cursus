/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:03:27 by fmanzana          #+#    #+#             */
/*   Updated: 2023/04/10 18:21:49 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error_writer(void)
{
	ft_putstr_fd("Error allocating memory", 2);
	return (2);
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

int	mutex_arr_initializer(t_data *data)
{
	int		i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->forks)
		return (ft_error_writer());
	while (i < data->n_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

void	data_initializer(t_data *data)
{
	data->n_philos = 0;
	data->p_start = 0;
	data->death_t = 0;
	data->eat_t = 0;
	data->sleep_t = 0;
	data->total_eat = 0;
	data->meals = 0;
	data->philo_ptr = 0;
	data->catastrophy = 0;
	data->philos_ids = 0;
	data->forks = 0;
	data->table = NULL;
}
