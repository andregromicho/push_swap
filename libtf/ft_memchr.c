/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:31:07 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/15 15:23:24 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	value;
	size_t			i;

	p = (unsigned char *)s;
	value = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == value)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char s[20] = "HelLo World!";
	char *p;
	p = ft_memchr(s, 'o', 20);

	printf("%s\n", p);
}*/		
