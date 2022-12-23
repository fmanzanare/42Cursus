/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:49:46 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/23 14:24:43 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(int num)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->num = num;
	new->index = 0;
	new->pos = -1;
	new->target = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

t_stack		*run_to_bottom(t_stack *stk)
{
	while (stk && stk->next != NULL)
		stk = stk->next;
	return (stk);
}

void	stk_add_bottom(t_stack **stk, t_stack *new)
{
	t_stack		*tail;

	if (!new)
		return ;
	if (!*stk)
	{
		*stk = new;
		return ;
	}
	tail = run_to_bottom(*stk);
	tail->next = new;
}

t_stack	*fill_stk_a(t_stack *stk, char **args, int num_counter)
{
	long int	num;
	int			i;

	i = 0;
	num = 0;
	while (args[i])
	{
		num = ft_atoli_errexit(args[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_errexit();
		if (!num_counter)
			stk = new_node((int)num);
		else
			stk_add_bottom(&stk, new_node((int)num));
		i++;
	}
	return (stk);
}

t_stack	*args_splitter(char **args)
{
	t_stack	*stk;
	char	**tmp;
	int		i;
	int		num_counter;

	stk = NULL;
	i = 1;
	num_counter = 0;
	while (args[i])
	{
		tmp = ft_split(args[i], ' ');
		stk = fill_stk_a(stk, tmp, num_counter);
		free(tmp);
		num_counter++;
		i++;
	}
	return (stk);
}
