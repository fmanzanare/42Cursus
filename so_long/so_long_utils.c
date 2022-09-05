/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:06:01 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/05 17:00:04 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read_map(char *file)
{
	char	*str;
	int		i;
	int		fd;
	char	tmp;

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

	printf("String length = %i\n\n", i);

	return (str);
}

int	map_checker(t_controltab *map)
{
	if (perimeter_control(map) == 1)
		return (1);
	if (elements_control(map) == 1)
		return (1);
	return (0);
}
