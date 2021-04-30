#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t i;
	char *resstr;

	if(!s)
		return(0);
	i = 0;
	resstr = ft_strdup(s);
	if(!resstr)
		return(0);
	while(resstr[i])
	{	
		resstr[i] = (*f)(i, resstr[i]);
		i++;
	}
	return(resstr);
}