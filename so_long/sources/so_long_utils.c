/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:06:01 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/13 11:06:13 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	lines_len_control(t_data *data)
{
	int	first_line_len;
	int	i;
	int	j;

	first_line_len = 0;
	while (data->map.str_map[first_line_len] != '\n')
	{
		first_line_len++;
	}
	i = 0;
	while (data->map.str_map[i] != '\0')
	{
		j = 0;
		while (data->map.str_map[i] != '\n')
		{
			i++;
			j++;
		}
		if (j != first_line_len)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	print_moves_counter(t_data *data)
{
	ft_printf("Moves = %i\n", data->map.moves_counter);
}
