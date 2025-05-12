
#include "../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	else if ((*lst) == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
	return ;
}
