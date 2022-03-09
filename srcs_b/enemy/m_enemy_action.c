/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_enemy_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

static void	m_rad_lumus(t_vilian *vilian, t_map *map)
{
	double	res;
	double	rad;
	double	line;
	double	dir_old;

	rad = 3.;
	res = sqrt(((vilian->x - map->pers.posx) * (vilian->x - map->pers.posx)) + \
		((vilian->y - map->pers.posy) * (vilian->y - map->pers.posy)));
	dir_old = vilian->dir;
	m_change_dir_to_hero(vilian, &map->pers);
	line = ray_cast_vil(map, vilian->dir, vilian);
	if (res <= rad && line > res)
	{
		if (res <= 0.5)
			vilian->status_action = 2;
		else
			vilian->status_action = 1;
	}
	else
	{
		vilian->dir = dir_old;
		vilian->status_action = 0;
	}
}

static void	m_angry(t_vilian *vil, t_map *map)
{
	m_rad_lumus(vil, map);
}

int	m_enemy_action(t_map *map)
{
	t_vilian	*step;

	step = map->vilian;
	while (step)
	{
		if (step->health)
		{
			m_angry(step, map);
			if (!step->status_action)
				m_move_lite(step, map);
			else if (step->status_action == 1)
				m_move_angry(step, map);
			else
				m_enemy_atack(map);
		}
		step = step->next;
	}
	return (0);
}
