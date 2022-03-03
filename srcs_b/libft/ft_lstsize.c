/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:51:02 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/22 18:34:02 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
