/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:46:20 by fmanzana          #+#    #+#             */
/*   Updated: 2023/02/27 14:30:25 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	philo_initialier(t_philo *philo, long int msecs)
{
	struct timeval	curr_time;

	philo->curr_time = &curr_time;
	philo->p_start = msecs;
	philo->te_eat = 0;
	philo->te_sleep = 0;
}

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
	long int		msecs;

	i = 0;
	gettimeofday(&curr_time, NULL);
	msecs = ((curr_time.tv_sec * 1000000) + curr_time.tv_usec) / 1000;
	data->table = (t_philo **)malloc(sizeof(t_philo) * (data->n_philos));
	data->philos_ids = (pthread_t *)malloc(sizeof(pthread_t) * data->n_philos);
	while (i < data->n_philos)
	{
		data->table[i] = (t_philo *)malloc(sizeof(t_philo));
		philo_initialier(data->table[i], msecs);
		pthread_create(&data->philos_ids[i], NULL, thread_start_rutine, data->table[i]);
		pthread_join(data->philos_ids[i], NULL);
		i++;
	}
}
