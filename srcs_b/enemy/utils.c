#include "../../hdrs/cub3d_bonus.h"

void	m_change_dir_to_hero(t_vilian *vil, t_hero *hero)
{
	double	dir;

	dir = (hero->posx - vil->x) / sqrt(((hero->posx - vil->x) * \
	(hero->posx - vil->x)) + ((hero->posy - vil->y) * (hero->posy - vil->y)));
	vil->dir = acos(dir) + GR;
}

double	ray_cast_vil(t_map *map, double dir)
{
	double	dist_on_y;
	double	dist_on_x;
	double	dist;

	dist_on_y = cast_on_y(map, map->vilian->x, map->vilian->y, dir);
	dist_on_x = cast_on_x(map, map->vilian->x, map->vilian->y, dir);
	if (dist_on_y > dist_on_x)
		dist = dist_on_x;
	else
		dist = dist_on_y;
	return (dist);
}

int	m_check_vil_vil(t_vilian *vilian, t_vilian *now, \
double posx, double posy)
{
	t_vilian	*step;

	step = vilian;
	while (step)
	{
		if (fabs(step->x - posx) <= 1 && \
			fabs(step->y - posy) <= 1 && \
			step->num_vil != now->num_vil)
			return (1);
		step = step->next;
	}
	return (0);
}

void	m_change_vil_dir(t_vilian *vil)
{
	int	util;

	util = rand() % 4;
	if (util == 0)
		vil->dir = PI / 2 + GR;
	if (util == 1)
		vil->dir = 3 * PI / 2 + GR;
	if (util == 2)
		vil->dir = PI + GR;
	else
		vil->dir = GR;
}
