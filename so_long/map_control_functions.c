/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:50:06 by fmanzana          #+#    #+#             */
/*   Updated: 2022/06/23 18:13:28 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_controltab(t_controltab *map)
{
	map->width = 0;
	map->hight = 0;
	map->player = 0;
	map->collect = 0;
	map->exit = 0;
	map->perimeter = 0;
}

int	perimeter_control(t_controltab *map)
{
	int		perimeter_chkr;

	init_controltab(map);
	perimeter_chkr = columns_rows_and_check(map);
	return (perimeter_chkr);
}

int	elements_control(t_controltab *map)
{
	int		i;

	i = 0;
	while (map->str_map[i] != '\0')
	{
		if (map->str_map[i] == 'P')
			map->player += 1;
		else if (map->str_map[i] == 'C')
			map->collect += 1;
		else if (map->str_map[i] == 'E')
			map->exit += 1;
		i++;
	}

	printf("Players = %i\n", map->player);
	printf("Collectables = %i\n", map->collect);
	printf("Exits = %i\n\n", map->exit);
	if (map->player != 1)
		return (1);
	else if (map->collect < 1)
		return (1);
	else if (map->exit != 1)
		return (1);
	return (0);
}
