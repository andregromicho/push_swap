/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:55:06 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/20 18:13:44 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/* static	void	*to_upper(void *content)
{
	char	*str;
	char	*new;
	int		i;

	str = (char *)content;
	new = ft_strdup(str);
	if (!new)
		return (NULL);
	i = 0;
	while (new[i])
	{
		if (new[i] >= 'a' && new[i] <= 'z')
			new[i] -= 32;
		i++;
	}
	return (new);
}

int	main(void)
{
	t_list *list;
	t_list *list2;
	t_list 	*temp;

	list = NULL;
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("hello")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("world")));

	list2 = ft_lstmap(list, to_upper, free);
	temp = list2;
	while (temp != NULL)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstclear(&list, free);
	ft_lstclear(&list2, free);
}*/
