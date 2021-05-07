#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		k;
	char		*resstr;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (0);
	resstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!resstr)
		return (0);
	while (i < ft_strlen(s1))
		resstr[k++] = s1[i++];
	i = 0;
	while (i < ft_strlen(s2))
		resstr[k++] = s2[i++];
	resstr[k] = '\0';
	return (resstr);
}
