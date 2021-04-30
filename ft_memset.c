#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	if (!b && !c) //если переданы пустая строка и пустой символ
		return(0);
	while(i < len) //пока счетчик меньше длинны переданной в кач-ве параметра
	{
		*(unsigned char*)(b + i) = (unsigned char)c; //заполняем в строку переданный байт С
		i++;
	}
	return(b);
}