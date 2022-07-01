/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:11:43 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/26 20:24:08 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = 0;
	while (s[slen] != '\0')
		slen++;
	if ((unsigned char) c == '\0')
		return ((char *) s + slen);
	while (slen-- > 0)
	{
		if (*(s + slen) == (unsigned char) c)
			return ((char *)(s + slen));
	}
	return ((char *) 0);
}
