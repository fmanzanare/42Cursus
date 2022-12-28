/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:46:29 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/28 18:37:55 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* Sends the top element of the stack at the end of the list
* @param stk Stack to work with
*/
static void	rotate(t_stack **stk)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stk;
	*stk = (*stk)->next;
	tail = bottom_node(*stk);
	tmp->next = NULL;
	tail->next = tmp;
}

/*
* Makes "rotate" action over stack A and prints "ra"
* @param stk Stack A
*/
void	ra_act(t_stack **stk)
{
	rotate(stk);
	write(1, "ra\n", 3);
}

/*
* Makes "rotate" action over stack B and prints "rb"
* @param stk Stack B
*/
void	rb_act(t_stack **stk)
{
	rotate(stk);
	write(1, "rb\n", 3);
}

/*
* Makes "rotate" action over stack A and stack B and prints "rr"
* @param stk_a Stack A
* @param stk_b Stack B
*/
void	rr_act(t_stack **stk_a, t_stack **stk_b)
{
	rotate(stk_a);
	rotate(stk_b);
	write(1, "rr\n", 3);
}
