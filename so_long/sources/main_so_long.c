/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:00:24 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/16 15:01:21 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	extension_tester(char *argv)
{
	int	map_name_len;

	map_name_len = ft_strlen(argv);
	map_name_len -= 1;
	if (argv[map_name_len--] == 'r')
		if (argv[map_name_len--] == 'e')
			if (argv[map_name_len--] == 'b')
				if (argv[map_name_len--] == '.')
					return (0);
	return (1);
}

int	testers_function(t_controltab *map, int argc, char **argv)
{
	int		tester;

	if (argc != 2)
	{
		return (1);
	}
	tester = extension_tester(argv[1]);
	if (tester == 1)
	{
		ft_printf("Error\nNombre de mapa erróneo\n");
		return (1);
	}
	tester = map_checker(map);
	if (tester == 1)
	{
		ft_printf ("Error\nComposición de mapa errónea\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.map.str_map = ft_read_map(argv[1]);
	if (!data.map.str_map)
		return (0);
	if (testers_function(&data.map, argc, argv) == 1)
	{
		free(data.map.str_map);
		return (1);
	}
	if (lines_len_control(&data) == 1)
	{
		free(data.map.str_map);
		ft_printf("Error\nComposición de mapa errónea\n");
		return (1);
	}
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.width * IMG_S,
			data.map.hight * IMG_S, "so_long");
	open_images(&data);
	pre_print_map(&data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_hook(data.win_ptr, 2, 0, input, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
