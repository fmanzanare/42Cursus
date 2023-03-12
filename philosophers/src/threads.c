/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:41:31 by fmanzana          #+#    #+#             */
/*   Updated: 2023/03/12 12:41:31 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void status_log(t_data *data, t_philo *philo, int opt)
{
	pthread_mutex_lock(&data->status);
	if (!data->catastrophy && opt == 1)
		printf("%dms %d is eating\n", philo->te_eat, philo->philo_no);
	else if (!data->catastrophy && opt == 2)
		printf("%dms %d is sleeping\n", philo->te_sleep, philo->philo_no);
	else if (!data->catastrophy && opt == 3)
		printf("Philosophers ate %d times", data->total_eat);
	else
		printf("%dms %d is death\n", philo->te_death, philo->philo_no);
	data->meals++;
	pthread_mutex_unlock(&data->status);
}

static void	eating_ft(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->forks[philo->left_fork]);
	pthread_mutex_lock(&data->forks[philo->right_fork]);
	philo->te_eat = get_ts(data);
	status_log(data, philo, 1);
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
	pthread_mutex_unlock(&data->forks[philo->right_fork]);
}

static void sleeping_ft(t_data *data)
{
	int		nap_start;

	nap_start = get_ts(data);
	while (get_ts(data) - nap_start < data->sleep_t)
		usleep(50);
}

static void philo_loop(t_data *data, t_philo *philo)
{
	while (!data->catastrophy)
	{
		catastrophy_checker(data, philo);
		if (!data->catastrophy)
			eating_ft(data, philo);
		catastrophy_checker(data, philo);
		if (!data->catastrophy)
		{
			sleeping_ft(data);
			status_log(data, philo, 2);
		}
		if (data->total_eat > 0 && data->meals == data->total_eat)
		{
			status_log(data, philo, 3);
			break;
		}
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
	if (philo->right_fork == philo->philo_no)
		philo->right_fork = 0;
	//-----------------------------------------
	if (philo->philo_no % 2)
		usleep(250);
	//-----------------------------------------
	philo_loop(data, philo);
	return (NULL);
}
