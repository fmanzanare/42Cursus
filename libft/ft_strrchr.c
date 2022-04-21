/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:11:43 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/21 16:26:00 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (*s != '\0')
		s++;
	s--;
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *) s);
		s--;
	}
	return (0);
}
/*int main(void)
{
	char	str[] = "Hello World, What are you doing?";
	char	c = 'W';

	printf("Original : %s | Char : %c\n", str, c);
	//printf("strrchr : %s\n", strrchr(str, c));
	printf("mystrrchr : %s\n", ft_strrchr(str, c));

	return (0);
}*/
