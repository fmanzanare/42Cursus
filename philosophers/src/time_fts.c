/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:41:27 by fmanzana          #+#    #+#             */
/*   Updated: 2023/03/12 12:41:27 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	get_ts(t_data *data)
{
	struct timeval	curr_time;
	int				msecs;

	gettimeofday(&curr_time, NULL);
	msecs = (curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000);
	return (msecs - data->p_start);
}

void	catastrophy_checker(t_data *data, t_philo *philo)
{
	if (get_ts(data) - philo->te_eat > data->death_t)
		data->catastrophy = 1;
	if (data->catastrophy)
		philo->te_death = get_ts(data);
}
