#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptchar;

	i = 0;
	ptchar = (char *)s;
	if (!s && !n)
		return ;
	while (i < n)
	{	
		*(ptchar + i) = 0;
		i++;
	}
}
