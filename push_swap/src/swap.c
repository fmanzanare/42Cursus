/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:43:09 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/28 18:39:02 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*	Swaps the top position on a stack
* 	@param stk stack to work with
*/
static void	swap(t_stack *stk)
{
	int		tmp;

	if (!stk || !stk->next)
		return ;
	tmp = stk->num;
	stk->num = stk->next->num;
	stk->next->num = tmp;
	tmp = stk->index;
	stk->index = stk->next->index;
	stk->next->index = tmp;
}

/*
* Swaps top position of stack A and prints "sa"
* @param stk Stack A
*/
void	sa_act(t_stack **stk)
{
	swap(*stk);
	write(1, "sa\n", 3);
}

/*
* Swaps top position of stack B and prints "sb"
* @param stk Stack B
*/
void	sb_act(t_stack **stk)
{
	swap(*stk);
	write(1, "sb\n", 3);
}

/*
* Swaps top position of stack A and stack B and prints "ss"
* @param stk_a Stack A
* @param stk_b Stack B
*/
void	ss_act(t_stack **stk_a, t_stack **stk_b)
{
	swap(*stk_a);
	swap(*stk_b);
	write(1, "ss\n", 3);
}
