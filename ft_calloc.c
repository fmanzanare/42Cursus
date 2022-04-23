/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:43:01 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/23 21:01:03 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	nb;
	char	*p;
	char	*q;

	nb = count * size;
	i = 0;
	q = malloc(nb);
	p = q;
	if (p != 0)
	{
		while (i < nb)
		{
			*p++ = 0;
			i++;
		}
	}
	return (q);
}
