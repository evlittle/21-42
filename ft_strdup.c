#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t i;
	char *pt;
	int length;

	i = 0;
	length = ft_strlen(s);
	pt = (char *)malloc(length + 1);
	if(!s || !pt)
		return(0);
	while (length--)
	{
		pt[i] = s[i];
		i++;
	}
	pt[i] = '\0';
	return(pt);
}