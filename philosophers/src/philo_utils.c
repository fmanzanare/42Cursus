/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:46:20 by fmanzana          #+#    #+#             */
/*   Updated: 2023/02/26 21:30:23 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_initialier(t_philo *philo, long int msecs)
{
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

t_philo	**table_builder(t_data *data)
{
	int				i;
	t_philo			**table;
	struct timeval	curr_time;
	long int		msecs;

	i = 0;
	gettimeofday(&curr_time, NULL);
	msecs = ((curr_time.tv_sec * 1000000) + curr_time.tv_usec) / 1000;
	table = (t_philo **)malloc(sizeof(t_philo *) * (data->n_philos + 1));
	while (i < data->n_philos)
	{
		table[i] = (t_philo *)malloc(sizeof(t_philo));
		philo_initialier(table[i], msecs);
		pthread_create(&table[i]->philo_id, NULL, thread_start_runtime(), NULL);
		i++;
	}
	table[i] = NULL;
	return (table);
}
