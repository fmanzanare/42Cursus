/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:41:31 by fmanzana          #+#    #+#             */
/*   Updated: 2023/04/10 18:19:44 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	status_log(t_data *data, t_philo *philo, int opt)
{
	pthread_mutex_lock(&data->status);
	if (!data->catastrophy && opt == 1)
		print_eating(data, philo);
	else if (!data->catastrophy && opt == 2)
		printf("%dms %d is sleeping\n", get_ts(data), philo->philo_no);
	else if (!data->catastrophy && opt == 3)
		printf("%dms %d is thinking\n", get_ts(data), philo->philo_no);
	pthread_mutex_unlock(&data->status);
}

static void	eating_ft(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->forks[philo->left_fork]);
	printf("%dms %d has taken a fork\n", get_ts(data), philo->philo_no);
	pthread_mutex_lock(&data->forks[philo->right_fork]);
	printf("%dms %d has taken a fork\n", get_ts(data), philo->philo_no);
	philo->te_eat = get_ts(data);
	status_log(data, philo, 1);
	while ((get_ts(data) - philo->te_eat) < data->eat_t
		&& !data->catastrophy)
	{
		catastrophy_checker(data, philo);
		usleep(50);
	}
	catastrophy_checker(data, philo);
	data->meals++;
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
	pthread_mutex_unlock(&data->forks[philo->right_fork]);
}

static void	sleeping_ft(t_data *data, t_philo *philo)
{
	int		nap_start;

	nap_start = get_ts(data);
	philo->te_sleep = get_ts(data);
	status_log(data, philo, 2);
	while ((get_ts(data) - nap_start) < data->sleep_t
		&& !data->catastrophy)
	{
		catastrophy_checker(data, philo);
		usleep(50);
	}
	catastrophy_checker(data, philo);
	philo->te_think = get_ts(data);
	status_log(data, philo, 3);
}

static void	philo_loop(t_data *data, t_philo *philo)
{
	while (!data->catastrophy)
	{
		catastrophy_checker(data, philo);
		if (!data->catastrophy)
			eating_ft(data, philo);
		catastrophy_checker(data, philo);
		if (!data->catastrophy)
			sleeping_ft(data, philo);
		if (data->total_eat > 0
			&& (data->meals / data->n_philos) == data->total_eat)
			break ;
	}
	if (data->catastrophy)
	{
		pthread_mutex_lock(&data->get_death_philo);
		data->death_philo = philo->philo_no;
	}
}

void	*thread_rutine(void *p)
{
	t_data		*data;
	t_philo		*philo;

	data = (t_data *)p;
	philo = data->table[data->philo_ptr];
	philo->left_fork = philo->philo_no - 1;
	philo->right_fork = philo->philo_no;
	if (philo->right_fork == data->n_philos)
		philo->right_fork = 0;
	// if (philo->philo_no % 2)
	// 	usleep(250);
	philo_loop(data, philo);
	pthread_mutex_unlock(&data->get_death_philo);
	return (NULL);
}
