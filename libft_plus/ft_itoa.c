/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:21:33 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/25 15:39:02 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(long nb);

char	*ft_itoa(int n)
{
	long	nb;
	char	*dst;
	int		i;

	nb = n;
	i = intlen(nb);
	dst = (char *)malloc(sizeof(char) * (intlen(nb) + 1));
	if (!dst)
		return (0);
	dst[i--] = '\0';
	if (nb == 0)
		dst[0] = '0';
	if (nb < 0)
	{
		dst[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		dst[i--] = '0' + (nb % 10);
		nb = nb / 10;
	}
	return (dst);
}

static int	intlen(long nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		len = 1;
	else if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
