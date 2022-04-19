/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:09:54 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/19 16:18:47 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<ctype.h>

int	ft_isascii(int c)
{
	int		check;

	if (c >= 0 && c <= 127)
		check = 1;
	else
		check = 0;
	return (check);
}
/*int	main(void)
{
	int		cha = 64;

	printf("%i\n", cha);
	printf("%i\n\n", isascii(cha));
	printf("%i\n", ft_isascii(cha));

	return (0);
}*/
