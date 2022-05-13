/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:51:30 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/26 20:22:00 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<strings.h>

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	i;

	i = 0;
	c = s;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}
