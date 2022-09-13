/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:29:39 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/13 09:58:00 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void *data)
{
	t_data	*mlx;

	mlx = data;
	close_images(mlx);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx->map.str_map);
	exit(0);
	return (0);
}

int	input(int keycode, void *ptr)
{
	t_data	*data;

	data = ptr;
	if (keycode == ESC)
		close_window(data);
	else if (keycode == DOWN)
		move_pj_down(data);
	else if (keycode == UP)
		move_pj_up(data);
	else if (keycode == RIGHT)
		move_pj_right(data);
	else if (keycode == LEFT)
		move_pj_left(data);
	return (0);
}
