/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:44:38 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/15 15:24:06 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (temp1[i] != temp2[i])
			return (temp1[i] - temp2[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char *s1 = "Hello World!";
	char *s2 = "Hello World!";

	printf("%i\n", ft_memcmp(s1, s2, 12));

	char *ss1 = "Hello World!";
	char *ss2 = "Hello World!!!";

	printf("%i\n", ft_memcmp(ss1, ss2, 20));
}*/
