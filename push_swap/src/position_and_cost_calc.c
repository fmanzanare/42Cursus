/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_and_cost_calc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:57:36 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/28 12:10:17 by fmanzana         ###   ########.fr       */
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
static int	target_calc(t_stack **stk_a, int b_idx, int t_idx, int t_pos)
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
		if (tmp->index < t_idx)
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
void	assign_pos(t_stack **stk)
{
	t_stack	*tmp;
	int		pos;

	tmp = *stk;
	pos = 0;
	while (tmp)
	{
		tmp->pos = pos;
		tmp = tmp->next;
		pos++;
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

/*
* Calculates the cost of placing the item on top of Stack B
* Also calculates the cost of moving the item on top of Stack A
* Takes into consideration if it is over or under the half of the stack
* @param stk_a Stack A
* @param stk_b Stack B
*/
void	cost_calc(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		a_len;
	int		b_len;

	tmp_a = *stk_a;
	tmp_b = *stk_b;
	a_len = stack_length(tmp_a);
	b_len = stack_length(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > b_len / 2)
			tmp_b->cost_b = (b_len - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target;
		if (tmp_b->target > a_len / 2)
			tmp_b->cost_a = (a_len - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}

/*
* Looks for the cheapest element to be moved from Stack B on top of Stack A
* @param stk_a Stack A
* @param stk_b Stack B
*/
void	calc_cheapest_move(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*tmp;
	int		min;
	int		cost_a;
	int		cost_b;

	tmp = *stk_b;
	min = INT_MAX;
	while (tmp)
	{
		if (abs_value(tmp->cost_a) + abs_value(tmp->cost_b) < abs_value(min))
		{
			min = abs_value(tmp->cost_b) + abs_value(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	moves(stk_a, stk_b, cost_a, cost_b);
}
