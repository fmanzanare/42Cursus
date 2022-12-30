/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:06:01 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/30 13:16:17 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	command_finder(char **cmd)
{

}

void	command_reader(t_stack ***stk_a, t_stack **stk_b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{

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

	free_stk(stk_a);
	free_stk(stk_b);
	return (0);
}
