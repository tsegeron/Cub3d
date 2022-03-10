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

#include "../../hdrs/cub3d_bonus.h"
#include "./L3d.h"

void	draw_ceil(t_local *q, t_interface *background, int color)
{
	while (++q->y < q->starty)
	{
		q->startx = q->savex;
		q->res = (int )sqrt((q->y + q->rad) * (q->y + q->rad)
				+ (q->startx - 660) * (q->startx - 660));
		q->ceil_clr = color;
		if (q->res - q->rad > 345)
			q->ceil_clr = 0xFF000000;
		else
			q->ceil_clr = add_transparency(color, (q->res - q->rad) / 23.);
		while (q->startx < q->endx)
			my_mlx_pixel_put(background, q->startx++, q->y, q->ceil_clr);
	}
}
