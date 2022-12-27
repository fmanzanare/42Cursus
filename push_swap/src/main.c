/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:25:34 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/27 19:12:13 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* Chooses the algorith to use acording to the stack length
* Small Sort for stack length = 3
* Long Sort for stack length > 3
* @param stk_a Stack A
* @param stk_b Stack B
* @param stk_len Stack A length
*/
static void	algo_chooser(t_stack **stk_a, t_stack **stk_b, int stk_len)
{
	if (stk_len == 2 && !check_sorted(*stk_a))
		sa_act(*stk_a);
	else if (stk_len == 3)
		small_sort(*stk_a);
	else if (stk_len > 3 && !check_sorted(*stk_a))
		large_sort(stk_a, stk_b, stk_len);
}

// void leaks(void)
// {
// 	system("leaks -q push_swap");
// }

int	main(int argc, char **args)
{
	t_stack		*stk_a;
	t_stack		*stk_b;
	int			stk_len;

	// atexit(leaks);
	if (argc <= 1)
		return (1);
	stk_b = NULL;
	stk_a = args_splitter_and_stk_filler(args);
	stk_len = stack_length(stk_a);
	check_duplicates(stk_a);
	assign_indexes(stk_a, (stk_len + 1));
	algo_chooser(&stk_a, &stk_b, stk_len);
	return (0);
}
