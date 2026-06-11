/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:16:35 by abrandao          #+#    #+#             */
/*   Updated: 2026/06/09 20:18:30 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, int *result)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		num = (num * 10) + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num) < INT_MIN))
			return (0);
		i++;
	}
	*result = (int)(num * sign);
	return (1);
}

/*int	main(void)
{
	printf("%i\n", ft_atoi("123"));
	printf("%i\n", ft_atoi("    -123"));
	printf("%i\n", ft_atoi(""));
	printf("%i\n", ft_atoi("-2147483648999"));
}*/
