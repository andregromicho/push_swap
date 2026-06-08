/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:47:17 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/20 17:46:29 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = temp;
	}
}

/*int	main(void)
{
	t_list	*list;
	t_list	*first;
	t_list	*second;

	list = NULL;
	first = ft_lstnew(malloc(5));
	second = ft_lstnew(malloc(5));
	if (!first || !second)
	{
		free(first);
		free(second);
		return (1);
	}

	ft_lstadd_front(&list, second);
	ft_lstadd_front(&list, first);

	ft_lstclear(&list, free);

	if (list == NULL)
	printf("Lista limpa.");
}*/
//cc -g ft_lstclear.c ft_lstdelone.c ft_lstadd_front.c ft_lstnew.c
