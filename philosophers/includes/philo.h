/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:34:13 by fmanzana          #+#    #+#             */
/*   Updated: 2023/03/04 12:10:45 by fmanzana         ###   ########.fr       */
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
	pthread_t			philo_id;
	int					philo_no;
	int					left_fork;
	int					right_fork;
	long int			te_eat;
	long int			te_sleep;
}				t_philo;

typedef struct s_data
{
	int				n_philos;
	long int		p_start;
	long int		death_t;
	long int		eat_t;
	long int		sleep_t;
	int				total_eat;
	int				philo_ptr;
	struct timeval	*curr_time;
	pthread_t		*philos_ids;
	pthread_mutex_t	*forks;
	t_philo			**table;
}				t_data;

void		data_initializer(t_data *data);
void		ft_putstr_fd(char *str, int fd);
void		argv_parser(t_data *data, int argc, char **argv);
void		table_builder(t_data *data);
void		free_table(t_philo **table);
void		*thread_rutine(void *p);
long int	get_ts(t_data *data);
void		mutex_arr_initializer(t_data *data);
void		mutex_arr_destroyer(t_data *data);

#endif
