/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:49:46 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/28 14:38:14 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* Creates a new node of the list (stack)
* @param num "int" to be assing to the stack
*/
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

/*
* Moves the point to the end of the list (stack bottom)
* @param stk stack to run through
*/
t_stack	*run_to_bottom(t_stack *stk)
{
	while (stk && stk->next != NULL)
		stk = stk->next;
	return (stk);
}

/*
* Adds a new node at the end of the list (stack bottom)
* @param stk stack to work with
* @param new New node to be added
*/
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

/*
* Fill the list with the received arguments.
* If "args" is the first number it fills the first position (stack head).
* The rest of the arguments filled on the following positions (stack tail).
* @param stk stack to be filled
* @param args Arguments received to be converted into "int" through ft_atoi
* @param num_counter Counter to control the number of "int" to be added
*/
t_stack	*fill_stk_a(t_stack *stk, char **args, int num_counter)
{
	long int	num;
	int			i;

	i = 0;
	num = 0;
	while (args[i])
	{
		num = ft_atoli_errexit(args[i], stk);
		if (num > INT_MAX || num < INT_MIN)
			ft_errexit(stk);
		if (!num_counter)
			stk = new_node((int)num);
		else
			stk_add_bottom(&stk, new_node((int)num));
		i++;
	}
	return (stk);
}

/*
* Splits the received "args" by ' '.
* It sends each array of strings to the fill_stk_a function.
* If "args" contains strings and array of strings mixed, it splits it by ' '.
* @param args Arguments received into main function to be splitted
*/
t_stack	*args_splitter_and_stk_filler(char **args)
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
		free_arr(tmp);
		num_counter++;
		i++;
	}
	return (stk);
}
