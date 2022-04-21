/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:55:29 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/21 20:08:41 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *) s)[i] == (unsigned char) c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
/*int	main(void)
{
	char	str[] = "Hello World";
	int		c = 'o';

	printf("String : %s | Char : %c\n", str, c);
	printf("memchr : %s\n", memchr(str, c, strlen(str)));
	printf("mymemchr : %s\n", ft_memchr(str, c, strlen(str)));

	return (0);
}*/
