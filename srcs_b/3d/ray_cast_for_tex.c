/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:51:02 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/22 18:34:02 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

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

static int	check_cell_symb(char sym, char stat)
{
	if (stat == 'D')
	{
		if (sym == '1' || sym == 'C' || sym == '#' || sym == 'P')
			return (1);
	}
	else if (stat == 'W')
	{
		if (sym == '1' || sym == 'C' || sym == '#')
			return (2);
	}
	return (0);
}

/*
 * returns the path length to that coordinate
 * (from pers position to HORIZONTALLY wall crossing coordinate)
 */
static double	find_wall_on_y(t_map *map, t_local *q, char stat)
{
	if (q->cur_x >= map->map_width)
		q->cur_x = map->map_width - 1;
	if (q->cur_x < 0)
		q->cur_x = 0;
	while (!check_cell_symb(map->map[(int)q->cur_y + \
	q->dif_y][(int)q->cur_x], stat))
	{
		q->cur_y += q->step_y;
		q->cur_x = (q->pos_y - q->cur_y) / tan(q->dir) + q->pos_x;
		if (q->cur_x >= map->map_width)
			q->cur_x = map->map_width - 1;
		if (q->cur_x < 0)
			q->cur_x = 0;
	}
	return (sqrt((q->cur_x - q->pos_x) * (q->cur_x - q->pos_x) \
	+ (q->cur_y - q->pos_y) * (q->cur_y - q->pos_y)));
}

/*
 * finds closest HORIZONTALLY wall crossing Y coordinate towards view direction
 */
double	cast_on_y_tex(t_map *map, double dir, char stat)
{
	t_local	q;

	q.dif_y = 0;
	if (dir < PI && dir > 0)
	{
		q.cur_y = floor(map->pers.posy);
		q.cur_x = (map->pers.posy - q.cur_y) / tan(dir) + map->pers.posx;
		q.step_y = -1;
		q.dif_y = -1;
	}
	else if (dir == 0 || dir == PI)
	{
		q.cur_x = map->pers.posx;
		q.cur_y = map->pers.posy;
	}
	else
	{
		q.cur_y = ceil(map->pers.posy);
		q.cur_x = (map->pers.posy - q.cur_y) / tan(dir) + map->pers.posx;
		q.step_y = 1;
	}
	q.pos_x = map->pers.posx;
	q.pos_y = map->pers.posy;
	q.dir = dir;
	return (find_wall_on_y(map, &q, stat));
}

/*
 * returns the path length to that coordinate
 * (from pers position to VERTICALLY wall crossing coordinate)
 */
static double	find_wall_on_x(t_map *map, t_local *q, char stat)
{
	if (q->cur_y >= map->map_height)
		q->cur_y = map->map_height - 1;
	if (q->cur_y < 0)
		q->cur_y = 0;
	while (!check_cell_symb(map->map[(int)q->cur_y][(int)q->cur_x + \
	q->dif_x], stat))
	{
		q->cur_x += q->step_x;
		q->cur_y = (q->cur_x - q->pos_x) * -tan(q->dir) + q->pos_y;
		if (q->cur_y >= map->map_height)
			q->cur_y = map->map_height - 1;
		if (q->cur_y < 0)
			q->cur_y = 0;
	}
	return (sqrt((q->cur_x - q->pos_x) * (q->cur_x - q->pos_x) \
	+ (q->cur_y - q->pos_y) * (q->cur_y - q->pos_y)));
}

/*
 * finds closest VERTICALLY wall crossing X coordinate towards view direction
 */
double	cast_on_x_tex(t_map *map, double dir, char stat)
{
	t_local	q;

	q.dif_x = 0;
	if (dir > PI2 && dir < 1.5 * PI)
	{
		q.cur_x = floor(map->pers.posx);
		q.cur_y = (q.cur_x - map->pers.posx) * -tan(dir) + map->pers.posy;
		q.step_x = -1;
		q.dif_x = -1;
	}
	else if (dir == PI2 || dir == PI2 * 3)
	{
		q.cur_x = map->pers.posx;
		q.cur_y = map->pers.posy;
	}
	else
	{
		q.cur_x = ceil(map->pers.posx);
		q.cur_y = (q.cur_x - map->pers.posx) * -tan(dir) + map->pers.posy;
		q.step_x = 1;
	}
	q.pos_x = map->pers.posx;
	q.pos_y = map->pers.posy;
	q.dir = dir;
	return (find_wall_on_x(map, &q, stat));
}
