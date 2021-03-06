/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_keys.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:23:55 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/17 15:23:59 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

int	handle_mouse_keys(int keycode, int mouse_x, int mouse_y, t_map *map)
{
	if (keycode == 1 || keycode == 2)
	{
		if (map->screen_stat == NOSCREEN)
			m_player_attack(map);
		else if (map->screen_stat == START)
		{
			if (mouse_y > 587 && mouse_y < 657)
			{
				if (mouse_x > 815 && mouse_x < 1165)
					close_win(map);
				else if (mouse_x > 155 && mouse_x < 505)
					map->screen_stat = NOSCREEN;
			}
		}
		else if (map->screen_stat == MENU && mouse_x > 465 && mouse_x < 815)
		{
			if (mouse_y > 300 && mouse_y < 370)
				map->screen_stat = NOSCREEN;
			else if (mouse_y > 400 && mouse_y < 470)
				close_win(map);
		}
	}
	return (0);
}
