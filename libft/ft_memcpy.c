/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:51:28 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/20 12:15:06 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*csrc;
	char	*cdst;
	size_t	i;

	csrc = (char *)src;
	cdst = (char *)dst;
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
/*int	main(void)
{
	const char	src[50] = "Hello World";
	char		dest[50] = "Hola Mundo";

	printf("dest orig : %s\n", dest);
	memcpy(dest, src, strlen(src)+1);
	printf("dest modif : %s\n", dest);

	ft_memcpy(dest, src, strlen(src)+1);
	printf("mymemcpy : %s\n", dest);

	return (0);
}*/
