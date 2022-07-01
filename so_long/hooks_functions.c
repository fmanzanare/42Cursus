/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:29:39 by fmanzana          #+#    #+#             */
/*   Updated: 2022/06/24 15:42:30 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*close_window(int keycode, t_data *data)
{
	close_images(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}
