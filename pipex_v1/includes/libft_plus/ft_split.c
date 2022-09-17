/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:42:52 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/27 15:45:52 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordscnt(char const *s, char c);
static char	*stringmkr(char const *s, int start, int finish);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**dst;

	dst = malloc((wordscnt(s, c) + 1) * sizeof(char *));
	if (!s || !dst)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			dst[j++] = stringmkr(s, index, i);
			index = -1;
		}
		i++;
	}
	dst[j] = 0;
	return (dst);
}

static int	wordscnt(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*s == c)
			j = 0;
		s++;
	}
	return (i);
}

static char	*stringmkr(char const *s, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}
