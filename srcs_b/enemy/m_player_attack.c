/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_player_attack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

static double	m_find_dir_ti_enemy(t_map *map, t_vilian *step)
{
	double	vec_a[2];
	double	vec_b[2];

	vec_b[0] = -1.;
	vec_b[1] = 0;
	vec_a[0] = -(step->x - map->pers.posx);
	vec_a[1] = -(step->y - map->pers.posy);
	return (((vec_a[0] * vec_b[0]) + (vec_a[1] * vec_b[1])) / \
		(sqrt((vec_a[0] * vec_a[0]) + (vec_a[1] * vec_a[1])) * \
			sqrt((vec_b[0] * vec_b[0]) + (vec_b[1] * vec_b[1]))));
}

static void	m_check_dir_attack(double dir_to_enemy, t_map *map, t_vilian *step)
{
	if (fabs(dir_to_enemy - map->pers.dir) < PI / 6 || \
		fabs(dir_to_enemy - map->pers.dir) > 5 * PI / 3)
		step->health = (int )(step->health - 0.25);
}

int	m_player_attack(t_map *map)
{
	t_vilian	*step;
	double		dir_to_enemy;

	step = map->vilian;
	while (step)
	{
		if (step->status_action == 2 && step->health > 0)
		{
			dir_to_enemy = m_find_dir_ti_enemy(map, step);
			if (step->y < map->pers.posy)
				dir_to_enemy = fabs(acos(dir_to_enemy));
			else
				dir_to_enemy = 2 * PI - fabs(acos(dir_to_enemy));
			if (dir_to_enemy < 0)
				dir_to_enemy += 2 * PI;
			if (dir_to_enemy > 2 * PI)
				dir_to_enemy -= 2 * PI;
			m_check_dir_attack(dir_to_enemy, map, step);
		}
		step = step->next;
	}
	return (0);
}
