/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:08:24 by akurz             #+#    #+#             */
/*   Updated: 2021/07/10 16:12:58 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*element;
	t_list	*next;

	element = *lst;
	while (element != NULL)
	{
		next = element->next;
		del(element->content);
		free(element);
		element = next;
	}
	*lst = NULL;
}
