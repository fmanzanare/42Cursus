/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:25:34 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/22 16:20:57 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

static int	args_checker(int argc, char **args)
{
	int		i;
	int		j;
	char	**matrix;

	if (argc <= 1)
		return (ft_error());
	i = 1;
	j = 0;
	while (args[i])
	{
		matrix = ft_split(args[i], ' ');
		while (matrix[j])
		{
			if (!ft_atoi(matrix[j]))
				return (ft_error());
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	main(int argc, char **args)
{
	if (!args_checker(argc, args))
		return (-1);
	return (0);
}
