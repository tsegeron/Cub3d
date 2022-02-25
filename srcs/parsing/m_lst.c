#include "../../hdrs/cub3d.h"

t_list	*m_lstnew(char *content)
{
	t_list	*vagiz;

	vagiz = (t_list *) malloc(sizeof (t_list));
	if (vagiz == NULL)
		return (NULL);
	if (!content)
		vagiz->str = NULL;
	else
		vagiz->str = content;
	vagiz->next = NULL;
	return (vagiz);
}

int	m_lstadd_back(t_list **lst, char *str)
{
	t_list	*lst_step;

	if (!*lst)
	{
		*lst = m_lstnew(str);
		if (!*lst)
			return (1);
	}
	else
	{
		lst_step = *lst;
		while (lst_step->next)
			lst_step = lst_step->next;
		lst_step->next = m_lstnew(str);
		if (!lst_step->next)
			return (1);
	}
	return (0);
}

int	m_lstclear(t_list **list)
{
	t_list	*bog;

	while (list && *list)
	{
		bog = (*list)->next;
		free((*list)->str);
		free(*list);
		*list = bog;
	}
	return (1);
}

int	m_lst_size(t_list **lst_a)
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


