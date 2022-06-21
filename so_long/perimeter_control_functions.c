/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter_control_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:46:48 by fmanzana          #+#    #+#             */
/*   Updated: 2022/06/21 17:06:41 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	columns_rows_and_check(t_controltab *map, char *str)
{
	int		x;
	int		y;
	int		i;
	int		perimeter_chkr;

	i = 0;
	x = 0;
	while (str[i] != '\n')
	{
		x++;
		i++;
	}
	i = 0;
	y = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			y++;
		i++;
	}
	first_row_ctrl(map, str, x, y);
	perimeter_chkr = perimeter_checker(map, y);
	return (perimeter_chkr);
}

void	first_row_ctrl(t_controltab *map, char *str, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] == '1')
	{
		map->width += 1;
		i++;
		if (map->width == x)
			map->perimeter += 1;
	}
	mid_rows_ctrl(map, str, x, y);
}

void	mid_rows_ctrl(t_controltab *map, char *str, int x, int y)
{
	int		i;
	int		j;

	i = x;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\n' && (j + 1) < y && j != 0)
		{
			if (i % (x + 1) == 0 && str[i] == '1' && str[i + (x - 1)] == '1')
				map->perimeter += 1;
			i++;
		}
		i++;
		j++;
	}
	last_row_ctrl(map, str, x, i);
}

void	last_row_ctrl(t_controltab *map, char *str, int x, int i)
{
	i = i - (x + 1);
	while (str[i] != '\0')
	{
		if (str [i] == '1')
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
