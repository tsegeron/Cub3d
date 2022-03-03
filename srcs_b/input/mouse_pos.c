/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:23:55 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/17 15:23:59 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

void	handle_mouse_pos(t_map *map)
{
	static int	save_x;
	int			mouse_x;
	int			mouse_y;

	mlx_mouse_get_pos(map->mlx.win, &mouse_x, &mouse_y);
	if (mouse_y < -25)
		mouse_y = map->mlx.win_size_y;
	else if (mouse_y > map->mlx.win_size_y)
		mouse_y = -25;
	if (mouse_x < 0)
		mouse_x = map->mlx.win_size_x;
	else if (mouse_x > map->mlx.win_size_x)
		mouse_x = 0;
	mlx_mouse_move(map->mlx.win, mouse_x, mouse_y);
	if (map->screen_stat == NOSCREEN && save_x && mouse_x != save_x)
	{
		if (mouse_x - save_x > 1000 || (mouse_x < save_x
				&& save_x - mouse_x < 1000))
			do_cam_rot(&map->pers.dir, 123);
		else if (save_x - mouse_x > 1000 || mouse_x > save_x)
			do_cam_rot(&map->pers.dir, 124);
	}
	else if (map->screen_stat != NOSCREEN)
		mlx_mouse_hook(map->mlx.win, handle_mouse_keys, map);
	save_x = mouse_x;
}
