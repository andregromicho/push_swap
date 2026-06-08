/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:16:35 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/27 14:45:59 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	value;
	int	sign;

	value = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		value = value * 10 + (nptr[i] - '0');
		i++;
	}
	return (value * sign);
}

/*int	main(void)
{
	printf("%i\n", ft_atoi("123"));
	printf("%i\n", ft_atoi("    -123"));
	printf("%i\n", ft_atoi(""));
	printf("%i\n", ft_atoi("-2147483648999"));
}*/
