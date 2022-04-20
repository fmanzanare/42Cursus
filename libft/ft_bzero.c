/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:51:30 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/20 11:14:18 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<strings.h>

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	i;

	i = 0;
	c = s;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}
/*int	main(void)
{
	int		i;
	char	str[] = "aslkdfjalksdjflasdkj";

	i = 0;
	printf("Original : %s\n", str);
	
	bzero(str+5, 5);
	while (i < 20)
	{
		printf("bzero : %d\n", str[i]);
		i++;
	}
	printf("\n");
	
	i = 0;
	ft_bzero(str+5, 5);
	while (i < 20)
	{
		printf("mybzero : %d\n", str[i]);
		i++;
	}

	return (0);
}*/
