/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:54:57 by fmanzana          #+#    #+#             */
/*   Updated: 2022/06/21 14:31:59 by fmanzana         ###   ########.fr       */
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

int		perimeter_control(t_controltab *map, char *str)
{
	int		perimeter_chkr;

	init_controltab(map);
	perimeter_chkr = columns_rows_and_check(map, str);
	return (perimeter_chkr);
}

int		elements_control(t_controltab *map, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'P')
			map->player += 1;
		else if (str[i] == 'C')
			map->collect += 1;
		else if (str[i] == 'E')
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
