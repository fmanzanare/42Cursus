/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:06:26 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/28 18:37:11 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* Places the last element at the begining of the list
* @param stk Stack to work with
*/
static void	reverse_rotate(t_stack **stk)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*prev_tail;

	tail = bottom_node(*stk);
	prev_tail = before_bottom_node(*stk);
	tmp = *stk;
	*stk = tail;
	(*stk)->next = tmp;
	prev_tail->next = NULL;
}

/*
* Makes "reverse rotate" to Stack A and prints "rra"
* @param stk Stack A
*/
void	rra_act(t_stack **stk)
{
	reverse_rotate(stk);
	write(1, "rra\n", 4);
}

/*
* Makes "reverse rotate" to Stack B and prints "rrb"
* @param stk Stack B
*/
void	rrb_act(t_stack **stk)
{
	reverse_rotate(stk);
	write(1, "rrb\n", 4);
}

/*
* Makes "reverse rotate" to Stack A and Stack B and prints "rrr"
* @param stk Stack A
* @param stk Stack B
*/
void	rrr_act(t_stack **stk_a, t_stack **stk_b)
{
	reverse_rotate(stk_a);
	reverse_rotate(stk_b);
	write(1, "rrr\n", 4);
}
