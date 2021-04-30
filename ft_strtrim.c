#include "libft.h"

static int	compare(char const *set, char c)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return(0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int i;
	size_t start;
	size_t end;
	char *resstr;

	if(!s1)
		return(0);
	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while(s1[start] && compare(set, s1[start]))
		start++;
	while(end > start && compare(set, s1[end - 1]))
		end--;
	resstr = (char*)malloc(end - start + 1);
	if(!resstr)
		return(NULL);
	i = 0;
	while(start < end)
		resstr[i++] = s1[start++];
	resstr[i] = '\0';
	return(resstr);
}