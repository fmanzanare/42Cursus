/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:57:36 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/27 14:41:07 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* Calculates the "target pos" of the stack B elements to be placed on Stack A
* It is done comparing the index values of the stacks elements
* @param stk_a Stack A
* @param b_idx Index of Stack B element
* @param t_idx Target index
* @param t_pos Target position to be returned and assigned
*/
static int		target_calc(t_stack **stk_a, int b_idx, int t_idx, int t_pos)
{
	t_stack		*tmp;

	tmp = *stk_a;
	while (tmp)
	{
		if (tmp->index > b_idx && tmp->index < t_idx)
		{
			t_idx = tmp->index;
			t_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (t_idx != INT_MAX)
		return (t_pos);
	tmp = *stk_a;
	while (tmp)
	{
		if (tmp->index < b_idx)
		{
			t_idx = tmp->index;
			t_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (t_pos);
}

/*
* Assigns the current position to the elements of the Stack
* @param stk Stack to work with
*/
static void		assign_pos(t_stack **stk)
{
	t_stack	*tmp;
	int		pos;

	tmp = *stk;
	pos = 0;
	while (tmp)
	{
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
}

/*
* Assign the current positions of Stack A and Stack B elements
* Calculates the "target pos" of Stack B elements to be placed Stack A
* @param stk_a Stack A
* @param stk_b Stack B
*/
void	assing_target_pos(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*tmp_b;
	int		t_pos;

	tmp_b = *stk_b;
	t_pos = 0;
	assign_pos(stk_a);
	assign_pos(stk_b);
	while (tmp_b)
	{
		t_pos = target_calc(stk_a, tmp_b->index, INT_MAX, t_pos);
		tmp_b->target = t_pos;
		tmp_b = tmp_b->next;
	}
}
