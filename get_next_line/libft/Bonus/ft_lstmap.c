#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;

	res = NULL;
	if (lst != NULL)
	{
		tmp = f(lst);
		res = ft_lstnew(tmp->content, tmp->content_size);
		res->next = ft_lstmap(lst->next, f);
	}
	return (res);
}