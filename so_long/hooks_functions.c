/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:29:39 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/05 16:16:11 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_pj_pos(t_data *data)
{
	int		i;

	i = 0;
	data->map.pj_pos = 0;
	while (data->map.str_map[i] != 'P')
	{
		data->map.pj_pos++;
		i++;
	}
	printf("%i\n\n", data->map.pj_pos);
}

static void	move_pj_down(t_data *data)
{
	int		i;

	find_pj_pos(data);
	i = data->map.pj_pos + data->map.width + 1;
	if (data->map.str_map[i] != '1' && data->map.str_map[i] != 'P' && data->map.str_map[i] != '\n')
	{
		data->map.str_map[data->map.pj_pos] = '0';
		data->map.str_map[i] = 'P';
		pre_print_map(data);
	}
	printf("%i\n", data->map.width);
	printf("%s\n", data->map.str_map);
}

static void	close_window(t_data *data)
{	
	close_images(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int	input(int keycode, void *ptr)
{
	t_data	*data;

	data = ptr;
	if (keycode == ESC)
		close_window(data);
	else if (keycode == DOWN)
		move_pj_down(data);
	return (0);
}
