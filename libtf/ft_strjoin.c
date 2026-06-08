/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:28:46 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/30 13:18:38 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(total_len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, total_len + 1);
	ft_strlcat(result, s2, total_len + 1);
	return (result);
}

/* int	main(void)
{
	char *s1 = "Hello";
	char *s2 = " World!";
	printf("%s\n", ft_strjoin(s1, s2));
} */
