/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:56:40 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/27 17:40:15 by fmanzana         ###   ########.fr       */
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
t_stack		*bottom_node(t_stack *stk);
t_stack		*before_bottom_node(t_stack *stk);
int			min_index_pos(t_stack **stk);
/* Utils */
void		check_duplicates(t_stack *stk);
int			check_sorted(t_stack *stk);
long int	ft_atoli_errexit(char *str);
int			abs_value(int num);
void		ft_errexit(void);
/* Positions and Cost Calculator */
void		assign_pos(t_stack **stk);
void		assing_target_pos(t_stack **stk_a, t_stack **stk_b);
void		cost_calc(t_stack **stk_a, t_stack **stk_b);
void		calc_cheapest_move(t_stack **stk_a, t_stack **stk_b);
/* Movements */
void		moves(t_stack **stk_a, t_stack **stk_b, int cost_a, int cost_b);
/* Push-Swap Movements */
/* Swap */
void		sa_act(t_stack *stk);
void		sb_act(t_stack *stk);
void		ss_act(t_stack *stk_a, t_stack *stk_b);
/* Rotate */
void		ra_act(t_stack **stk);
void		rb_act(t_stack **stk);
void		rr_act(t_stack **stk_a, t_stack **stk_b);
/* Reverse Rotate */
void		rra_act(t_stack **stk);
void		rrb_act(t_stack **stk);
void		rrr_act(t_stack **stk_a, t_stack **stk_b);
/* Push */
void		pa_act(t_stack **stk_a, t_stack **stk_b);
void		pb_act(t_stack **stk_b, t_stack **stk_a);
/* Algorithms */
/* Small Sort */
void		small_sort(t_stack *stk);
/* Large Sort */

#endif
