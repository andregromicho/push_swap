/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:27:24 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/16 15:34:46 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/* char	test_toupper(unsigned int i, char c)
{
	(void)i;
	return((char)ft_toupper(c));
}

int	main(void)
{
	char *s = ft_strmapi("hello world", test_toupper);
	char *s2 = ft_strmapi("", test_toupper);
	printf("%s\n", s);
	printf("%s\n", s2);
	free(s);
	free(s2);
} */
//cc ft_toupper.c ft_strlen.c ft_strmapi.c
