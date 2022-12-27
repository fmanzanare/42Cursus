/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stks_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:01:37 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/27 17:40:54 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* Measures the lenght of the list (stack)
* @param stk stack to measure
*/
int	stack_length(t_stack *stk)
{
	int	stk_length;

	stk_length = 0;
	if (!stk)
		return (0);
	while (stk)
	{
		stk = stk->next;
		stk_length++;
	}
	return (stk_length);
}

/*
* Assigns indexes to the numbers contained in stack.
* It goes from the end (stk_len) to the start (1).
* Compares all the nodes to get the biggest and assigns the (stk_len) as index.
* @param stk stack to work with
* @param stk_len stack length
*/
void	assign_indexes(t_stack *stk, int stk_len)
{
	t_stack	*tmp;
	t_stack	*max;
	int		val;

	while (--stk_len > 0)
	{
		val = INT_MIN;
		tmp = stk;
		max = NULL;
		while (tmp)
		{
			if (tmp->num == INT_MIN && !tmp->index)
				tmp->index = 1;
			if (tmp->num > val && !tmp->index)
			{
				val = tmp->num;
				max = tmp;
				tmp = stk;
			}
			else
				tmp = tmp->next;
		}
		if (max)
			max->index = stk_len;
	}
}

/*
* Puts the stack pointer at the end of the list and returns it.
* @param stk Stack to work with
*/
t_stack	*bottom_node(t_stack *stk)
{
	while (stk && stk->next)
		stk = stk->next;
	return (stk);
}

/*
* Place the stack pointer one position before the end of the list.
* @param stk Stack to work with
*/
t_stack	*before_bottom_node(t_stack *stk)
{
	while (stk && stk->next && stk->next->next)
		stk = stk->next;
	return (stk);
}

/*
* Looks for the lowest index within the Stack and returns its position
* @param stk Stack to work with
*/
int	min_index_pos(t_stack **stk)
{
	t_stack	*tmp;
	int		min_index;
	int		min_pos;

	tmp = *stk;
	min_index = INT_MAX;
	assign_pos(stk);
	min_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (min_pos);
}
