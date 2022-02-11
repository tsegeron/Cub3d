#include "../../hdrs/cub3d.h"

int	ft_lst_size(t_list **lst_a)
{
	int		count;
	t_list	*lst_step;

	count = 0;
	if (!lst_a)
		return (count);
	lst_step = *lst_a;
	while (lst_step)
	{
		count++;
		lst_step = lst_step->next;
	}
	return (count);
}
