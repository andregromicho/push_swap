/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:39:48 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/15 15:28:08 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s);
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s, len + 1);
	return (new);
}

/*int	main(void)
{
	char *s = "Hello World!";
	char *d;

	d = ft_strdup(s);

	printf("%s\n", d);
}*/
