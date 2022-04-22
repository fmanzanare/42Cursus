/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:10:34 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/22 09:33:49 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;

	p = (unsigned char *)s1;
	q = (unsigned char *)s2;
	while (n > 0)
	{
		if (*p != *q)
			return (*p - *q);
		n--;
		p++;
		q++;
	}
	return (0);
}
/*int	main(void)
{
	char	str1[] = "Hello World";
	char	str2[] = "Hello WOrld";

	printf("String 1 : %s | String 2 : %s\n", str1, str2);
	printf("memcmp : %d\n", memcmp(str1, str2, 9));
	printf("mymemcmp : %d\n", ft_memcmp(str1, str2, 9));

	return (0);
}*/
