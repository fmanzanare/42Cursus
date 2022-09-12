/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:15:57 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/12 11:26:49 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_images(t_data *data)
{
	data->img.type.wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprites/wall.xpm", &data->img.x, &data->img.y);
	data->img.type.floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprites/floor.xpm", &data->img.x, &data->img.y);
	data->img.type.collect = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprites/collectable.xpm", &data->img.x, &data->img.y);
	data->img.type.player_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprites/player-1.xpm", &data->img.x, &data->img.y);
	data->img.type.player_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprites/player-2.xpm", &data->img.x, &data->img.y);
	data->img.type.exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprites/exit.xpm", &data->img.x, &data->img.y);
	data->img.type.opened = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprites/opened.xpm", &data->img.x, &data->img.y);
}

void	pre_print_map(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	print_map(data, i, j, k);
}

void	print_map(t_data *data, int i, int j, int k)
{
	while (data->map.str_map[i] != '\0')
	{
		if (data->map.str_map[i] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.type.wall, IMG_S * k, IMG_S * j);
		else if (data->map.str_map[i] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.type.floor, IMG_S * k, IMG_S * j);
		else if (data->map.str_map[i] == 'C')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.type.collect, IMG_S * k, IMG_S * j);
		else if (data->map.str_map[i] == 'P')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.type.player_1, IMG_S * k, IMG_S * j);
		else if (data->map.str_map[i] == 'E')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.type.exit, IMG_S * k, IMG_S * j);
		k++;
		if (data->map.str_map[i] == '\n' && j <= data->map.hight)
		{
			j++;
			k = 0;
		}
		i++;
	}
}

void	close_images(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.type.wall);
	mlx_destroy_image(data->mlx_ptr, data->img.type.floor);
	mlx_destroy_image(data->mlx_ptr, data->img.type.collect);
	mlx_destroy_image(data->mlx_ptr, data->img.type.player_1);
	mlx_destroy_image(data->mlx_ptr, data->img.type.player_2);
	mlx_destroy_image(data->mlx_ptr, data->img.type.exit);
}
