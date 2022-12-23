/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:25:34 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/23 14:29:18 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void leaks(void)
// {
// 	system("leaks -q push_swap");
// }

int	main(int argc, char **args)
{
	// atexit(leaks);
	t_stack		*stk_a;
	t_stack		*stk_b;

	if (argc <= 1)
		ft_errexit();
	stk_b = NULL;
	stk_a = args_splitter_and_stk_filler(args);
	while (stk_a != NULL)
	{
		ft_printf("Number = %i\n", stk_a->num);
		stk_a = stk_a->next;
	}

	return (0);
}
