/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_do_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:34:59 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/08 22:14:55 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

static void	find_difs(double *x, double *y, double dir, int keycode)
{
	if (keycode == 13)
	{
		*x = MOVE_SPEED * cos(dir);
		*y = -MOVE_SPEED * sin(dir);
	}
	else if (keycode == 1)
	{
		*x = -MOVE_SPEED * cos(dir);
		*y = MOVE_SPEED * sin(dir);
	}
	else if (keycode == 0)
	{
		*x = -MOVE_SPEED * sin(dir);
		*y = MOVE_SPEED * -cos(dir);
	}
	else
	{
		*x = MOVE_SPEED * sin(dir);
		*y = -MOVE_SPEED * -cos(dir);
	}
}

static void	do_key_wasd(t_map *map, int keycode)
{
	int		posx;
	int		posy;
	double	difx;
	double	dify;

	find_difs(&difx, &dify, map->pers.dir, keycode);
	posx = (int)(map->pers.posx + difx + MOVE_SPEED * difx / fabs(difx));
	posy = (int)(map->pers.posy + dify + MOVE_SPEED * dify / fabs(dify));
	if (map->map[(int)map->pers.posy][posx] != '1'
			&& map->map[(int)map->pers.posy][posx] != 'C')
		map->pers.posx += difx;
	if (map->map[posy][(int)map->pers.posx] != '1'
			&& map->map[posy][(int)map->pers.posx] != 'C')
		map->pers.posy += dify;
	if (map->map[posy][posx] == 'B' || map->map[posy][posx] == 'H')
	{
		if (map->map[posy][posx] == 'B' && map->pers.charge < 10)
			map->pers.charge++;
		else if (map->map[posy][posx] == 'H' && map->pers.health < 3)
			map->pers.health++;
		map->map[posy][posx] = '0';
	}
}

void	do_cam_rot(double *dir, int keycode)
{
	if (keycode == 123)
		*dir += 0.06981317;
	else
		*dir -= 0.06981317;
	if (*dir < 0.0)
		*dir = 3.14159265 * 2 - 0.06981317;
	else if (*dir > 3.14159265 * 2)
		*dir = 0.00001;
}

void	check_buttons(t_map *map)
{
	if (map->key.w)
		do_key_wasd(map, 13);
	if (map->key.a)
		do_key_wasd(map, 0);
	if (map->key.s)
		do_key_wasd(map, 1);
	if (map->key.d)
		do_key_wasd(map, 2);
	if (map->key.left)
		do_cam_rot(&map->pers.dir, 123);
	if (map->key.right)
		do_cam_rot(&map->pers.dir, 124);
}
