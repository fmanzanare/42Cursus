/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:56:54 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/20 16:29:49 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize -1)
	{
		if (*src != '\0')
			*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (i);
}
/*int	main(void)
{
	char	src[] = "Hello World!!!!!!!";
	char	dst[] = "Hola Mundo!!!";

	printf("Original src : %s\n", src);
	printf("Original dst : %s\n", dst);
	
	//strlcpy(dst, src, strlen(dst));
	//printf("strlcpy dst : %s\n", dst);

	ft_strlcpy(dst, src, strlen(dst));
	printf("mystrlcpy dst : %s\n", dst);

	return (0);
}*/
