/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:02:53 by fmanzana          #+#    #+#             */
/*   Updated: 2023/03/04 10:59:15 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	get_ts(long int prev)
{
	struct timeval	curr_time;
	long int		msecs;

	gettimeofday(&curr_time, NULL);
	msecs = ((curr_time.tv_sec * 1000000) + curr_time.tv_usec) / 1000;
	return (msecs - prev);
}

void	*thread_rutine(void *p)
{
	t_data		*data;
	t_philo		*philo;

	data = (t_data *)p;
	philo = data->table[data->philo_ptr];
	if ((get_ts(philo->p_start) - philo->te_eat) > philo->death_t)
		printf("%li %i died\n", get_ts(philo->p_start), philo->philo_no);
	printf("%li %i has taken a fork\n", get_ts(philo->p_start), philo->philo_no);
	// lock_mutex
	printf("%li %i is eating\n", get_ts(philo->p_start), philo->philo_no);
	usleep(philo->eat_t);
	// unlock_mutex
	printf("%li %i is sleeping\n", get_ts(philo->p_start), philo->philo_no);
	usleep(philo->sleep_t);
	printf("%li %i is thinking\n\n", get_ts(philo->p_start), philo->philo_no);
	usleep(philo->death_t - philo->sleep_t);
	return (NULL);
}
