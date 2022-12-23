/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stks_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:01:37 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/23 16:32:02 by fmanzana         ###   ########.fr       */
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
