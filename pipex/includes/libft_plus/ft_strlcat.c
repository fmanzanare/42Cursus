/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:31:02 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/26 20:23:09 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	while (src[j] != '\0' && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + srclen);
}
