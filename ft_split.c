#include "libft.h"
#include <stdio.h>

static int 	words_counter(const char *s, char c)
{
	size_t i;
	size_t words;
	size_t max;

	max = ft_strlen(s);
	i = 0;
	words = 0;
	while((s[i] == c) && s[i]) // доводим счетчик до начала до первого символа слова в строке
		i++;
	if(i == max)
		return(0);
	while(s[++i]) // идем по слову до его последнего символа и прибавляем к words + 1
	{
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
	}
	return(words);
}

static char **free_array(char **array)
{
	while(*array)
	{
		free(*array);
		array++;
	}
	*array = NULL;
	return(array);
}


static char **fill(char const *s, char c, char **array, size_t words)
{
	size_t i;
	size_t k;
	size_t l;

	i = 0;
	k = 0;
	while(k < words && s[i])
	{
		if(s[i] != c)
		{
			l = 0;
			while(s[i] != c && s[i])
			{
				array[k][l] = s[i];
				l++;
				i++;
			}
			array[k][l] = '\0';
			k++;
		}
	i++;
	}
	return(array);
}


static char	**allocate(const char *s, char c, char **array, size_t words)
{
	size_t k;
	size_t i;
	size_t lenghtword;

	k = 0;
	i = -1;
	while(k < words && s[++i]) // пока не выделим память для каждого слова и строка не дойдет до конца
	{	
		lenghtword = 0;  
		while(s[i] != c && s[i])
		{
			lenghtword++; // считаем длинну слова
			i++; // идем дальше по строке
		}
		if(lenghtword != 0)
		{
			array[k] = malloc(sizeof(char) * (lenghtword + 1)); // 
			if(!array)
			{
				array = free_array(array);
				return(array);
			}
			k++;
		}
	}
	return(array);
}

char	**ft_split(char const *s, char c)
{
	size_t words;
	char **array;

	if(!s)
		return(0);
	words = words_counter(s, c);  // вычисляем количество строк
	if(!(array = malloc(sizeof(char*) * (words + 1))))
		return(0);
	array[words] = NULL;
	array = allocate(s, c, array, words);
	array = fill(s, c, array, words);
	return(array);
}

// int main()
// {
// 	int i,j;
// 	i = 0;
// 	char *s = "  split this    ";
// 	char **result = ft_split(s, 32);
// 	while(result[i])
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	return(0);
// }