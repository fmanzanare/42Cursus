/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:21:49 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/19 16:26:12 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<ctype.h>

int	ft_isprint(char c)
{
	int	check;

	if (c >= 32 && c <= 126)
		check = 1;
	else
		check = 0;
	return (check);
}
/*int	main(void)
{
	int	cha = 58;

	printf("%i\n", cha);
	printf("%i\n\n", isprint(cha));
	printf("%i\n", ft_isprint(cha));

	return (0);
}*/
