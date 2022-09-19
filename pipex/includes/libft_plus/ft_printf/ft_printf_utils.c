/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:47:32 by fmanzana          #+#    #+#             */
/*   Updated: 2022/05/27 18:07:03 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putchar(char c, int *i)
{
	write(1, &c, 1);
	*i += 1;
}

void	ft_putstr(char *str, int *i)
{
	int		j;

	if (!str)
	{
		ft_putstr("(null)", i);
		return ;
	}
	j = 0;
	while (str[j])
		ft_putchar(str[j++], i);
}

void	ft_puthex(unsigned long long nb, int *i, char *base)
{
	if (nb >= 16)
		ft_puthex(nb / 16, i, base);
	ft_putchar(base[nb % 16], i);
}

void	ft_putnbr(int nbr, int *i)
{
	long long	number;

	number = (long long)nbr;
	if (number < 0)
	{
		ft_putchar('-', i);
		number *= -1;
	}
	if (number >= 10)
	{
		ft_putnbr(number / 10, i);
		number %= 10;
	}
	ft_putchar(number + '0', i);
}

void	ft_putui(unsigned int nb, int *i)
{
	if (nb >= 10)
	{
		ft_putui(nb / 10, i);
		nb %= 10;
	}
	ft_putchar(nb + '0', i);
}
