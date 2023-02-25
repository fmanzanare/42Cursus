/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:46:20 by fmanzana          #+#    #+#             */
/*   Updated: 2023/02/25 19:19:48 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_initialier(t_philo *philo)
{
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
	int		i;
	t_philo	**table;

	i = 0;
	table = (t_philo **)malloc(sizeof(t_philo *) * (data->n_philos + 1));
	while (i < data->n_philos)
	{
		table[i] = (t_philo *)malloc(sizeof(t_philo));
		philo_initialier(table[i]);
		i++;
	}
	table[i] = NULL;
	return (table);
}
