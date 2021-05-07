#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;
	size_t	lendst;
	size_t	result;

	i = 0;
	result = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (size > lendst)
		result = lensrc + lendst;
	else
		return (lensrc + size);
	while (src[i] && (lendst + 1) < size)
		dst[lendst++] = src[i++];
	dst[lendst] = '\0';
	return (result);
}
