/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:41:48 by fmanzana          #+#    #+#             */
/*   Updated: 2023/04/10 18:20:43 by fmanzana         ###   ########.fr       */
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
	int					te_think;
	int					te_death;
	int					last_meal;
}				t_philo;

typedef struct s_data
{
	int				n_philos;
	long int		p_start;
	int				death_t;
	int				eat_t;
	int				sleep_t;
	int				total_eat;
	int				meals;
	int				philo_ptr;
	int				catastrophy;
	pthread_mutex_t	get_death_philo;
	int				death_philo;
	int				te_death;
	struct timeval	*curr_time;
	pthread_t		*philos_ids;
	pthread_mutex_t	status;
	pthread_mutex_t	*forks;
	t_philo			**table;
}				t_data;

void		data_initializer(t_data *data);
void		ft_putstr_fd(char *str, int fd);
int			argv_parser(t_data *data, int argc, char **argv);
int			table_builder(t_data *data);
void		free_table(t_philo **table);
void		*thread_rutine(void *p);
int			get_ts(t_data *data);
int			mutex_arr_initializer(t_data *data);
void		mutex_arr_destroyer(t_data *data);
void		catastrophy_checker(t_data *data, t_philo *philo);
int			ft_error_writer(void);

/* CHAR UTILS */
int			ft_isspecialchar(char c);
int			ft_isdigit(int c);
int			ft_issign(char c);

#endif
