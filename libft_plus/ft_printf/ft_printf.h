/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:18:44 by fmanzana          #+#    #+#             */
/*   Updated: 2022/05/27 18:05:45 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

void	ft_putchar(char c, int *i);
void	ft_putstr(char *str, int *i2);
void	ft_puthex(unsigned long long nb, int *i, char *base);
void	ft_putnbr(int nb, int *i);
void	ft_putui(unsigned int nb, int *i);
int		ft_printf(const char *str, ...);

#endif
