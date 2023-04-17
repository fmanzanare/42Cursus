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
	if (!table)
		return ;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

static int	rutine_checker(t_data *data)
{
	if ((data->meals / data->n_philos) == data->total_eat
		&& data->total_eat > 0)
	{
		printf("Philosophers ate %d times\n", data->total_eat);
		return (1);
	}
	if (data->catastrophy)
	{
		printf("%dms %d died\n", data->te_death, data->death_philo);
		return (0);
	}
	return (1);
}

static int	table_and_philo_alloc(t_data *data)
{
	data->table = (t_philo **)malloc(sizeof(t_philo) * (data->n_philos));
	data->philos_ids = (pthread_t *)malloc(sizeof(pthread_t) * data->n_philos);
	if (!data->table || !data->philos_ids)
		return (ft_error_writer());
	return (1);
}

int	table_builder(t_data *data)
{
	int				i;
	struct timeval	curr_time;

	i = 0;
	gettimeofday(&curr_time, NULL);
	data->p_start = ((curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000));
	if (table_and_philo_alloc(data) == 2)
		return (2);
	while (i < data->n_philos)
	{
		data->philo_ptr = i;
		data->table[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!data->table[i])
			return (ft_error_writer());
		data->table[i]->philo_no = (i + 1);
		pthread_create(&data->table[i]->philo_id, NULL, thread_rutine, data);
		usleep(50);
		i++;
	}
	i = 0;
	while (i < data->n_philos)
		pthread_join(data->table[i++]->philo_id, NULL);
	return (rutine_checker(data));
}
