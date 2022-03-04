/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"
#include "./L3d.h"

static void	get_color(int res, int rad, int *color, int floor_clr)
{
	if (res >= rad - 800 && res < rad - 800 + 135)
		(*color) = floor_clr;
	else if (res >= rad - 800 + 135 && res < rad - 800 + 200)
		(*color) = floor_clr + 570425344;
	else if (res >= rad - 800 + 200 && res < rad - 800 + 240)
		(*color) = floor_clr + 1140850688;
	else if (res >= rad - 800 + 240 && res < rad - 800 + 265)
		(*color) = floor_clr + 1711276032;
	else if (res >= rad - 800 + 265 && res < rad - 800 + 285)
		(*color) = floor_clr - 2013265920;
	else if (res >= rad - 800 + 285 && res < rad - 800 + 300)
		(*color) = floor_clr - 1442840576;
	else if (res >= rad - 800 + 300 && res < rad - 800 + 309)
		(*color) = floor_clr - 872415232;
	else if (res >= rad - 800 + 309 && res < rad - 800 + 317)
		(*color) = floor_clr - 587202560;
	else if (res >= rad - 800 + 317)
		(*color) = floor_clr - 301989888;
}

int	shade_color_f(int color, double divide)
{
	if (divide <= 1.)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / divide) << 16)
			+ ((int)(((0x00FF00 & color) >> 8) / divide) << 8)
			+ ((int)((0x0000FF & color) / divide)));
}

void	draw_floor(t_local *q, t_interface *background, int color)
{
	q->endy = 800;
	q->rad += 800;
	while (q->starty < q->endy--)
	{
		q->startx = q->savex;
		q->res = sqrt((q->endy - q->rad) * (q->endy - q->rad)
				+ (q->startx - 660) * (q->startx - 660));
		q->floor_clr = color;
		q->floor_clr = shade_color_f(q->floor_clr, (800 - q->rad + q->res) / 64. / 1.9);
		while (q->startx < q->endx)
			my_mlx_pixel_put(background, q->startx++, q->endy, q->floor_clr);
	}
}
