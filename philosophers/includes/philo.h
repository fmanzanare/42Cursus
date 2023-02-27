/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:34:13 by fmanzana          #+#    #+#             */
/*   Updated: 2023/02/27 14:25:54 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<unistd.h>
# include<sys/time.h>
# include<pthread.h>

typedef struct s_philo
{
	pthread_t			philoID;
	struct timeval		*curr_time;
	long unsigned int	p_start;
	long unsigned int	te_eat;
	long unsigned int	te_sleep;
}				t_philo;

typedef struct s_data
{
	int				n_philos;
	long int		death_t;
	long int		eat_t;
	long int		sleep_t;
	int				total_eat;
	struct timeval	*curr_time;
	pthread_t		*philos_ids;
	t_philo			**table;
}				t_data;

void	data_initializer(t_data *data);
void	ft_putstr_fd(char *str, int fd);
void	argv_parser(t_data *data, int argc, char **argv);
void	table_builder(t_data *data);
void	free_table(t_philo **table);
void	*thread_start_rutine(void *p);

#endif
