/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:00:24 by fmanzana          #+#    #+#             */
/*   Updated: 2022/06/23 18:44:16 by fmanzana         ###   ########.fr       */
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

int		main (int argc, char **argv)
{
	int		tester;
	t_data	data;

	if (argc != 2)
		return (1);
	tester = extension_tester(argv[1]);
	if (!tester)
	{
		printf("Buen nombre de mapa bro!\n");
		data.map.str_map = ft_read_map(argv[1]);
		printf("%s\n", data.map.str_map);
	}
	else
	{
		printf("Nombre de mapa failed!\n");
		return (1);
	}
	
	tester = map_checker(&data.map);
	if (tester == 1)
	{
		printf("Error en la composición del mapa\n");
		return (1);
	}
	else
		printf("El mapa está perfe\n");

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.width * IMG_S,
			data.map.hight * IMG_S, "jueguito_largo!");
//	open_images(&data);
//	close_images(&data);
//	prerender_function(&data);
	mlx_loop(data.mlx_ptr);

	return (0);
}
