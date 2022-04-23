/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:31:02 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/23 19:50:27 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	int		i;

	i = 0;
	dstlen = 0;
	srclen = 0;
	while (dst[dstlen] != '\0')
		dstlen++;
	while (src[srclen] != '\0')
		srclen++;
	if (dstlen >= dstsize)
		return (dstsize + srclen);
	if (dstsize)
		i = 1;
	dst = dst + dstlen;
	while ((dstsize - dstlen - 1) && *src)
	{
		*dst++ = *src++;
		dstsize--;
	}
	if (i)
		*dst = 0;
	return (dstlen + srclen);
}
