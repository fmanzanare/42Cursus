/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:41:00 by fmanzana          #+#    #+#             */
/*   Updated: 2022/05/27 18:06:08 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_print_var(const char *str, int *i, va_list args, int j);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, str);
	while (str[j])
	{
		if (str[j] == '%')
		{
			ft_print_var(str, &i, args, j);
			j++;
		}
		else
			ft_putchar(str[j], &i);
		j++;
	}
	va_end(args);
	return (i);
}

void	ft_print_var(const char *str, int *i, va_list args, int j)
{
	if (str[j + 1] == '%')
		ft_putchar('%', i);
	else if (str[j + 1] == 'c')
		ft_putchar(va_arg(args, int), i);
	else if (str[j + 1] == 's')
		ft_putstr(va_arg(args, char *), i);
	else if (str[j + 1] == 'p')
	{
		ft_putstr("0x", i);
		ft_puthex(va_arg(args, unsigned long long), i, "0123456789abcdef");
	}
	else if (str[j + 1] == 'd' || str[j + 1] == 'i')
		ft_putnbr(va_arg(args, int), i);
	else if (str[j + 1] == 'u')
		ft_putui(va_arg(args, unsigned int), i);
	else if (str[j + 1] == 'x')
		ft_puthex(va_arg(args, unsigned int), i, "0123456789abcdef");
	else if (str[j + 1] == 'X')
		ft_puthex(va_arg(args, unsigned int), i, "0123456789ABCDEF");
}
