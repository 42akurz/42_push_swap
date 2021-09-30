/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:31:55 by akurz             #+#    #+#             */
/*   Updated: 2021/07/10 16:58:26 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*element;
	t_list	*new;

	new = 0;
	while (lst != NULL)
	{
		element = ft_lstnew(f(lst->content));
		if (element == NULL)
			ft_lstclear(&new, del);
		else
			ft_lstadd_back(&new, element);
		lst = lst->next;
	}
	return (new);
}
