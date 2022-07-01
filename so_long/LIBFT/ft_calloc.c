/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:43:01 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/26 11:41:51 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count + size < count || count + size < size)
		return (0);
	ptr = (char *)malloc(count * size);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}
