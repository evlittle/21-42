#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	number;
	size_t	i;
	size_t	minus;

	i = 0;
	number = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] =='\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			minus *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 +(str[i] - '0');
		i++;
	}
	return ((int)(number * minus));
}
