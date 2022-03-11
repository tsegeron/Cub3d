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

#include "../../hdrs/cub3d_bonus.h"

static void	move_mouse(void *win, int *mouse_x, int win_width, int win_height)
{
	int			mouse_y;

	mlx_mouse_get_pos(win, mouse_x, &mouse_y);
	if (mouse_y < -25)
		mouse_y = win_height;
	else if (mouse_y > win_height)
		mouse_y = -25;
	if (*mouse_x < 0)
		*mouse_x = win_width;
	else if (*mouse_x > win_width)
		*mouse_x = 0;
	mlx_mouse_move(win, *mouse_x, mouse_y);
}

void	handle_mouse_pos(t_map *map)
{
	static int	save_x;
	int			mouse_x;

	move_mouse(map->mlx.win, &mouse_x, \
	map->mlx.win_size_x, map->mlx.win_size_y);
	if (map->screen_stat == NOSCREEN && save_x && mouse_x != save_x)
	{
		if (mouse_x - save_x > 1000 || (mouse_x < save_x \
		&& save_x - mouse_x < 1000))
			do_cam_rot(&map->pers.dir, 123);
		else if (save_x - mouse_x > 1000 || mouse_x > save_x)
			do_cam_rot(&map->pers.dir, 124);
	}
	save_x = mouse_x;
}
