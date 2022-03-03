#include "hdrs/cub3d_bonus.h"

int	main(int ac, char **av)
{
	t_map	map;

	/* ---Parsing--- */
	if (ac != 2 || m_pars(av, &map))
		return (EXIT_FAILURE);
	t_vilian *step;

	step = map.vilian;
	map.map_height = (int)ft_len_array(map.map);
	while (step)
	{
		printf("NUM VIL : %d\nPOSX VIL : %f\nPOSY VIL : %f\n", step->num_vil, step->x, step->y);
		step = step->next;
	}
	for ( int i = 0;map.map[i]; i++)
		printf("%s\n", map.map[i]);
	step = map.vilian;
	while (map.map)
	{
		if (!step)
			step = map.vilian;
		m_move_enemy(step, &map);
		printf("POS X : %f\nPOS Y : %f\nNUM VIL : %d\nVIL DIR : %f\n", step->x, step->y, step->num_vil, step->dir);
		step = step->next;
	}
}
