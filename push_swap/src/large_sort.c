/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:30:46 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/27 15:37:57 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
			pb_act(stk_b, stk_a);
			push_count++;
		}
		else
			ra_act(stk_a);
		count++;
	}
	while (stk_len - push_count > 3)
	{
		pb_act(stk_b, stk_a);
		push_count++;
	}
}

void	large_sort(t_stack **stk_a, t_stack **stk_b, int stk_len)
{
	push_and_save3(stk_a, stk_b, stk_len);
	small_sort(stk_a);

}
