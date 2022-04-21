/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:36:02 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/21 16:09:12 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	return (0);
}
/*int	main(void)
{
	char	str[] = "Hello World, what are you doing?";
	char	c = 'W';

	printf("String : %s | Char : %c\n", str, c);
	//printf("Resultado : %s\n", strchr(str, c));
	printf("mystrchr : %s\n", ft_strchr(str, c));

	return (0);
}*/
