/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_moving_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:42:14 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/12 16:35:26 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_pj_and_exit_pos(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	data->map.pj_pos = 0;
	while (data->map.str_map[i] != 'P')
	{
		data->map.pj_pos++;
		i++;
	}
	j = 0;
	data->map.exit_pos = 0;
	while (data->map.str_map[j] != 'E')
	{
		data->map.exit_pos++;
		j++;
	}
}

void	move_pj_down(t_data *data)
{
	int		i;

	find_pj_and_exit_pos(data);
	i = data->map.pj_pos + data->map.width + 1;
	if (data->map.str_map[i] != '1' && data->map.str_map[i] != '\n'
		&& data->map.str_map[i] != 'E')
	{
		if (data->map.str_map[i] == 'C')
			data->map.collect -= 1;
		data->map.str_map[data->map.pj_pos] = '0';
		data->map.str_map[i] = 'P';
		data->map.moves_counter += 1;
		print_moves_counter(data);
		pre_print_map(data);
	}
	else if (data->map.str_map[i] == 'E' && data->map.collect == 0)
	{
		ft_printf("\nYou Win!!!\n\n");
		close_window(data);
	}
}

void	move_pj_up(t_data *data)
{
	int		i;

	find_pj_and_exit_pos(data);
	i = data->map.pj_pos - data->map.width - 1;
	if (data->map.str_map[i] != '1' && data->map.str_map[i] != '\n'
		&& data->map.str_map[i] != 'E')
	{
		if (data->map.str_map[i] == 'C')
			data->map.collect -= 1;
		data->map.str_map[data->map.pj_pos] = '0';
		data->map.str_map[i] = 'P';
		data->map.moves_counter += 1;
		print_moves_counter(data);
		pre_print_map(data);
	}
	else if (data->map.str_map[i] == 'E' && data->map.collect == 0)
	{
		ft_printf("You Win!!!\n");
		close_window(data);
	}
}

void	move_pj_right(t_data *data)
{
	int		i;

	find_pj_and_exit_pos(data);
	i = data->map.pj_pos + 1;
	if (data->map.str_map[i] != '1' && data->map.str_map[i] != '\n'
		&& data->map.str_map[i] != 'E')
	{
		if (data->map.str_map[i] == 'C')
			data->map.collect -= 1;
		data->map.str_map[data->map.pj_pos] = '0';
		data->map.str_map[i] = 'P';
		data->map.moves_counter += 1;
		print_moves_counter(data);
		pre_print_map(data);
	}
	else if (data->map.str_map[i] == 'E' && data->map.collect == 0)
	{
		ft_printf("You Win!!!\n");
		close_window(data);
	}
}

void	move_pj_left(t_data *data)
{
	int		i;

	find_pj_and_exit_pos(data);
	i = data->map.pj_pos - 1;
	if (data->map.str_map[i] != '1' && data->map.str_map[i] != '\n'
		&& data->map.str_map[i] != 'E')
	{
		if (data->map.str_map[i] == 'C')
			data->map.collect -= 1;
		data->map.str_map[data->map.pj_pos] = '0';
		data->map.str_map[i] = 'P';
		data->map.moves_counter += 1;
		print_moves_counter(data);
		pre_print_map(data);
	}
	else if (data->map.str_map[i] == 'E' && data->map.collect == 0)
	{
		ft_printf("You Win!!!\n");
		close_window(data);
	}
}
