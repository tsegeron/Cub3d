#include "../hdrs/cub3d.h"

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

#include "../hdrs/cub3d.h"

static void	do_key_w(t_map *map)
{
	int	posx;
	int	posy;

	posx = (int)(map->pers.posx);
	posy = (int)(map->pers.posy - 0.2);
	if (map->map[posy][posx] != '1')
		map->pers.posy -= 0.2;
}

static void	do_key_a(t_map *map)
{
	int	posx;
	int	posy;

	posx = (int)(map->pers.posx - 0.2);
	posy = (int)(map->pers.posy);
	if (map->map[posy][posx] != '1')
		map->pers.posx -= 0.2;
}

static void	do_key_s(t_map *map)
{
	int	posx;
	int	posy;

	posx = (int)(map->pers.posx);
	posy = (int)(map->pers.posy + 0.2);
	if (map->map[posy][posx] != '1')
		map->pers.posy += 0.2;
}

static void	do_key_d(t_map *map)
{
	int	posx;
	int	posy;

	posx = (int)(map->pers.posx + 0.2);
	posy = (int)(map->pers.posy);
	if (map->map[posy][posx] != '1')
		map->pers.posx += 0.2;
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
//	printf("%f ", *dir);
}

int	g_do_keys(int keycode, t_map *map)
{
//	printf("%d ", keycode);
	if (keycode == 53)
		close_win(map);
	if (keycode == 13)
		do_key_w(map);
	else if (keycode == 0)
		do_key_a(map);
	else if (keycode == 1)
		do_key_s(map);
	else if (keycode == 2)
		do_key_d(map);
	else if (keycode == 123 || keycode == 124)
		do_cam_rot(&map->pers.dir, keycode);
//	printf("%d ", keycode);
	mlx_clear_window(map->mlx.mlx, map->mlx.win);
//	printf("%.1f %.1f\n", map->pers.posx, map->pers.posy);
	draw_minimap(map);

//	draw_map(map);
//	draw_objects(map);
	return (0);
}

