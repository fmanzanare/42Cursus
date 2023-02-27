/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:02:53 by fmanzana          #+#    #+#             */
/*   Updated: 2023/02/27 14:27:58 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	get_time_stamp(t_philo *philo)
{
	long unsigned int		msecs;

	gettimeofday(philo->curr_time, NULL);
	msecs = ((philo->curr_time->tv_sec * 1000000) + philo->curr_time->tv_usec) / 1000;
	return (msecs);
}

void	*thread_start_rutine(void *p)
{
	t_philo *philo = (t_philo *)p;

	philo->philoID = pthread_self();
	printf("PhiloID: [%li], Time Stamp: %li\n", (long int)&philo->philoID, get_time_stamp(philo));
	return (NULL);
}
