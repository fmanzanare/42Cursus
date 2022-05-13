/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:28:49 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/26 12:12:09 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (0);
	if (len <= 0 || (start + 1 > ft_strlen(s)))
	{
		dst = (char *)malloc(1);
		*dst = 0;
		return (dst);
	}
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start] != '\0' && i < len)
			dst[i++] = s[start++];
	}
	dst[i] = '\0';
	return (dst);
}
