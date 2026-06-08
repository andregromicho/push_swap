/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:59:12 by abrandao          #+#    #+#             */
/*   Updated: 2026/04/23 12:08:18 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits++;
	while (n != 0)
	{
		digits++;
		n = n / 10;
	}
	return (digits);
}

static void	fill_str(char *res, int n, int len)
{
	while (n > 0)
	{
		res[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;

	len = count_digits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	fill_str(res, n, len);
	return (res);
}

//cc ft_itoa.c ft_strdup.c ft_strlen.c 
/*int	main(void)
{
	char *s = ft_itoa(-123);
	char *s2 = ft_itoa(0);
	printf("%s\n", s);
	printf("%s\n", s2);
	free (s);
}*/
