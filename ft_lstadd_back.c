#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastelement;

	if (lst)
	{
		if (*lst)
		{
			lastelement = ft_lstlast(lst);
			lastelement ->next = new;
		}
		else
			*lst = new;
	}
}
