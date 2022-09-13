/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter_control_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:13:28 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/13 09:14:07 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	columns_rows_and_check(t_controltab *map)
{
	int		x;
	int		y;
	int		i;
	int		perimeter_chkr;

	i = 0;
	x = 0;
	while (map->str_map[i] != '\n')
	{
		x++;
		i++;
	}
	i = 0;
	y = 0;
	while (map->str_map[i] != '\0')
	{
		if (map->str_map[i] == '\n')
			y++;
		i++;
	}
	map->hight = map->hight + y;
	first_row_ctrl(map, x, y);
	perimeter_chkr = perimeter_checker(map, y);
	return (perimeter_chkr);
}

void	first_row_ctrl(t_controltab *map, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map->str_map[i] != '\n' && map->str_map[i] == '1')
	{
		map->width += 1;
		i++;
		if (map->width == x)
			map->perimeter += 1;
	}
	mid_rows_ctrl(map, x, y);
}

void	mid_rows_ctrl(t_controltab *map, int x, int y)
{
	int		i;
	int		j;

	i = x;
	j = 0;
	while (map->str_map[i] != '\0')
	{
		while (map->str_map[i] != '\n' && (j + 1) < y && j != 0)
		{
			if (i % (x + 1) == 0 && map->str_map[i] == '1'
				&& map->str_map[i + (x - 1)] == '1')
				map->perimeter += 1;
			i++;
		}
		i++;
		j++;
	}
	last_row_ctrl(map, x, i);
}

void	last_row_ctrl(t_controltab *map, int x, int i)
{
	i = i - (x + 1);
	while (map->str_map[i] != '\0')
	{
		if (map->str_map[i] == '1')
			map->width += 1;
		if ((map->width / 2) == x)
		{
			map->perimeter += 1;
			break ;
		}
		i++;
	}
	map->width = map->width / 2;
}

int	perimeter_checker(t_controltab *map, int y)
{
	if (map->perimeter != y)
		return (1);
	return (0);
}
