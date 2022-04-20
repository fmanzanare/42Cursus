/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:00:01 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/20 10:44:39 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len > 0)
	{
		*p = (unsigned char) c;
		p++;
		len--;
	}
	return (b);
}
/*int	main(void)
{
	char	str[] = "dljfahsldjfhñasldjhflañsjdhfñasljdhfñalsjdhfñalsjfhd";

	printf("Original : %s\n", str);
	memset(str+5, '.', 10*sizeof(char));
	printf("memset : %s\n", str);

	//printf("mymemset : %s\n", ft_memset(str+5, '.', 10*sizeof(char)));
	ft_memset(str+5, '.', 10*sizeof(char));
	printf("mymemset : %s\n", str);

	return (0);
}*/
