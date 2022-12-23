/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stks_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:01:37 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/23 18:33:13 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* Checks if the stack is sorted
* @param stk stack to check
*/
int	check_sorted(t_stack *stk)
{
	while (stk->next != NULL)
	{
		if (stk->num > stk->next->num)
			return (0);
		stk = stk->next;
	}
	return (1);
}

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
	t_stack *max;
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
