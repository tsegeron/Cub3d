/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_ber.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseastar <mseastar@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 20:53:11 by mseastar          #+#    #+#             */
/*   Updated: 2022/02/22 18:34:02 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

static void	*m_clear_array(char **a)
{
	ft_clear_arrray(a);
	return (NULL);
}

char	**ft_map_create(t_list *map)
{
	t_list	*step;
	char	**array_r;
	int		i;

	array_r = ft_calloc(sizeof(char *), ft_lst_size(&map) + 1);
	if (!array_r)
		return (NULL);
	i = -1;
	step = map;
	while (step)
	{
		array_r[++i] = ft_strdup(step->str);
		if (!array_r[i] || array_r[i][0] == '\0')
			return (m_clear_array(array_r));
		step = step->next;
	}
	return (array_r);
}
