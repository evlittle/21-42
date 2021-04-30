#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char *pt;
	size_t i;

	i = 0;
	pt = (void *)malloc(size * count);
	if (!pt)
		return (0);
	while(!pt || (i < size * count))
		pt[i++] = 0;
	return(pt);
}