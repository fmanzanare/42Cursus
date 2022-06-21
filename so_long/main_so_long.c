/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:11:40 by fmanzana          #+#    #+#             */
/*   Updated: 2022/06/21 17:13:18 by fmanzana         ###   ########.fr       */
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
	return (0);
}
