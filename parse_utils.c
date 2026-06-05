#include "push_swap.h"
#include <limits.h>

/* Compara duas strings. Útil para detetar as flags --bench e --adaptive */
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* Valida se a string contém apenas dígitos e sinais regulamentares */
int	is_digit_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/* Converte string para int com proteção absoluta contra Overflows (INT_MAX/MIN) */
int	ft_atoi_protected(char *str, int *result)
{
	long	num;
	int		sign;
	int		i;

	if (!is_digit_str(str))
		return (0);
	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		num = (num * 10) + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num) < INT_MIN))
			return (0);
		i++;
	}
	*result = (int)(num * sign);
	return (1);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

/* Divide strings complexas passadas entre aspas (ex: "1 2 3") */
char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			tab[i++] = ft_substr(s, 0, len); // Usa o ft_substr da tua libft
			s += len;
		}
	}
	tab[i] = NULL;
	return (tab);
}