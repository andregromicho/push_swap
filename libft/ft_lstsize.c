/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:44:17 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/20 12:57:23 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*int	main(void)
{
	t_list	*list;
	t_list	*first;
	t_list	*second;

	list = NULL;
	first = ft_lstnew("teste");
	second = ft_lstnew("teste");

	ft_lstadd_front(&list, first);
	ft_lstadd_front(&list, second);

	printf("length: %i\n", ft_lstsize(list));

	free(first);
	free(second);
}*/
