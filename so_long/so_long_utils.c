/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:30:43 by fmanzana          #+#    #+#             */
/*   Updated: 2022/06/21 17:13:09 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read_map(char *file)
{
	char			*str;
	int				i;
	int				fd;
	char			tmp;

	fd = open(file, O_RDONLY);
	i = 0;
	while (read(fd, &tmp, 1) > 0)
		i++;
	close(fd);
	fd = open(file, O_RDONLY);
	str = malloc(sizeof(char) * (i + 1));
	read(fd, str, i);
	close(fd);
	str[i] = '\0';

	printf("Largo del string: %i\n\n", i);

	return (str);
}

int		map_checker(t_controltab *map, char *str)
{
	init_controltab(map);
	if (perimeter_control(map, str) == 1)
		return (1);
	else if (elements_control(map, str) == 1)
		return (1);
	return (0);
}

/*void	ft_render_background(t_img *img, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			ft_pixel_put(img, j++, i, color);
		i++;
	}
}

void	ft_pixel_put(t_img *mlx_img, int x, int y, int color)
{
	char	*dst;

	dst = mlx_img->addr + (y * mlx_img->line_len + x *(mlx_img->bpp / 8));
	*(unsigned int *)dst = color;
}*/
