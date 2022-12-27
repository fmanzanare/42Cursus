/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:34:55 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/27 19:24:39 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* Converts the received "string" to "long int".
* It also checks if it has any digits on it.
* If no digits are found, it goes directly to Error Exit.
* @param str String to convert into "int"
*/
long int	ft_atoli_errexit(char *str)
{
	long int			num;
	int					sign;
	int					digit_found;

	digit_found = 0;
	sign = 1;
	num = 0;
	if (!*str)
		ft_errexit();
	while (ft_isspecialchar(*str))
		str++;
	if (ft_issign(*str) == -1)
		sign = -1;
	if (ft_issign(*str))
		str++;
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
		digit_found = 1;
	}
	if (!digit_found)
		ft_errexit();
	num *= sign;
	return (num);
}

/*
* Checks if the stack is sorted
* @param stk stack to check
*/
int	check_sorted(t_stack *stk)
{
	while (stk->next != NULL)
	{
		if (stk->num > stk->next->num)
			return (0);
		stk = stk->next;
	}
	return (1);
}

/*
* Goes through the numbers contained into stack to check duplicates.
* If duplicates are found it goes directly to Error exit.
* @param stk Stack to be checked
*/
void	check_duplicates(t_stack *stk)
{
	t_stack	*fixed;
	t_stack	*nav;

	if (!stk)
		return ;
	fixed = stk;
	while (fixed->next)
	{
		nav = fixed->next;
		while (nav)
		{
			if (nav->num == fixed->num)
				ft_errexit();
			nav = nav->next;
		}
		fixed = fixed->next;
	}
}

/*
* Returns the absolute value of a number
* @param num Number to work with
*/
int	abs_value(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

void	ft_errexit(void)
{
	ft_printf("Error\n");
	// Free memory functions!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	exit(1);
}
