/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:46:20 by fmanzana          #+#    #+#             */
/*   Updated: 2023/03/04 12:09:05 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_table(t_philo **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void	table_builder(t_data *data)
{
	int				i;
	struct timeval	curr_time;

	i = 0;
	gettimeofday(&curr_time, NULL);
	data->p_start = ((curr_time.tv_sec * 1000000) + curr_time.tv_usec) / 1000;
	data->table = (t_philo **)malloc(sizeof(t_philo) * (data->n_philos));
	data->philos_ids = (pthread_t *)malloc(sizeof(pthread_t) * data->n_philos);
	while (i < data->n_philos)
	{
		data->philo_ptr = i;
		data->table[i] = (t_philo *)malloc(sizeof(t_philo));
		data->table[i]->philo_no = (i + 1);
		pthread_create(&data->table[i]->philo_id, NULL, thread_rutine, data);
		usleep(50);
		i++;
	}
	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(data->table[i]->philo_id, NULL);
		i++;
	}
}
