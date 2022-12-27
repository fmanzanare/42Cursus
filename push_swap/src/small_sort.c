/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:34:43 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/27 12:13:28 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* Looks for the highest index within the stack
* @param stk Stack to work with
*/
static int		max_index_finder(t_stack *stk)
{
	int		max;

	max = stk->index;
	while (stk)
	{
		if (stk->index > max)
			max = stk->index;
		stk = stk->next;
	}
	return (max);
}

/*
* Algorithm to sort 3 values
* 1. Checks the biggest value through index
* 2. If the first item is the biggest, places it at the end
* 3. If the second item is the biggets, places the last item at the beginning
* 4. Finally, checks if the first item is bigger than the second.
*		if "true", places the second item, at the begining.
* @param stk Stack to work with
*/
void	small_sort(t_stack *stk)
{
	int		max;

	if (check_sorted(stk))
		return ;
	max = max_index_finder(stk);
	if (max == stk->index)
		ra_act(&stk);
	else if (max == stk->next->index)
		rra_act(&stk);
	if (stk->index > stk->next->index)
		sa_act(stk);
}
