/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:58:50 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/15 15:24:56 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == 0)
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != 0)
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j] && big[i + j] != 0)
		{
			j++;
			if (little[j] == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char big[] = "Hello World";
	char little[] = "lo";

	printf("%s\n", ft_strnstr(big, little, 12));
}*/
