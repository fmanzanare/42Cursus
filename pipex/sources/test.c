/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:40:05 by fmanzana          #+#    #+#             */
/*   Updated: 2022/09/14 13:39:11 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(void)
{
	char	*str1 = "Hola Mundo! ";
	char	*str2 = "Como va eso?";
	char	*dst;
	
	printf("str 1: %s\n", str1);
	printf("str 2: %s\n", str2);
	dst = ft_strjoin(str1, str2);
	printf("dst: %s\n", dst);
	free(dst);
	return (0);
}
