/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:51:02 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/16 12:11:08 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

typedef struct s_local
{
	double	cur_x;
	double	cur_y;
	double	step_x;
	double	step_y;
	int		dif_x;
	int		dif_y;
	double	pos_x;
	double	pos_y;
	double	dir;
}	t_local;

/*
 * returns the path length to that coordinate
 * (from pers position to HORIZONTALLY wall crossing coordinate)
 */
static double	find_wall_on_y(t_map *map, t_local *q)
{
	if (q->cur_x >= map->map_width)
		q->cur_x = map->map_width - 1;
	if (q->cur_x < 0)
		q->cur_x = 0;
	while (map->map[(int)q->cur_y + q->dif_y][(int)q->cur_x] != '1'
			&& map->map[(int)q->cur_y + q->dif_y][(int)q->cur_x] != 'C')
	{
		q->cur_y += q->step_y;
		q->cur_x = (q->pos_y - q->cur_y) / tan(q->dir) + q->pos_x;
		if (q->cur_x >= map->map_width)
			q->cur_x = map->map_width - 1;
		if (q->cur_x < 0)
			q->cur_x = 0;
	}
	return (sqrt((q->cur_x - q->pos_x) * (q->cur_x - q->pos_x)
			+ (q->cur_y - q->pos_y) * (q->cur_y - q->pos_y)));
}

/*
 * finds closest HORIZONTALLY wall crossing Y coordinate towards view direction
 */
static double	cast_on_y(t_map *map, double posx, double posy, double dir)
{
	t_local	q;

	if (dir < PI && dir > 0)
	{
		q.cur_y = floor(posy);
		q.cur_x = (posy - q.cur_y) / tan(dir) + posx;
		q.step_y = -1;
		q.dif_y = -1;
	}
	else if (dir == 0 || dir == PI)
	{
		q.cur_x = posx;
		q.cur_y = posy;
	}
	else
	{
		q.cur_y = ceil(posy);
		q.cur_x = (posy - q.cur_y) / tan(dir) + posx;
		q.step_y = 1;
		q.dif_y = 0;
	}
	q.pos_x = posx;
	q.pos_y = posy;
	q.dir = dir;
	return (find_wall_on_y(map, &q));
}

/*
 * returns the path length to that coordinate
 * (from pers position to VERTICALLY wall crossing coordinate)
 */
static double	find_wall_on_x(t_map *map, t_local *q)
{
	if (q->cur_y >= map->map_height)
		q->cur_y = map->map_height - 1;
	if (q->cur_y < 0)
		q->cur_y = 0;
	while (map->map[(int)q->cur_y][(int)q->cur_x + q->dif_x] != '1'
			&& map->map[(int)q->cur_y][(int)q->cur_x + q->dif_x] != 'C')
	{
		q->cur_x += q->step_x;
		q->cur_y = (q->cur_x - q->pos_x) * -tan(q->dir) + q->pos_y;
		if (q->cur_y >= map->map_height)
			q->cur_y = map->map_height - 1;
		if (q->cur_y < 0)
			q->cur_y = 0;
	}
	return (sqrt((q->cur_x - q->pos_x) * (q->cur_x - q->pos_x)
			+ (q->cur_y - q->pos_y) * (q->cur_y - q->pos_y)));
}

/*
 * finds closest VERTICALLY wall crossing X coordinate towards view direction
 */
static double	cast_on_x(t_map *map, double posx, double posy, double dir)
{
	t_local	q;

	if (dir > PI2 && dir < 1.5 * PI)
	{
		q.cur_x = floor(posx);
		q.cur_y = (q.cur_x - posx) * -tan(dir) + posy;
		q.step_x = -1;
		q.dif_x = -1;
	}
	else if (dir == PI2 || dir == PI2 * 3)
	{
		q.cur_x = posx;
		q.cur_y = posy;
	}
	else
	{
		q.cur_x = ceil(posx);
		q.cur_y = (q.cur_x - posx) * -tan(dir) + posy;
		q.step_x = 1;
		q.dif_x = 0;
	}
	q.pos_x = posx;
	q.pos_y = posy;
	q.dir = dir;
	return (find_wall_on_x(map, &q));
}

/*
 * compares path lengths of both VERTICALLY and HORIZONTALLY
 * wall crossing routes, finds the lowest path
 * and, based on it, counts shifts on X and Y coordinates
 *
 * returns values of that shifts
 */
double	ray_cast(t_map *map, double dir, int stat)
{
	double	dist_on_y;
	double	dist_on_x;
	double	dist;

	dist_on_y = cast_on_y(map, map->pers.posx, map->pers.posy, dir);
	dist_on_x = cast_on_x(map, map->pers.posx, map->pers.posy, dir);
	if (dist_on_y > dist_on_x)
		dist = dist_on_x;
	else
		dist = dist_on_y;
	if (stat == 2)
		return (dist);
	if (dist > 5.5)
		dist = 5.5;
	dist_on_y = fabs(sin(dir) * dist) * 20;
	dist_on_x = fabs(cos(dir) * dist) * 20;
	if (dir < PI && dir > 0)
		dist_on_y = -dist_on_y;
	if (dir > PI2 && dir < PI2 * 3)
		dist_on_x = -dist_on_x;
	if (stat)
		return (dist_on_y);
	else
		return (dist_on_x);
}
