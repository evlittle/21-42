#include "libft.h"

static int		words_counter(char const *s, char c)
{
	int words;
	size_t i;

	words = 0;
	i = 0;
	while(s[i])
	{
		if((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			words++;
		i++;
	}
	return(words);
}

static int		words_length(char const *s, char c)
{
	int length;
	size_t i;

	i = 0;
	length = 0;
	while (s[i++] != c && s[i] != '\0')
		length++;
	return(length);
}

static char		**additions(char const *s, char c, int words, char **arrayofptrs)
{
	int i;
	int k;
	int length;

	i = 0;
	k = 0;
	while (i++ < words)
	{
		while(*s == c)
			s++;
		length = words_length(s, c);
		arrayofptrs[i] = (char*)malloc(length + 1);
			if(!arrayofptrs)
				free(arrayofptrs);
		while(k++ < length)
			arrayofptrs[i][k] = s[k];
		arrayofptrs[i][k] = '\0';	
	}
	arrayofptrs[i] = 0;
	return(arrayofptrs);
}

char	**ft_split(char const *s, char c)
{
	char **arrayofptrs;
	int words;
	
	words = words_counter(s, c);
	arrayofptrs = (char**)malloc(words + 1);
	if(!arrayofptrs)
		return(0);
	additions(s, c, words, arrayofptrs);
	return(arrayofptrs);
}