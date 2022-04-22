/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:35:13 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/22 15:28:16 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;
	char	c;

	c = *needle;
	needle_len = 0;
	i = 1;
	while (needle[needle_len] != '\0')
		needle_len++;
	if (c == '\0')
		return ((char *) haystack);
	while (needle_len <= len)
	{
		if (*haystack == c)
		{
			while (i)
			{
				if (i == needle_len)
					return ((char *) haystack);
				if (haystack[i] != needle[i])
					return (0);
				i++;
			}
		}
		needle_len--;
		haystack++;
	}
	return (0);
}
/*int	main(void)
{
	char	str1[] = "Hello World!!";
	char	str2[] = "Hello";

	printf("String 1 : %s | String 2 : %s\n", str1, str2);
	printf("strnstr : %s\n", strnstr(str1, str2, strlen(str2)));
	printf("mystrnstr : %s\n", ft_strnstr(str1, str2, strlen(str2)));

	return (0);
}*/
