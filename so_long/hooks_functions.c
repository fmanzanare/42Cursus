/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:29:39 by fmanzana          #+#    #+#             */
/*   Updated: 2022/07/01 19:10:57 by fmanzana         ###   ########.fr       */
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
	return (0);
}
