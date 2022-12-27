/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:56:40 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/27 11:15:12 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft_plus/libft.h"
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

/* Stacks Initialization */
t_stack		*new_node(int num);
t_stack		*run_to_bottom(t_stack *stk);
void		stk_add_bottom(t_stack **stk, t_stack *new);
t_stack		*fill_stk_a(t_stack *stk, char **args, int num_counter);
t_stack		*args_splitter_and_stk_filler(char **args);
/* Stacks Utils */
void		assign_indexes(t_stack *stk, int stk_len);
int			stack_length(t_stack *stk);
int			check_sorted(t_stack *stk);
t_stack		*bottom_node(t_stack *stk);
t_stack		*before_bottom_node(t_stack *stk);
/* Push-Swap Movements */
/* Swap */
void		sa_act(t_stack *stk);
void		sb_act(t_stack *stk);
void		ss_act(t_stack *stk_a, t_stack *stk_b);
/* Rotate */
void		ra_act(*stk);
void		rb_act(*stk);
void		rr_act(*stk_a, *stk_b);
/* Reverse Rotate */
void		rra_act(t_stack *stk);
void		rrb_act(t_stack *stk);
void		rrr_act(t_stack *stk_a, t_stack *stk_b);
/* Utils */
void		check_duplicates(t_stack *stk);
long int	ft_atoli_errexit(char *str);
void		ft_errexit(void);

#endif
