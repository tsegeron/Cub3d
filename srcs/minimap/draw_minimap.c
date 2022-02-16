/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:05:46 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/16 13:07:19 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

typedef struct s_local
{
	int		pix_map_x;
	int		pix_map_y;
	int		pix_map_end_x;
	int		pix_map_end_y;
	int		save_x;
	int		pix_x;
	int		pix_y;
}	t_local;

/*
 *	just paints pixel in minimap
 */
static void	paint_pixels(t_map *map, t_local *q)
{
	q->pix_x = -1;
	q->pix_map_x = q->save_x;
	while (++q->pix_x < MAPW + 1 && ++q->pix_map_x < q->pix_map_end_x)
	{
		if (q->pix_map_x < 0)
		{
			q->pix_map_x += 6;
			q->pix_x += 6;
			continue ;
		}
		if (q->pix_map_y < 0)
		{
			q->pix_map_y += 3;
			q->pix_y += 3;
			break ;
		}
		if (!(q->pix_map_x % 32))
			continue ;
		if (map->map[(q->pix_map_y / 20)][(q->pix_map_x / 32)] == '1')
			my_mlx_pixel_put(&map->minimap, q->pix_x, q->pix_y, WALL);
		else
			my_mlx_pixel_put(&map->minimap, q->pix_x, q->pix_y, VOID);
	}
}

/*
 *	1. draws a minimap relative to the player
 */
void	draw_relative_minimap(t_map *map)
{
	t_local	q;

	q.save_x = 32 * map->pers.posx - 160;
	q.pix_map_y = 20 * map->pers.posy - 100;
	q.pix_map_end_x = q.save_x + 321;
	q.pix_map_end_y = q.pix_map_y + 201;
	if (q.pix_map_end_x > map->map_width * 32 - 1)
		q.pix_map_end_x = map->map_width * 32 - 1;
	if (q.pix_map_end_y > map->map_height * 20 - 1)
		q.pix_map_end_y = map->map_height * 20 - 1;
	q.pix_y = -1;
	while (++q.pix_y < MAPH + 1 && ++q.pix_map_y < q.pix_map_end_y)
	{
		if (!(q.pix_map_y % 20))
			continue ;
		paint_pixels(map, &q);
	}
}

/*
 *	2.	draws a rectangle which is a player
 */
void	draw_player_in_minimap(t_map *map)
{
	int		x;
	int		y;
	int		save_y;

	save_y = MAPH_HALF - 2;
	x = MAPW_HALF - 3;
	while (x < MAPW_HALF + 4)
	{
		y = save_y;
		while (y < MAPH_HALF + 3)
		{
			my_mlx_pixel_put(&map->minimap, x, y, 0x0058C878);
			y++;
		}
		x++;
	}
}

/*
 *	3.	draws field of view on minimap (60° or PI/3)
 */
void	draw_fov_in_minimap(t_map *map)
{
	double	line_end_x;
	double	line_end_y;
	double	dir_start;
	double	dir_end;

	dir_start = map->pers.dir - FOV2;
	dir_end = dir_start + 2 * FOV2;
	if (dir_end > PI * 2)
		dir_end -= PI * 2;
	dir_start = dir_end - 2 * FOV2;
	while (dir_start <= dir_end)
	{
		line_end_x = MAPW_HALF + ray_cast(map, dir_start, 0);
		line_end_y = MAPH_HALF + ray_cast(map, dir_start, 1);
		draw_line(map->minimap, line_end_x, line_end_y);
		dir_start += GR / 2;
	}
}

/*
 *	includes funcs above:
 *	1.	draws a minimap relative to the player
 *	2.	draws a rectangle which is a player
 *	3.	draws field of view on minimap (60° or PI/3)
 */
void	draw_minimap(t_map *map)
{
	map->minimap.size_x = map->mlx.win_size_x / 4;
	map->minimap.size_y = map->mlx.win_size_y / 4;
	map->minimap.img = mlx_new_image(map->mlx.mlx,
			map->minimap.size_x, map->minimap.size_y);
	map->minimap.addr = mlx_get_data_addr(map->minimap.img,
			&map->minimap.bits_per_pixel, &map->minimap.line_length,
			&map->minimap.endian);
	draw_relative_minimap(map);
	draw_player_in_minimap(map);
	draw_fov_in_minimap(map);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->minimap.img, 0, 0);
}
