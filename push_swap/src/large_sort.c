/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:30:46 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/28 13:40:49 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* Pushes the values to Stack B saving 3
* It checks if the value is on the first half of the stack to send it first
* Otherwise, it send it to the bottom of Stack A
* When finished, stack B will have all the values, except 3
* @param stk_a Stack A
* @param stk_b Stack B
* @param stk_len Stack A length
*/
static void	push_and_save3(t_stack **stk_a, t_stack **stk_b, int stk_len)
{
	int		push_count;
	int		count;

	push_count = 0;
	count = 0;
	while (stk_len > 6 && count < stk_len && push_count < stk_len / 2)
	{
		if ((*stk_a)->index <= stk_len / 2)
		{
			pb_act(stk_a, stk_b);
			push_count++;
		}
		else
			ra_act(stk_a);
		count++;
	}
	while (stk_len - push_count > 3)
	{
		pb_act(stk_a, stk_b);
		push_count++;
	}
}

static void	drift_stack(t_stack **stk_a)
{
	int		min_idx_pos;
	int		stk_len;

	stk_len = stack_length(*stk_a);
	min_idx_pos = min_index_pos(stk_a);
	if (min_idx_pos > stk_len / 2)
	{
		while (min_idx_pos < stk_len)
		{
			rra_act(stk_a);
			min_idx_pos++;
		}
	}
	else
	{
		while (min_idx_pos > 0)
		{
			ra_act(stk_a);
			min_idx_pos--;
		}
	}
}

/*
* Receives the Stacks and applies the sort "Algo" for long Stacks (>3)
* First of all sends all the values to Stack B, saving 3 on Stack A
* Applies a small sort "Algo" for values contained on Stack A
* Then applies the large "Algo", assigning indexis and calculating costs
* It also moves the values according to the "Algo" and then checks if sorted
* If it is not sorted, it sends Stack A to be drifted
* @param stk_a Stack A
* @param stk_b Stack B
* @param stk_len Stack A length
*/
void	large_sort(t_stack **stk_a, t_stack **stk_b, int stk_len)
{
	push_and_save3(stk_a, stk_b, stk_len);
	small_sort(stk_a);
	while (*stk_b)
	{
		assing_target_pos(stk_a, stk_b);
		cost_calc(stk_a, stk_b);
		calc_cheapest_move(stk_a, stk_b);
	}
	if (!check_sorted(*stk_a))
		drift_stack(stk_a);
}
