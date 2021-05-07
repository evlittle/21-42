#include "libft.h"

static int	nmbrlen(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			i;
	int			len;
	char		*resstr;
	long int	temporary;

	temporary = n;
	i = 0;
	len = nmbrlen(n);
	resstr = (char *)malloc(len + 1);
	if (!resstr)
		return (0);
	resstr[len] = '\0';
	if (n == 0)
		resstr[i] = '0';
	if (n < 0)
	{
		resstr[i++] = '-';
		temporary = -temporary;
	}
	while (temporary != 0)
	{
		resstr[--len] = (temporary % 10) + '0';
		temporary = temporary / 10;
	}
	return (resstr);
}
