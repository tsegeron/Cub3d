#include "../../hdrs/cub3d.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_keys.c                                          :+:      :+:    :+:   */
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
		*x = 0.2 * cos(dir);
		*y = -0.2 * sin(dir);
	}
	else if (keycode == 1)
	{
		*x = -0.2 * cos(dir);
		*y = 0.2 * sin(dir);
	}
	else if (keycode == 0)
	{
		*x = -0.2 * sin(dir);
		*y = 0.2 * -cos(dir);
	}
	else
	{
		*x = 0.2 * sin(dir);
		*y = -0.2 * -cos(dir);
	}
}

static void	do_key_wasd(t_map *map, int keycode)
{
	int		posx;
	int		posy;
	double	difx;
	double	dify;

	find_difs(&difx, &dify, map->pers.dir, keycode);
	posx = (int)(map->pers.posx + difx + 0.2 * difx / fabs(difx));
	posy = (int)(map->pers.posy + dify + 0.2  * dify / fabs(dify));
	if (map->map[(int)map->pers.posy][posx] != '1' && map->map[(int)map->pers.posy][posx] != 'C')
		map->pers.posx += difx;
	if (map->map[posy][(int)map->pers.posx] != '1' && map->map[posy][(int)map->pers.posx] != 'C')
		map->pers.posy += dify;
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

void	do_open_door(t_map *map)
{
	int		posx;
	int		posy;
	double	difx;
	double	dify;
	int		dif;

	find_difs(&difx, &dify, map->pers.dir, 13);
	posx = (map->pers.posx + 2.5 * difx);
	posy = (map->pers.posy + 2.5 * dify);
	dif = abs((int)map->pers.posx - posx) + abs((int)map->pers.posy - posy);
	if (map->map[(int)map->pers.posy][(int)map->pers.posx] != 'O' && dif <= 1)
	{
		if (map->map[posy][posx] == 'C')
			map->map[posy][posx] = 'O';
		else if (map->map[posy][posx] == 'O')
			map->map[posy][posx] = 'C';
	}
}

int	g_do_keys(int keycode, t_map *map)
{
//	printf("%d ", keycode);
	if (keycode == 53)
		close_win(map);
	if (keycode == 14)	//	E - open door
		do_open_door(map);
//	else if (keycode == 12)	//	Q - menu call
//		do_call_menu(map);
	else if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		do_key_wasd(map, keycode);
	else if (keycode == 123 || keycode == 124)
		do_cam_rot(&map->pers.dir, keycode);
	mlx_clear_window(map->mlx.mlx, map->mlx.win);
	draw_minimap(map);

//	draw_map(map);
//	draw_objects(map);
	return (0);
}

