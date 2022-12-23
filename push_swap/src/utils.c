/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:34:55 by fmanzana          #+#    #+#             */
/*   Updated: 2022/12/23 18:15:54 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* Converts the received "string" to "int" and checks if it has any digit on it.
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

void	ft_errexit(void)
{
	ft_printf("Error\n");
	// Free memory functions!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	exit(1);
}
