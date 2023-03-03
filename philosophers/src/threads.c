/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:02:53 by fmanzana          #+#    #+#             */
/*   Updated: 2023/02/27 16:28:35 by fmanzana         ###   ########.fr       */
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

void	*thread_start_rutine(void *p)
{
	t_philo 	*philo;

	philo = (t_philo *)p;
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
