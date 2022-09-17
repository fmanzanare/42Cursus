/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:13:49 by fmanzana          #+#    #+#             */
/*   Updated: 2022/04/26 19:47:27 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newel;

	if (lst == NULL)
		return (NULL);
	newlst = ft_lstnew(f(lst->content));
	if (newlst == NULL)
		return (NULL);
	newel = newlst;
	while (lst->next)
	{
		newel->next = ft_lstnew(f(lst->next->content));
		if (newel->next == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		newel = newel->next;
		lst = lst->next;
	}
	return (newlst);
}
