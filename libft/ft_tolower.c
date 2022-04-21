/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:29:40 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/21 12:35:15 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<ctype.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/*int	main(void)
{
	char	c;

	c = 'A';
	printf("Original : %c\n", c);
	//printf("tolower : %c\n", tolower(c));
	printf("mytolower : %c\n", ft_tolower(c));
	
	return (0);
}*/
