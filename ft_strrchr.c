/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:11:43 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/23 14:16:41 by fmanzana         ###   ########.fr       */
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
	while (slen != 0 && *(s + slen) != c)
		slen--;
	if (*(s + slen) == c)
		return ((char *)(s + slen));
	return (0);
}
