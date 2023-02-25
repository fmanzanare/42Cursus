/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_spliter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:47:45 by fmanzana          #+#    #+#             */
/*   Updated: 2023/02/25 12:36:44 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/**
 * Allocates memory for each string to be saved on the array.
 * It also copies the received string on the res variable (return value).
 * @param **str Pointer to the string that will be allocated and copied.
 * @param c Char that will be the split target.
 * @param *arrptr Pointer to the index of the array.
 * @return *res Full string to be copied on the proper array index.
*/
static char	*strmalloc(char **str, char c, int *arrptr)
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

/**
 * Builds the full array once it has been splited and memory allocated.
 * @param **arr Array to be built.
 * @param wrds Number of words that compose the array.
 * @param c Char that will be the split target.
 * @param *str Strign that will be splited into the array.
 * @return **arr The built array.
*/
static char	**arraybuilder(char **arr, int wrds, char c, char *str)
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

/**
 * Counts the number of words that compose the received string.
 * @param *str String to be splited.
 * @param c Char that will be the split target.
 * @return wrds Number of words that compose the string, splitted by "c".
*/
static int	wrdscounter(char *str, char c)
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
			brkchar = *(str - 1);
			while (*str != brkchar && *str)
				str++;
		}
		if ((*str != c && str[1] == c) || (*str != c && !str[1]))
			wrds++;
		str++;
	}
	return (wrds);
}

/**
 * Function that will be calling the other functions.
 * @param *str String to be splitted.
 * @param c Char that will be the split target.
 * @return **arr The array to be returned, once it has been built
*/
char	**command_splitter(char *str, char c)
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
