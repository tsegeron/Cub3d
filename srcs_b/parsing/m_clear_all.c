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

//static void	m_clear_itf(void *mlx, t_interface *path)
//{
//	if (path->img)
//		mlx_destroy_image(mlx, path->img);
//}

int	m_clear_all(t_map *map)
{
	ft_clear_arrray(map->map);
//	m_clear_itf(map->mlx.mlx, &map->vars.path_no);
//	m_clear_itf(map->mlx.mlx, &map->vars.path_so);
//	m_clear_itf(map->mlx.mlx, &map->vars.path_we);
//	m_clear_itf(map->mlx.mlx, &map->vars.path_ea);
//	m_clear_itf(map->mlx.mlx, &map->vars.enemy);
//	m_clear_itf(map->mlx.mlx, &map->vars.door);
//	m_clear_itf(map->mlx.mlx, &map->vars.cure);
//	m_clear_itf(map->mlx.mlx, &map->vars.charge);
	m_clear_vilian_lst(&map->vilian);
	exit(EXIT_FAILURE);
}
