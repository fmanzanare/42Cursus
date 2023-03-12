/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:41:48 by fmanzana          #+#    #+#             */
/*   Updated: 2023/03/12 12:41:48 by fmanzana         ###   ########.fr       */
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
# include<limits.h>

typedef struct s_philo
{
	pthread_t			philo_id;
	int					philo_no;
	int					left_fork;
	int					right_fork;
	int					te_eat;
	int					te_sleep;
	int					te_death;
}				t_philo;

typedef struct s_data
{
	int				n_philos;
	int				p_start;
	int				death_t;
	int				eat_t;
	int				sleep_t;
	int				total_eat;
	int				meals;
	int				philo_ptr;
	int				catastrophy;
	struct timeval	*curr_time;
	pthread_t		*philos_ids;
	pthread_mutex_t	status;
	pthread_mutex_t	*forks;
	t_philo			**table;
}				t_data;

void	data_initializer(t_data *data);
void	ft_putstr_fd(char *str, int fd);
void	argv_parser(t_data *data, int argc, char **argv);
void	table_builder(t_data *data);
void	free_table(t_philo **table);
void	*thread_rutine(void *p);
int		get_ts(t_data *data);
void	mutex_arr_initializer(t_data *data);
void	mutex_arr_destroyer(t_data *data);
void	catastrophy_checker(t_data *data, t_philo *philo);

#endif
