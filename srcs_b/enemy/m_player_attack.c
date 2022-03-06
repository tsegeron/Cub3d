#include "../../hdrs/cub3d_bonus.h"

//static void m_del_enemy(int num_enemy, t_map *map)
//{
//	t_vilian	*step;
//	t_vilian	*del;
//
//	step = map->vilian;
//	while (step)
//	{
//		if (step->next->num_vil == num_enemy)
//		{
//			del = step->next;
//			step->next = del->next;
//			free(del);
//		}
//		step = step->next;
//	}
//}

int	m_player_attack(int keycode, int mouse_x, int mouse_y, t_map *map)
{
	t_vilian	*step;
	double		dir_to_enemy;
	double	vec_a[2];
	double	vec_b[2];

	if (keycode != 1 && keycode != 2)
		return (1);
	(void)mouse_x;
	(void)mouse_y;
	vec_b[0] = -1;
	vec_b[1] = 0;
	step = map->vilian;
	while (step)
	{
		if (step->status_action == 2 && step->health)
		{
			vec_a[0] = -(step->x - map->pers.posx);
			vec_a[1] = -(step->y - map->pers.posy);
			dir_to_enemy = ((vec_a[0] * vec_b[0]) + (vec_a[1] * vec_b[1])) / \
		(sqrt((vec_a[0] * vec_a[0]) + (vec_a[1] * vec_a[1])) * \
			sqrt((vec_b[0] * vec_b[0]) + (vec_b[1] * vec_b[1])));
			if (step->y < map->pers.posy)
				dir_to_enemy = fabs(acos(dir_to_enemy));
			else
				dir_to_enemy = 2 * PI - fabs(acos(dir_to_enemy));
//			if (dir_to_enemy > map->pers.dir)
			if (fabs(dir_to_enemy - map->pers.dir) < PI / 6)
				step->health = 0;
//			if (dir_to_enemy <= map->pers.dir)
//				if (map->pers.dir - dir_to_enemy < PI / 6)
//					step->health = 0;
		}
		step = step->next;
	}
	return (0);
}