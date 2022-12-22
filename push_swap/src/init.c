/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:24:34 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/22 19:48:54 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	args_conversor(t_data *data, char **args)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	i = 1;
	k = 0;
	while (args[i])
	{
		j = 0;
		tmp = ft_split(args[i], ' ');
		data->num_mtrx = (char**)malloc(sizeof(tmp));
		while (tmp[j])
		{
			data->num_mtrx[k] = tmp[j];
			ft_printf("Number = %s\n", data->num_mtrx[k]);
			j++;
			k++;
		}
		free(tmp);
		i++;
	}
}

void	init_stack(t_stack *stk)
{
	stk = (t_stack *)malloc(sizeof(t_stack));
	if (stk == NULL)
		exit(1);
	stk->num = 0;
	stk->next = NULL;
	stk->prev = NULL;
}

void	init_data(t_data *data, int argc ,char **args)
{
	data->argc = argc;
	init_stack(data->stk_a);
	init_stack(data->stk_b);
	args_conversor(data, args);
}
