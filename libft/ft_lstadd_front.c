/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:04:56 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/20 12:49:18 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	t_list	*list;
	t_list	*first;
	t_list	*second;
	t_list	*temp;

	list = NULL;
	first = ft_lstnew("World");
	ft_lstadd_front(&list, first);
	second = ft_lstnew("Hello");
	ft_lstadd_front(&list, second);

	temp = list;
	while (temp != NULL)
	{
		printf("list: %s\n", (char *)temp->content);
		temp = temp->next;
	}

	ft_lstclear(&list, free);
}*/
