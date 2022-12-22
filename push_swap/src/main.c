/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:25:34 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/22 15:10:16 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	args_checker(int argc, char **args)
{
	int		i;

	i = 0;
	if (argc <= 1)
		return (-1);
	while (args[i])
	{
		if (!ft_atoi(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **args)
{
	char	**matrix;

	matrix = ft_split(args[1], ' ');
	if (!args_checker(argc, matrix))
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (0);
}
