/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:22:21 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/22 17:08:26 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* void	print_content(void *content)
{
    printf("%s\n", (char *)content);
} */

/* int	main(void)
{
	t_list	*list;

	list = NULL;
	ft_lstadd_front(&list, ft_lstnew(ft_strdup("1")));
	ft_lstadd_front(&list, ft_lstnew(ft_strdup("2")));
	ft_lstadd_front(&list, ft_lstnew(ft_strdup("3")));

	ft_lstiter(list, print_content);
	ft_lstclear(&list, free);
} */
