/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:12:14 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/15 15:27:35 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (nmemb != 0 && size > ((size_t)-1) / nmemb)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

/* #include <stdio.h>
int	main(void)
{
	int	i;
	int *s = (int *)ft_calloc(8, sizeof(int));
	i = 0;
	while (i < 8)
	{
		printf("%i ", s[i]);
		i++;
	}
	free(s);
}
 */
