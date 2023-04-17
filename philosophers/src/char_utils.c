/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:36:25 by fmanzana          #+#    #+#             */
/*   Updated: 2023/04/17 17:38:15 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isspecialchar(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\f' || c == '\r'
		|| c == '\n' || c == '\v')
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	int		check;

	if (c >= 48 && c <= 57)
		check = 1;
	else
		check = 0;
	return (check);
}

int	ft_issign(char c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (-1);
	else
		return (0);
}
