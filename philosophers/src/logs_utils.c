/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:57:05 by fmanzana          #+#    #+#             */
/*   Updated: 2023/04/15 21:22:08 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_eating(t_data *data, t_philo *philo)
{
	//printf("%dms %d has taken a fork\n", get_ts(data), philo->philo_no);
	//printf("%dms %d has taken a fork\n", get_ts(data), philo->philo_no);
	printf("%dms %d is eating\n", get_ts(data), philo->philo_no);
}
