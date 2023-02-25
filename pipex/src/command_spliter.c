/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_spliter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:47:45 by fmanzana          #+#    #+#             */
/*   Updated: 2023/02/25 11:38:13 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*strmalloc(char const **str, char c, int *arrptr)
{
	char	*res;
	char	brkchar;
	int		i;

	i = 0;
	if (**str == '\'' || **str == '\"')
	{
		str[0]++;
		brkchar = *(*str - 1);
		while (str[0][i] && str[0][i] != brkchar)
			i++;
	}
	else
	{
		while (str[0][i] && str[0][i] != c)
			i++;
	}
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, *str, (i + 1));
	*arrptr = i;
	return (res);
}

static char	**arraybuilder(char **arr, int wrds, char c, char const *str)
{
	int	i;
	int	idx;
	int	wrdscounter;

	wrdscounter = 0;
	idx = 0;
	while (wrdscounter < wrds)
	{
		while (*str == c)
			str++;
		arr[idx] = strmalloc(&str, c, &i);
		str += i;
		wrdscounter++;
		if (!arr[idx])
		{
			ft_free_arr(arr);
			return (NULL);
		}
		idx++;
	}
	if (wrdscounter == wrds)
		arr[idx] = NULL;
	return (arr);
}

static int	wrdscounter(char const *str, char c)
{
	int		wrds;
	char	brkchar;

	brkchar = 0;
	wrds = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			if (*str == '\'')
				str++;
			if (*str == '\"')
				str++;
			brkchar = *(str--);
			while (*str != brkchar && *str)
				str++;
		}
		if ((*str != c && str[1] == c) || (*str != c && !str[1]))
			wrds++;
		str++;
	}
	return (wrds);
}

char	**command_splitter(char const *str, char c)
{
	char	**arr;
	int		wrds;

	if (!str)
		return (0);
	wrds = wrdscounter(str, c);
	arr = (char **)malloc((wrds + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = arraybuilder(arr, wrds, c, str);
	return (arr);
}
