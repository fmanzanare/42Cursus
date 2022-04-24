/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:50:52 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/24 12:11:58 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*test;
	char	*p;
	int		len;

	len = 0;
	while (s1[len] != '\0')
		len++;
	test = (char *)malloc(len +1);
	if (!test)
		return (0);
	str = malloc(len + 1);
	p = str;
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (str);
}
