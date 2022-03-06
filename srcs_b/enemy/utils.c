/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

void	m_change_dir_to_hero(t_vilian *vil, t_hero *hero)
{
	double	dir;
	double	vec_a[2];
	double	vec_b[2];

	vec_b[0] = -1;
	vec_b[1] = 0;
	vec_a[0] = -(hero->posx - vil->x);
	vec_a[1] = -(hero->posy - vil->y);
	dir = ((vec_a[0] * vec_b[0]) + (vec_a[1] * vec_b[1])) / \
		(sqrt((vec_a[0] * vec_a[0]) + (vec_a[1] * vec_a[1])) * \
			sqrt((vec_b[0] * vec_b[0]) + (vec_b[1] * vec_b[1])));
	if (vil->y >= hero->posy)
		vil->dir = fabs(acos(dir));
	else
		vil->dir = 2 / PI - fabs(acos(dir));
	if (vil->dir < 0)
		vil->dir += 2 * PI;
	if (vil->dir >= 2 * PI)
		vil->dir = vil->dir - 2 * PI;
}

double	ray_cast_vil(t_map *map, double dir, t_vilian *now)
{
	double	dist_on_y;
	double	dist_on_x;

	dist_on_y = cast_on_y(map, now->x, now->y, dir);
	dist_on_x = cast_on_x(map, now->x, now->y, dir);
	if (dist_on_y > dist_on_x)
		return (dist_on_x);
	else
		return (dist_on_y);
}

void	m_change_vil_dir(t_vilian *vil)
{
	int	util;

	util = rand() % 4;
	if (util == 0)
		vil->dir += PI / 2 + GR;
	if (util == 1)
		vil->dir += 3 * PI / 2 + GR;
	if (util == 2)
		vil->dir += PI + GR;
	else
		vil->dir += GR;
	if (vil->dir >= 2 * PI)
		vil->dir -= 2 * PI;
}
