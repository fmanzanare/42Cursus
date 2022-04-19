/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:41:01 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/19 15:59:02 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<ctype.h>

int	ft_isalnum(int c)
{
	int		check;

	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		check = 1;
	else
		check = 0;
	return (check);
}
/*int	main(void)
{
	int	cha = 94;

	printf("%i\n", cha);
	printf("%i\n\n", isalnum(cha));
	printf("%i\n", ft_isalnum(cha));

	return(0);
}*/
