/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:49:46 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/23 11:13:01 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_value(int	num)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(new));
	new->num = num;
	new->next = NULL;
	return (new);
}
