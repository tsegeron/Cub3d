/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pars_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:34:59 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/08 22:14:55 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

int	m_pars_map(char *str, int fd, t_list **lst_map)
{
	while (1)
	{
		if (m_lstadd_back(lst_map, str))
		{
			m_lstclear(lst_map);
			free(str);
			return (m_close_fd(fd));
		}
		str = get_next_line(fd);
		if (!str)
			break ;
	}
	close(fd);
	return (0);
}
