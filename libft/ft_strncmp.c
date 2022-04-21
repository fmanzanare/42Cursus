/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:27:08 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/21 18:51:43 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
/*int	main(void)
{
	char	str1[] = "Hello World";
	char	str2[] = "Hello aORLD";

	printf("str1 : %s | str2 : %s\n", str1, str2);
	printf("strncmp : %d\n", strncmp(str1, str2, 10));
	printf("mystrncmp : %d\n", ft_strncmp(str1, str2, 10));

	return (0);
}*/
