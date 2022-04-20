/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:17:46 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/20 15:55:50 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			((unsigned char *)dst)[len -1] = ((unsigned char *)src)[len -1];
			len--;
		}
	}
	return (dst);
}
/*int	main(void)
{
	char	src[100] = "Hello World";

	printf("Original dst : %s\n", src);
	//memmove(src+6, src, strlen(src)+1);
	//printf("Modificado dst: %s\n", src);
	ft_memmove(src+6, src, strlen(src)+1);
	printf("Modificado dst : %s\n", src);

	return (0);
}*/
