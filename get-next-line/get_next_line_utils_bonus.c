/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:44:19 by fmanzana          #+#    #+#             */
/*   Updated: 2022/05/07 11:50:06 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if ((unsigned char) c == '\0')
		return ((char *) s);
	return ((char *) 0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	char			*csrc;
	char			*cdst;
	unsigned int	i;

	csrc = (char *)src;
	cdst = (char *)dst;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}

int	ft_linelen(char *ptr)
{
	int	len;

	len = 0;
	while (ptr[len] && ptr[len] != '\n')
		len++;
	if (ptr[len] == '\n')
		len++;
	return (len);
}
