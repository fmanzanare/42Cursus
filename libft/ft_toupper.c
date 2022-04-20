/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:21:19 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/20 20:27:18 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<ctype.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
		return (c);
	}
	else
		return (0);
}
/*int	main(void)
{
	int	c;

	c = 'a';
	printf("Original : %c\n", c);
	//printf("Modificado : %c\n", toupper(c));
	
	printf("mytoupper : %c\n", ft_toupper(c));

	return (0);
}*/
