/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:02:53 by fmanzana          #+#    #+#             */
/*   Updated: 2023/02/26 20:43:28 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	get_time_stamp(void)
{
	struct timeval			curr_time;
	long unsigned int		msecs;

	gettimeofday(&curr_time, NULL);
	msecs = ((curr_time.tv_sec * 1000000) + curr_time.tv_usec) / 1000;
	return (msecs);
}

void	*thread_start_runtime(void)
{
	pthread_t		id;

	id = pthread_self();
	printf("PhiloID: [%ld], Time Stamp: %li\n", id, get_time_stamp());
	return (NULL);
}
