/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"
#include "./L3d.h"

static void	get_color(int res, int rad, int *color, int ceil_clr)
{
	if (res >= rad && res < rad + 135)
		(*color) = ceil_clr;
	else if (res >= rad + 135 && res < rad + 200)
		(*color) = ceil_clr + 570425344;
	else if (res >= rad + 200 && res < rad + 240)
		(*color) = ceil_clr + 1140850688;
	else if (res >= rad + 240 && res < rad + 265)
		(*color) = ceil_clr + 1711276032;
	else if (res >= rad + 265 && res < rad + 285)
		(*color) = ceil_clr - 2013265920;
	else if (res >= rad + 285 && res < rad + 300)
		(*color) = ceil_clr - 1442840576;
	else if (res >= rad + 300 && res < rad + 309)
		(*color) = ceil_clr - 872415232;
	else if (res >= rad + 309 && res < rad + 317)
		(*color) = ceil_clr - 587202560;
	else
		(*color) = ceil_clr - 301989888;
}

void	draw_ceil(t_local *q, t_interface *background, int color)
{
	while (++q->y < q->starty)
	{
		q->startx = q->savex;
		q->res = sqrt((q->y + q->rad) * (q->y + q->rad)
				+ (q->startx - 660) * (q->startx - 660));
//		printf("%d\n", q->res);
//		exit(0);
//		get_color(q->res, q->rad, &q->ceil_clr, color);
		q->ceil_clr = color;
		q->ceil_clr = shade_color(q->ceil_clr, (q->res - 3000) / 64. / 1.1);
		while (q->startx < q->endx)
			my_mlx_pixel_put(background, q->startx++, q->y, q->ceil_clr);
	}
}
