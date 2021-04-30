#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	if(!src && !dest)
		return(0);
	while(i < n)
	{
		*(unsigned char*)(dest + i) = *(unsigned char*)(src + i); //копирует первый байт из src в dest
		if (*(unsigned char*)(src + i) == ((unsigned char)c)) // если байт из src совпадает с С переданный в кач-ве параметра
			return(dest + i + 1); //возвращаем следующий после совпадения байт
		i++;
	}
	return(0);
}