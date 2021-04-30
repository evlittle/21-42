#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substring;
	unsigned int i;
	size_t k;
	// size_t length;

	//length = ft_strlen(s);
	i = 0;
	k = 0;
	// if(start + len > length)
	// 	len = length - start;
	if (!s)
		return(0);
	substring = (char *)malloc(len + 1);
	if (!substring)
		return(0);
	while(s[i] && k < len)
	{
		if(i >= start)
			substring[k++] = s[i];
	i++;
	}
	substring[k] = '\0';
	return(substring);
}