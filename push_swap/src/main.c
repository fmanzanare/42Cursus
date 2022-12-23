/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:25:34 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/23 17:05:55 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static void print_stack(t_stack *stk)
// {
// 	while (stk)
// 	{
// 		ft_printf("Number = %i\n", stk->num);
// 		stk = stk->next;
// 	}
// }

static void	algo_chooser(t_stack **stk_a, t_stack **stk_b, int stk_len)
{
	stk_b = NULL;

	if (stk_len == 2 && !check_sorted(*stk_a))
		sa_act(*stk_a);
}

// void leaks(void)
// {
// 	system("leaks -q push_swap");
// }

int	main(int argc, char **args)
{
	// atexit(leaks);
	t_stack		*stk_a;
	t_stack		*stk_b;
	int			stk_len;

	if (argc <= 1)
		ft_errexit();
	stk_b = NULL;
	stk_a = args_splitter_and_stk_filler(args);
	stk_len = stack_length(stk_a);
	algo_chooser(&stk_a, &stk_b, stk_len);
	if(check_sorted(stk_a))
		ft_printf("The stack is sorted!\n");
	else
		ft_printf("The stack is NOT sorted\n");
	return (0);
}
