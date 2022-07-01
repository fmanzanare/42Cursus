/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:00:24 by fmanzana          #+#    #+#             */
/*   Updated: 2022/07/01 16:56:16 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		extension_tester(char *argv)
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

int		testers_function(t_controltab *map, int argc, char **argv)
{
	int		tester;

	if (argc != 2)
		return (1);
	tester = extension_tester(argv[1]);
	if (tester == 1)
	{
		printf("Error en la extensión del mapa\n");
		return (1);
	}
	else
		printf("Buen nombre de mapa bro!\n");
	tester = map_checker(map);
	if (tester == 1)
	{
		printf ("Error en la composición del mapa\n");
		return (1);
	}
	else
		printf("El mapa está perfe!\n");
	return (0);
}

int		main (int argc, char **argv)
{
	t_data	data;

	data.map.str_map = ft_read_map(argv[1]);
	printf("%s\n", data.map.str_map);
	if (testers_function(&data.map, argc, argv) == 1)
		return (1);

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.width * IMG_S,
			data.map.hight * IMG_S, "jueguito_largo!");
	printf("mlx_ptr = %p\n", data.mlx_ptr);
	printf("win_ptr = %p\n", data.win_ptr);
	printf("wall = %p\n", data.img.type.wall);
	open_images(&data);
	pre_print_map(&data);
//	mlx_key_hook(data.win_ptr, (*close_window)(27, &data), &data);
//	close_images(&data);
	mlx_loop(data.mlx_ptr);

	return (0);
}
