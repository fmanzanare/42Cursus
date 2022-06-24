/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:53:31 by fmanzana          #+#    #+#             */
/*   Updated: 2022/06/24 13:14:02 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<mlx.h>
# include"LIBFT/libft.h"
# include<stdlib.h>
# include<fcntl.h>
# include<stdio.h>

# define IMG_S 80

typedef struct s_imgtype
{
	void	*wall;
	void	*floor;
	void	*collect;
	void	*player_1;
	void	*player_2;
	void	*exit;
}				t_imgtype;

typedef struct s_img
{
	int			x;
	int			y;
	t_imgtype	type;
}				t_img;

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

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	t_controltab	map;
}				t_data;

char	*ft_read_map(char *file);
int		map_checker(t_controltab *map);
void	init_controltab(t_controltab *map);
int		perimeter_control(t_controltab *map);
int		columns_rows_and_check(t_controltab *map);
void	first_row_ctrl(t_controltab *map, int x, int y);
void	mid_rows_ctrl(t_controltab *map, int x, int y);
void	last_row_ctrl(t_controltab *map, int x, int i);
int		perimeter_checker(t_controltab *map, int y);
int		elements_control(t_controltab *map);
void	open_images(t_data *data);
void	pre_print_map(t_data *data);
void	print_map(t_data *data, int i, int j, int k);
void	close_images(t_data *data);

#endif
