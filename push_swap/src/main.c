/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:25:34 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/23 13:00:22 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* ft to print the Error message in Stdout and return 0 to control in main */
// int	ft_error(t_data *data)
// {
// 	free(data);
// 	ft_putstr_fd("Error\n", 2);
// 	return (0);
// }

/* ft that checks if the number of arguments is correct */
/* It also checks if the arguments are valid (i.e. 0 or invalid chars) */
// static int	args_checker(t_data *data)
// {
// 	int		i;

// 	if (data->argc <= 1)
// 		return (0);
// 	i = 0;
// 	while (data->num_mtrx[i])
// 	{
// 		ft_printf("hola\n");
// 		ft_printf("Number = %i\n", ft_atoi(data->num_mtrx[i]));
// 		if (!ft_atoi(data->num_mtrx[i]))
// 		{
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// void leaks(void)
// {
// 	system("leaks -q push_swap");
// }

int	main(int argc, char **args)
{
	// t_data		data;
	// t_stack		*stk_a;
	// t_stack		*stk_b;

	// atexit(leaks);
	// init_data(&data, argc, args);
	// if (!args_checker(&data))
	// 	return (-1);
	int i;

	i = 1;
	ft_printf("Argc = %i\n", argc);
	while (args[i])
	{
		ft_printf("Number = %i\n", ft_atoi_errexit(args[i]));
		i++;
	}
	return (0);
}
