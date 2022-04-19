/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:29:48 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/19 15:38:10 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<ctype.h>

int	ft_isdigit(int c)
{
	int		check;

	if (c >= 48 && c <= 57)
		check = 1;
	else
		check = 0;
	return (check);
}
/*int	main(void)
{
	int	cha = 58;

	printf("%i\n", cha);
	printf("%i\n\n", isdigit(cha));
	printf("%i\n", ft_isdigit(cha));

	return (0);
}*/
