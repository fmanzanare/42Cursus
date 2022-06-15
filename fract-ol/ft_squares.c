/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_squares.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:15:13 by fmanzana          #+#    #+#             */
/*   Updated: 2022/06/15 14:08:37 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}				t_rect;

int		ft_render_rect(t_img *img, t_rect rect)
{
	int		i;
	int		j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			ft_pixel_put(img, j++, i, rect.color);
		i++;
	}
	return (0);
}

int		ft_render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	ft_render_background(&data->img, WHITE_PIXEL);
	ft_render_rect(&data->img, (t_rect){0, WINDOW_HEIGHT - 100, WINDOW_WIDTH, 100, PURPLE_PIXEL});
	ft_render_rect(&data->img, (t_rect){0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, 100, YELLOW_PIXEL});
	ft_render_rect(&data->img, (t_rect){0, 0, WINDOW_WIDTH, 100, RED_PIXEL});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int		main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "testing window!");
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	ft_render(&data);
	mlx_loop(data.mlx_ptr);
}
