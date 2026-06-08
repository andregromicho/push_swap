/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:15:50 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/15 15:15:02 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	d_len = 0;
	s_len = 0;
	while (dst[d_len] != 0 && size > d_len)
		d_len++;
	while (src[s_len] != 0)
		s_len++;
	if (size <= d_len)
		return (size + s_len);
	i = 0;
	while (src[i] != 0 && d_len + i < size - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}

/*int	main(void)
{
	char d[20] = "Hello";
	char *s = "World";

	ft_strlcat(d, s, 20);
	printf("%s\n", d);
}*/
