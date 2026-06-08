/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:57:39 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/20 14:32:03 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*int	main(void)
{
	t_list	*list;
	t_list	*first;
	t_list	*second;
	t_list	*last;

	list = NULL;
	first = ft_lstnew("1");
	second = ft_lstnew("2");
	last = ft_lstnew("3");

	ft_lstadd_front(&list, last);
	ft_lstadd_front(&list, second);
	ft_lstadd_front(&list, first);
	printf("last: %s\n", (char *)ft_lstlast(list)->content);

	free(first);
	free(second);
	free(last);
}*/
