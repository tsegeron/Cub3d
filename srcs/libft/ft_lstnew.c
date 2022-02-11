/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseastar <mseastar@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:11:19 by mseastar          #+#    #+#             */
/*   Updated: 2021/11/27 13:01:32 by mseastar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../hdrs/cub3d.h"

t_list	*ft_lstnew(char *content)
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
