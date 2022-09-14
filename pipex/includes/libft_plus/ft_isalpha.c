/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:07:40 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/26 20:19:21 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<ctype.h>

int	ft_isalpha(int c)
{
	int		check;

	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		check = 1;
	else
		check = 0;
	return (check);
}
