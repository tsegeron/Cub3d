/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_clear_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:34:59 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/08 22:14:55 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

int	m_clear_all(t_map *map)
{
	ft_clear_arrray(map->map);
	m_clear_vilian_lst(&map->vilian);
	exit(EXIT_FAILURE);
}
