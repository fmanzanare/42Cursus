/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:36:02 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/26 20:24:03 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if ((unsigned char) c == '\0')
		return ((char *) s);
	return ((char *) 0);
}
