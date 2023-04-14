/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:57:05 by fmanzana          #+#    #+#             */
/*   Updated: 2023/04/14 21:00:44 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_eating(t_philo *philo)
{
	printf("%dms %d has taken left fork\n", philo->te_eat, philo->philo_no);
	printf("%dms %d has taken right fork\n", philo->te_eat, philo->philo_no);
	printf("%dms %d is eating\n", philo->te_eat, philo->philo_no);
}
