/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:28:49 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/24 12:51:55 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;

	dst = (char *)malloc(len + 1);
	if (!s || !(dst))
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		dst[j++] = s[i++];
	dst[j] = '\0';
	return (dst);
}
