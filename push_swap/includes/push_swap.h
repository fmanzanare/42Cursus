/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:56:40 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/23 12:53:27 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include"./libft_plus/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_data
{
	char			**num_mtrx;
	int				argc;
	t_stack			*stk_a;
	t_stack			*stk_b;
}	t_data;

int		ft_error(t_data *data);
void	init_data(t_data *data, int args, char **argv);
void	init_stack(t_stack *stk);
int		ft_atoi_errexit(char *str);
void	ft_errexit(void);

#endif
