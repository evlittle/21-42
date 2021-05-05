#include "libft.h"

static unsigned int 	words_counter(const char *s, char c)
{
	size_t i;
	size_t words;

	i = -1;
	words = 0;
	while((s[i + 1] == c) && s[i + 1])
		i++;
	while(s[++i])
	{
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
	}
	return(words);  //check
}

static char *fill(size_t sizeword, const char *s, size_t start)
{
	size_t i;
	size_t end;
	char *tab;

	i = 0;
	end = start + sizeword;
	tab = (char*)malloc(sizeof(char) * (sizeword + 1));
		if(!tab)
			return(0);
	while(start < end)
	{
		tab[i] = s[start];
		start++;
		i++;
	}
	tab[i] = '\0';
	return(tab);
}
static char	**allocate(const char *s, char c, char **arrayofptrs, unsigned int words)
{
	size_t i;
	size_t j;
	size_t sizeword;
	size_t start;

	i = 0;
	j = 0;
	while(j < words)
	{
		sizeword = 0;
		while((s[i] == c) && s[i])
			i++;
		while((s[i]!= c) && s[i])
		{
			sizeword++;
			i++;
		}
		start = i - sizeword;
		arrayofptrs[j] = fill(sizeword, s, start);
		j++;
		i++;	
	}
	arrayofptrs[j] = 0;
	return(0);
}

char	**ft_split(char const *s, char c)
{
	unsigned int words;
	char **arrayofptrs;

	if(!s)
		return(0);
	words = words_counter(s, c);
	arrayofptrs = (char**)malloc(sizeof(char*) * (words + 1));
		if(!arrayofptrs)
			return(0);
	arrayofptrs = allocate(s, c, arrayofptrs, words);
	return(arrayofptrs);
}