#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t 	k;

	i = 0;
	k = 0;
	if (needle[i] == '\0')
		return((char *)haystack);
	while (i < len && haystack[i])
	{
		if (needle[k] == haystack[i])
		{
			while (haystack[i + k] == needle[k] && len--)
			{
				k++;
				if (needle[k] == 0)
					return((char*)(haystack + i));
			}
		}
		i++;
	}
	return (0);
}