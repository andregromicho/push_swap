/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 12:35:19 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/22 17:05:10 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')))
	{
		return (1);
	}
	return (0);
}

/*#include <stdio.h>
int	main(void)
{
	printf ("%i\n", ft_isalnum('c'));
	printf ("%i\n", ft_isalnum('C'));
	printf ("%i\n", ft_isalnum('1'));
	printf ("%i\n", ft_isalnum('$'));
}*/
