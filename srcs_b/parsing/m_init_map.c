/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_ber.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseastar <mseastar@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 20:53:11 by mseastar          #+#    #+#             */
/*   Updated: 2022/02/10 22:27:06 by mseastar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../hdrs/cub3d_bonus.h"

static void	*m_clear_array(char **a)
{
	ft_clear_arrray(a);
	return (NULL);
}

size_t	m_len_width(t_list *map)
{
	t_list	*step;
	size_t	i;
	size_t	util;

	i = 0;
	step = map;
	while (step)
	{
		util = ft_strlen(step->str);
		if (util > i)
			i = util;
		step = step->next;
	}
	return (i);
}

static void	ft_strncpy(char *str1, char *str2, size_t n)
{
	size_t	i;

	i = -1;
	while (str2[++i] && i < n)
		str1[i] = str2[i];
}

char	**m_map_create(t_list *map, t_map *mapa)
{
	t_list	*step;
	char	**array_r;
	int		i;

	array_r = ft_calloc(sizeof(char *), m_lst_size(&map) + 1);
	if (!array_r)
		return (NULL);
	mapa->map_width = (int)m_len_width(map);
	i = -1;
	step = map;
	while (step)
	{
		array_r[++i] = ft_calloc(1, mapa->map_width + 1);
		if (!array_r[i])
			return (m_clear_array(array_r));
		ft_memset(array_r[i], ' ', mapa->map_width);
		ft_strncpy(array_r[i], step->str, ft_strlen(step->str));
		step = step->next;
	}
	return (array_r);
}
