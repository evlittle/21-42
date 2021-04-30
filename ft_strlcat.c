#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t lensrc;
	size_t lendst;
	size_t result;

	i = 0;
	result = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (size > lendst)
		result = lensrc + lendst; // будем возвр длинну строки src + dst
	else
		result = lensrc + size; // иначе будем возвр длинну строки src + размер
	while(src[i] && (lendst + 1) < size)
		dst[lendst++] = src[i++]; //заполняем dst с его последнего индекса элементами
//из строки src с нулевого элемента
	dst[lendst] = '\0';
	return(result);
}