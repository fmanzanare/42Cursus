/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:06:26 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/27 11:14:20 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* Places the last element at the begining of the list
* @param stk Stack to work with
*/
static void	reverse_rotate(t_stack *stk)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*prev_tail;

	tail = bottom_node(stk);
	prev_tail = before_bottom_node(stk);
	tmp = stk;
	stk = tail;
	stk->next = tmp;
	prev_tail = NULL;
}

/*
* Makes "reverse rotate" to Stack A and prints "rra"
* @param stk Stack A
*/
void	rra_act(t_stack *stk)
{
	reverse_rotate(stk);
	ft_printf("rra\n");
}

/*
* Makes "reverse rotate" to Stack B and prints "rrb"
* @param stk Stack B
*/
void	rrb_act(t_stack *stk)
{
	reverse_rotate(stk);
	ft_printf("rrb\n");
}

/*
* Makes "reverse rotate" to Stack A and Stack B and prints "rrr"
* @param stk Stack A
* @param stk Stack B
*/
void	rrr_act(t_stack *stk_a, t_stack *stk_b)
{
	reverse_rotate(stk_a);
	reverse_rotate(stk_b);
	ft_printf("rrr\n");
}
