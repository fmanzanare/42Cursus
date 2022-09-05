/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:29:39 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/05 16:49:56 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	else if (keycode == UP)
		move_pj_up(data);
	else if (keycode == RIGHT)
		move_pj_right(data);
	else if (keycode == LEFT)
		move_pj_left(data);
	return (0);
}
