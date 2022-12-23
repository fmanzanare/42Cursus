/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:56:40 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/23 14:28:57 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include"./libft_plus/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

t_stack		*new_node(int num);
t_stack		*run_to_bottom(t_stack *stk);
void		stk_add_bottom(t_stack **stk, t_stack *new);
t_stack		*fill_stk_a(t_stack *stk, char **args, int num_counter);
t_stack		*args_splitter_and_stk_filler(char **args);
long int	ft_atoli_errexit(char *str);
void		ft_errexit(void);

#endif
