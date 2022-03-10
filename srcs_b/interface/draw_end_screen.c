/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_end_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

void	draw_end_screen(t_map *map)
{
	mlx_clear_window(map->mlx.mlx, map->mlx.win);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, \
	map->vars.but_imgs[3].img, 0, 0);
	sleep(2);
	close_win(map);
}
