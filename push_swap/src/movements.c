/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:39:58 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/27 17:50:11 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* Reverse rotate both Stacks until one of them is on the correct "pos"
* @param a Stack A
* @param b Stack B
* @param cost_a Cost of placing in "pos" on Stack A
* @param cost_b Cost of placing in "pos" on Stack B
*/
static void	rev_rotate(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr_act(a, b);
	}
}

/*
* Rotate both Stacks until one of them is on the correct "pos"
* @param a Stack A
* @param b Stack B
* @param cost_a Cost of placing in "pos" on Stack A
* @param cost_b Cost of placing in "pos" on Stack B
*/
static void	rotate(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr_act(a, b);
	}
}

/*
* Rotates item on Stack A until it is in correct "pos"
* @param a Stack A
* @param cost_a Cost of placing in "pos" on Stack A
*/
static void	rotate_a(t_stack **a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			ra_act(a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			rra_act(a);
			(*cost_a)++;
		}
	}
}

/*
* Rotates item on Stack B until it is in correct "pos"
* @param b Stack B
* @param cost_b Cost of placing in "pos" on Stack B
*/
static void	rotate_b(t_stack **b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			rb_act(b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			rrb_act(b);
			(*cost_b)++;
		}
	}
}

/*
* Chosses movement to get the Stack B item in the correct "pos" on Stack A
* @param stk_a Stack A
* @param stk_b Stack B
* @param cost_a
* @param cost_b
*/
void	moves(t_stack **stk_a, t_stack **stk_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate(stk_a, stk_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate(stk_a, stk_b, &cost_a, &cost_b);
	rotate_a(stk_a, &cost_a);
	rotate_b(stk_b, &cost_b);
	pa_act(stk_a, stk_b);
}
