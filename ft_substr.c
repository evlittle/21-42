#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;
	size_t			k;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	if (len > (size_t)ft_strlen(s))
		len = ft_strlen(s);
	substring = (char *)malloc(len + 1);
	if (!substring)
		return (0);
	while (s[i] && k < len)
	{
		if (i >= start)
			substring[k++] = s[i];
		i++;
	}
	substring[k] = '\0';
	return (substring);
}
