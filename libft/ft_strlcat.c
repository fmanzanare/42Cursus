/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:31:02 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/20 18:19:17 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	i;

	i = 0;
	dlen = 0;
	while (dst[dlen] != '\0')
		dlen++;
	if (!src || !*src)
		return (dlen);
	while (i < dstsize - dlen - 1 && src[i])
	{
		dst[i + dlen] = src[i];
		i++;
	}
	dst[i + dlen] = 0;
	return (i + dlen);
}
/*int	main(void)
{
	char	src[100] = "a potencially long string";
	//char	src[] = "";
	char	dst[30] = "This is ";

	printf("Original src : %s\n", src);
	printf("Original dst : %s\n", dst);

	//strlcat(dst, src, sizeof(dst));
	//printf("strlcat dst : %s\n", dst);

	ft_strlcat(dst, src, sizeof(dst));
	printf("mystrlcat dst : %s\n", dst);
	
	return (0);
}*/
