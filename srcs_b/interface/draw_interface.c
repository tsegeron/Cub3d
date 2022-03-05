/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/22 19:15:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

void	draw_interface(t_map *map)
{
//	if (map->screen_stat == START)
//		draw_start_screen(map);
//	else if (map->screen_stat == MENU)
	if (map->screen_stat == MENU)
		draw_menu_screen(map);
//	else if (map->screen_stat == END)
//		draw_end_screen(map);
}

//	9DE3A2	-	cyan
//	5F6D4C	-	nasty green
