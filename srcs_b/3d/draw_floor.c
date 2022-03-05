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

#include "../../hdrs/cub3d_bonus.h"
#include "./L3d.h"

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
		q->floor_clr = shade_color(q->floor_clr,
				(800 - q->rad + q->res) / 64. / 1.9);
		while (q->startx < q->endx)
			my_mlx_pixel_put(background, q->startx++, q->endy, q->floor_clr);
	}
}
