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
	posy = (int)(map->pers.posy - 0.25);
	if (map->map[posy][posx] != '1')
		map->pers.posy -= 0.25;
}

static void	do_key_a(t_map *map)
{
	int	posx;
	int	posy;

	posx = (int)(map->pers.posx - 0.25);
	posy = (int)(map->pers.posy);
	if (map->map[posy][posx] != '1')
		map->pers.posx -= 0.25;
}

static void	do_key_s(t_map *map)
{
	int	posx;
	int	posy;

	posx = (int)(map->pers.posx);
	posy = (int)(map->pers.posy + 0.25);
	if (map->map[posy][posx] != '1')
		map->pers.posy += 0.25;
}

static void	do_key_d(t_map *map)
{
	int	posx;
	int	posy;

	posx = (int)(map->pers.posx + 0.25);
	posy = (int)(map->pers.posy);
	if (map->map[posy][posx] != '1')
		map->pers.posx += 0.25;
}

int	g_do_keys(int keycode, t_map *map)
{
	if (keycode == 53)
	{
//		map->close_state = 3;
		close_win(map);
	}
	if (keycode == 13)
		do_key_w(map);
	else if (keycode == 0)
		do_key_a(map);
	else if (keycode == 1)
		do_key_s(map);
	else if (keycode == 2)
		do_key_d(map);
//	printf("%d ", keycode);
	mlx_clear_window(map->mlx.mlx, map->mlx.win);
	draw_minimap(map);

//	draw_map(map);
//	draw_objects(map);
	return (0);
}

