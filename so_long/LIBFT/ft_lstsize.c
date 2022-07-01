/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:13:52 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/26 13:25:03 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	if (!lst)
		return (0);
	while (lst->next != 0)
	{
		counter++;
		lst = lst->next;
	}
	if (lst->next == 0)
		counter++;
	return (counter);
}
