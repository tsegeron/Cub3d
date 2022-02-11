/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseastar <mseastar@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:12:16 by mseastar          #+#    #+#             */
/*   Updated: 2022/02/09 01:15:54 by mseastar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

int	ft_lstclear(t_list **list)
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
