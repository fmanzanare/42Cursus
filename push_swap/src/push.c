/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:14:05 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/28 18:36:19 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* Puts the first item of "Stack Source" on top of "Stack Dest"
* @param stk_src Stack Source
* @param stk_dst Stack Dest
*/
static void	push(t_stack **stk_src, t_stack **stk_dst)
{
	t_stack	*tmp;

	if (*stk_src == NULL)
		return ;
	tmp = (*stk_src)->next;
	(*stk_src)->next = *stk_dst;
	*stk_dst = *stk_src;
	*stk_src = tmp;
}

/*
* Puts the top element of Stack B on top of Stack A
* @param stk_a Stack A
* @param stk_b Stack B
*/
void	pa_act(t_stack **stk_a, t_stack **stk_b)
{
	push(stk_b, stk_a);
	write(1, "pa\n", 3);
}

/*
* Puts the top element of Stack A on top of Stack B
* @param stk_b Stack B
* @param stk_a Stack A
*/
void	pb_act(t_stack **stk_a, t_stack **stk_b)
{
	push(stk_a, stk_b);
	write(1, "pb\n", 3);
}
