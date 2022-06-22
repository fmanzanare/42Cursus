/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:11:40 by fmanzana          #+#    #+#             */
/*   Updated: 2022/06/22 17:39:29 by fmanzana         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int				tester;
	char			*str_map;
	t_controltab	map;
	t_data			data;

	if (argc != 2)
		return (1);
	tester = extension_tester(argv[1]);
	if (!tester)
	{
		printf("Buen nombre de mapa bro!\n");
		str_map = ft_read_map(argv[1]);
		printf("%s\n", str_map);
	}
	else
	{
		printf("Nombre de mapa failed!\n");
		return (1);
	}

	tester = map_checker(&map, str_map);
	if (tester == 1)
	{
		printf("Error en la composición del mapa!\n");
		return (1);
	}
	else if (tester == 0)
		printf("El mapa esta PERFE!\n");
	
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HIGHT,"jueguito largo!");
	
	open_images(&data);
	render_function(&data, str_map);
	
	mlx_loop(data.mlx_ptr);
	close_images(&data);

	return (0);
}
