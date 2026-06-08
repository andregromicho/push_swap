/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:13:29 by abrandao          #+#    #+#             */
/*   Updated: 2026/05/02 16:43:57 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/* int	main(void)
{
	t_list	*list;
	t_list	*first;
	t_list	*second;
	t_list	*last;
	t_list	*temp;

	list = NULL;

	first = ft_lstnew("hello");
	second = ft_lstnew("world");
	last = ft_lstnew("!!");

	ft_lstadd_back(&list, first);
	ft_lstadd_back(&list, second);
	ft_lstadd_back(&list, last);

	temp = list;
	while (temp != NULL)
	{
		printf("%s",(char *) temp->content);
		temp = temp->next;
	}
	ft_lstclear(&list, free);
} */
