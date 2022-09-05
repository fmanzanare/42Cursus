/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_moving_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:42:14 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/05 18:26:56 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_pj_pos(t_data *data)
{
	int		i;

	i = 0;
	data->map.pj_pos = 0;
	while (data->map.str_map[i] != 'P')
	{
		data->map.pj_pos++;
		i++;
	}
}

void	move_pj_down(t_data *data)
{
	int		i;

	find_pj_pos(data);
	i = data->map.pj_pos + data->map.width + 1;
	if (data->map.str_map[i] != '1' && data->map.str_map[i] != '\n'
		&& data->map.str_map[i] != 'E')
	{
		if (data->map.str_map[i] == 'C')
		{
			data->map.collect -= 1;
			printf("%i\n", data->map.collect);
		}
		data->map.str_map[data->map.pj_pos] = '0';
		data->map.str_map[i] = 'P';
		pre_print_map(data);
	}
}

void	move_pj_up(t_data *data)
{
	int		i;

	find_pj_pos(data);
	i = data->map.pj_pos - data->map.width - 1;
	if (data->map.str_map[i] != '1' && data->map.str_map[i] != '\n'
		&& data->map.str_map[i] != 'E')
	{
		if (data->map.str_map[i] == 'C')
		{
			data->map.collect -= 1;
			printf("%i\n", data->map.collect);
		}
		data->map.str_map[data->map.pj_pos] = '0';
		data->map.str_map[i] = 'P';
		pre_print_map(data);
	}
}

void	move_pj_right(t_data *data)
{
	int		i;

	find_pj_pos(data);
	i = data->map.pj_pos + 1;
	if (data->map.str_map[i] != '1' && data->map.str_map[i] != '\n'
		&& data->map.str_map[i] != 'E')
	{
		if (data->map.str_map[i] == 'C')
		{
			data->map.collect -= 1;
			printf("%i\n", data->map.collect);
		}
		data->map.str_map[data->map.pj_pos] = '0';
		data->map.str_map[i] = '0';
		pre_print_map(data);
		data->map.str_map[i] = 'P';
		pre_print_map(data);
	}
	else if (data->map.str_map[i] == 'E' && data->map.collect == 0)
	{
	// Animacion puerta abierta + finalizacion programa
	}
}
void	move_pj_left(t_data *data)
{
	int		i;

	find_pj_pos(data);
	i = data->map.pj_pos - 1;
	if (data->map.str_map[i] != '1' && data->map.str_map[i] != '\n'
		&& data->map.str_map[i] != 'E')
	{
		if (data->map.str_map[i] == 'C')
		{
			data->map.collect -= 1;
			printf("%i\n", data->map.collect);
		}
		data->map.str_map[data->map.pj_pos] = '0';
		data->map.str_map[i] = 'P';
		pre_print_map(data);
	}
}
