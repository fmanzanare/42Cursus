/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:06:01 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/30 14:07:12 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	command_finder(char *cmd, t_stack **stk_a, t_stack **stk_b)
{
	if (!ft_strncmp("sa\n", cmd, 4))
		sa_act(stk_a);
	else if (!ft_strncmp("sb\n", cmd, 4))
		sb_act(stk_b);
	else if (!ft_strncmp("ra\n", cmd, 4))
		ra_act(stk_a);
	else if (!ft_strncmp("rb\n", cmd, 4))
		rb_act(stk_b);
	else if (!ft_strncmp("rr\n", cmd, 4))
		rr_act(stk_a, stk_b);
	else if (!ft_strncmp("rra\n", cmd, 5))
		rra_act(stk_a);
	else if (!ft_strncmp("rrb\n", cmd, 5))
		rrb_act(stk_b);
	else if (!ft_strncmp("rrr\n", cmd, 5))
		rrr_act(stk_a, stk_b);
	else if (!ft_strncmp("pb\n", cmd, 4))
		pb_act(stk_a, stk_b);
	else if (!ft_strncmp("pa\n", cmd, 4))
		pa_act(stk_a, stk_b);
	else
		return (0);
	return (1);
}

static void	command_reader(t_stack **stk_a, t_stack **stk_b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (!command_finder(cmd, stk_a, stk_b))
		{
			free_stk(stk_b);
			ft_errexit(*stk_a);
		}
		free(cmd);
		cmd = get_next_line(0);
	}
}

int	main(int argc, char **args)
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	if (argc <= 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	stk_b = NULL;
	stk_a = args_splitter_and_stk_filler(args);
	check_duplicates(stk_a);
	command_reader(&stk_a, &stk_b);
	if (check_sorted(stk_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stk(&stk_a);
	free_stk(&stk_b);
	return (0);
}
