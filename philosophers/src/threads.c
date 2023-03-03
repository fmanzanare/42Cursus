/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:02:53 by fmanzana          #+#    #+#             */
/*   Updated: 2023/03/03 20:47:48 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	get_time_stamp(long int prev, t_philo *philo)
{
	long int	time_st;
	long int	msecs;

	gettimeofday(philo->curr_time, NULL);
	msecs = ((philo->curr_time->tv_sec * 1000000) + philo->curr_time->tv_usec) / 1000;
	time_st = msecs - prev;
	return (time_st);
}

t_philo	*checkID(t_data *data, pthread_t self_id)
{
	int		i;

	i = 0;
	while (i < data->n_philos)
	{
		if (data->philos_ids[i] == self_id)
			return (data->table[i]);
		i++;
	}
	return (NULL);
}

void	*thread_rutine(void *p)
{
	t_data		*data;
	pthread_t	thread_id;
	t_philo 	*philo;

	data = (t_data *)p;
	thread_id = pthread_self();
	philo = checkID(data, thread_id);
	//philo = (t_philo *)p;
	if ((get_time_stamp(philo->p_start, philo) - philo->te_eat) > philo->death_t)
		printf("%li %i died\n", get_time_stamp(philo->p_start, philo), philo->philoNo);
	printf("%li %i has taken a fork\n", get_time_stamp(philo->p_start, philo), philo->philoNo);
	// lock_mutex
	printf("%li %i is eating\n", get_time_stamp(philo->p_start, philo), philo->philoNo);
	usleep(philo->eat_t);
	// unlock_mutex
	printf("%li %i is sleeping\n", get_time_stamp(philo->p_start, philo), philo->philoNo);
	usleep(philo->sleep_t);
	printf("%li %i is thinking\n\n", get_time_stamp(philo->p_start, philo), philo->philoNo);
	usleep(philo->death_t - philo->sleep_t);
	return (NULL);
}
