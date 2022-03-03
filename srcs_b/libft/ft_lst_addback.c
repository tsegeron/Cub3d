/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:51:02 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/22 18:34:02 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

int	ft_lstadd_back(t_list **lst, char *str)
{
	t_list	*lst_step;

	if (!*lst)
	{
		*lst = ft_lstnew(str);
		if (!*lst)
			return (1);
	}
	else
	{
		lst_step = *lst;
		while (lst_step->next)
			lst_step = lst_step->next;
		lst_step->next = ft_lstnew(str);
		if (!lst_step->next)
			return (1);
	}
	return (0);
}
