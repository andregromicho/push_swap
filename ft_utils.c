#include "push_swap.h"

/* Escreve uma string para um file descriptor */
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/* Escreve um número inteiro para um file descriptor */
void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	if (fd < 0)
		return ;
	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	num = num % 10 + '0';
	write(fd, &num, 1);
}

/* Retorna o tamanho de uma string */
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

/* Copia um substring entre dois índices e retorna um novo alocado */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start >= s_len)
	{
		result = malloc(1);
		if (result)
			result[0] = '\0';
		return (result);
	}
	if (start + len > s_len)
		len = s_len - start;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* Converte um inteiro para string */
char	*ft_itoa(int n)
{
	char	*result;
	long	num;
	int		len;
	int		is_negative;

	is_negative = (n < 0);
	num = (n < 0) ? -(long)n : (long)n;
	len = (is_negative ? 1 : 0);
	
	// Conta quantos dígitos tem
	if (num == 0)
		len++;
	else
	{
		long temp = num;
		while (temp > 0)
		{
			len++;
			temp /= 10;
		}
	}
	
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	
	result[len] = '\0';
	if (is_negative)
		result[0] = '-';
	
	// Preenche de trás para frente
	int i = len - 1;
	if (num == 0)
		result[is_negative ? 1 : 0] = '0';
	else
	{
		while (num > 0)
		{
			result[i] = (num % 10) + '0';
			num /= 10;
			i--;
		}
	}
	
	return (result);
}

/* Copia o valor de uma string para outra */
char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	dst = malloc(i + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
