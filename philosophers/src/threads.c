/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:02:53 by fmanzana          #+#    #+#             */
/*   Updated: 2023/03/04 12:10:20 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	get_ts(t_data *data)
{
	struct timeval	curr_time;
	long int		msecs;

	gettimeofday(&curr_time, NULL);
	msecs = (curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000);
	return (msecs - data->p_start);
}

// void	forks_assignment(t_data *data)
// {

// }

void	*thread_rutine(void *p)
{
	t_data		*data;
	t_philo		*philo;

	data = (t_data *)p;
	philo = data->table[data->philo_ptr];
	if ((get_ts(data) - philo->te_eat) > data->death_t)
		printf("%li %i died\n", get_ts(data), philo->philo_no);
	printf("%li %i has taken a fork\n", get_ts(data), philo->philo_no);
	// lock_mutex
	printf("%li %i is eating\n", get_ts(data), philo->philo_no);
	usleep(data->eat_t);
	// unlock_mutex
	printf("%li %i is sleeping\n", get_ts(data), philo->philo_no);
	usleep(data->sleep_t);
	printf("%li %i is thinking\n\n", get_ts(data), philo->philo_no);
	usleep(data->death_t - data->sleep_t);
	return (NULL);
}
