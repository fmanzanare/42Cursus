/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:28:37 by fmanzana          #+#    #+#             */
/*   Updated: 2022/06/23 15:04:45 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_images(t_data *data)
{
	data->img->type->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprites/wall.xpm", &data->img->x, &data->img->y);
	data->img->type->floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprites/floor.xpm", &data->img->x, &data->img->y);
	data->img->type->collect = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprites/collectable.xpm", &data->img->x, &data->img->y);
	data->img->type->player_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprites/player-1.xpm", &data->img->x, &data->img->y);
	data->img->type->player_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprites/player-2.xpm", &data->img->x, &data->img->y);
	data->img->type->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprites/exit.xpm", &data->img->x, &data->img->y);
}

void	prerender_function(t_data *data, char *str, t_controltab map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	data->map->hight = map.hight;
	render_function(data, str, i, j, k);
}

void	render_function(t_data *data, char *str, int i, int j, int k)
{
	while (str[i] != '\0')
	{
		if (str[i] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->type->wall, IMG_S * k, IMG_S * j);
		else if (str[i] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->type->floor, IMG_S * k, IMG_S * j);
		else if (str[i] == 'C')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->type->collect, IMG_S * k, IMG_S * j);
		else if (str[i] == 'P')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->type->player_1, IMG_S * k, IMG_S * j);
		else if (str[i] == 'E')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->type->exit, IMG_S * k, IMG_S * j);
		k++;
		if (str[i] == '\n' && j <= data->map->hight)
		{
			j++;
			k = 0;
		}
		i++;
	}
}

void	close_images(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->type->wall);
	mlx_destroy_image(data->mlx_ptr, data->img->type->floor);
	mlx_destroy_image(data->mlx_ptr, data->img->type->collect);
	mlx_destroy_image(data->mlx_ptr, data->img->type->player_1);
	mlx_destroy_image(data->mlx_ptr, data->img->type->player_2);
	mlx_destroy_image(data->mlx_ptr, data->img->type->exit);
}
