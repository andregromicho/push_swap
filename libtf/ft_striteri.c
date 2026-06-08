/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:41:50 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/16 15:53:36 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != 0)
	{
		f(i, &s[i]);
		i++;
	}
}

/* static void	teste_toupper(unsigned int i, char* s)
{
	if (*s >= 'a' && *s <= 'z')
		*s = *s - 32;
}

int	main(void)
{
	char	s[] = "hello world";
	ft_striteri(s, teste_toupper);
	printf("%s\n", s);
} */
