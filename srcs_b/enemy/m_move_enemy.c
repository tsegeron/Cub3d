#include "../../hdrs/cub3d_bonus.h"

static void	m_move_lite(t_vilian *vil, char **map, t_vilian *begin)
{
	int		posx;
	int		posy;
	double	difx;
	double	dify;
	int		status;

	difx = (MOVE_SPEED) * cos(vil->dir);
	dify = -(MOVE_SPEED) * sin(vil->dir);
	posx = (int)(vil->x + difx + MOVE_SPEED * difx / fabs(difx));
	posy = (int)(vil->y + dify + MOVE_SPEED * dify / fabs(dify));
	if (map[(int)vil->y][posx] != '1' && map[(int)vil->y][posx] != 'C' && \
		!m_check_vil_vil(begin, vil, posx, vil->y))
	{
		vil->x += difx;
		status = 1;
	}
	if (map[posy][(int)vil->x] != '1' && map[posy][(int)vil->x] != 'C' && \
		!m_check_vil_vil(begin, vil, vil->x, posy))
	{
		vil->y += dify;
		status = 1;
	}
	if (!status)
		m_change_vil_dir(vil);
}

static void	m_move_angry(t_vilian *vil, t_vilian *begin, t_map *map)
{
	int		posx;
	int		posy;
	double	difx;
	double	dify;

	difx = (MOVE_SPEED) * cos(vil->dir);
	dify = -(MOVE_SPEED) * sin(vil->dir);
	posx = (int)(vil->x + difx + MOVE_SPEED * difx / fabs(difx));
	posy = (int)(vil->y + dify + MOVE_SPEED * dify / fabs(dify));
	if (map->map[posy][posx] != '1' && \
		map->map[posy][posx] != 'C' && \
			!m_check_vil_vil(begin, vil, posx, posy))
	{
		vil->y += dify;
		vil->x += difx;
	}
}

void	m_rad_lumus(t_vilian *vilian, t_map *map, int status)
{
	double	res;
	double	rad;
	double	line;
	double	dir_old;

	if (status)
		rad = 4;
	else
		rad = 1;
	res = sqrt((double)(powf((float)(vilian->x - map->pers.posx), 2) + \
		powf((float)(vilian->y - map->pers.posy), 2)));
	dir_old = vilian->dir;
	m_change_dir_to_hero(vilian, &map->pers);
	line = ray_cast_vil(map, vilian->dir);
	if (res <= rad && line >= res)
	{
		printf("AGR!!!!\n");
		if (res <= 1)
		{
			printf("DEAD\nX pers : %f\n Y pers : %f\n", map->pers.posx, map->pers.posy);
			exit(10);
		}
		vilian->status_agr = 1;
	}
	else
	{
		vilian->dir = dir_old;
		vilian->status_agr = 0;
	}
}

int	m_angry(t_vilian *vil_begin, t_map * map)
{
	t_vilian	*step;

	step = vil_begin;
	while (step)
	{
		if (map->pers.charge)
			m_rad_lumus(step, map, 1);
		else
			m_rad_lumus(step, map, 0);
		step = step->next;
	}
	return (0);
}

int m_move_enemy(t_vilian *vilian, t_map *map)
{
	t_vilian	*step;

	step = vilian;
	while (step)
	{
		m_angry(vilian, map);
		if (!step->status_agr)
			m_move_lite(step, map->map, vilian);
		else
			m_move_angry(step, vilian, map);
		step = step->next;
	}
	return (0);
}
