/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:02:09 by fmanzana          #+#    #+#             */
/*   Updated: 2022/06/21 17:07:20 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<mlx.h>
# include"LIBFT/libft.h"
# include<stdlib.h>
# include<fcntl.h>
# include<stdio.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00
# define BLUE_PIXEL 0x0000FF
# define YELLOW_PIXEL 0xFFFF00
# define PURPLE_PIXEL 0x800080
# define WHITE_PIXEL 0xFFFFFF

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_data;

typedef struct s_controltab
{
	char	*str_map;
	int		width;
	int		hight;
	int		player;
	int		collect;
	int		exit;
	int		perimeter;
}				t_controltab;

//void	ft_pixel_put(t_img *mlx_img, int x, int y, int color);
//void	ft_render_background(t_img *img, int color);
char	*ft_read_map(char *file);
int		map_checker(t_controltab *map, char *str);
void	init_controltab(t_controltab *map);
int		perimeter_control(t_controltab *map, char *str);
int		columns_rows_and_check(t_controltab *map, char *str);
void	first_row_ctrl(t_controltab *map, char *str, int x, int y);
void	mid_rows_ctrl(t_controltab *map, char *str, int x, int y);
void	last_row_ctrl(t_controltab *map, char *str, int x, int i);
int		perimeter_checker(t_controltab *map, int y);
int		elements_control(t_controltab *map, char *str);

#endif