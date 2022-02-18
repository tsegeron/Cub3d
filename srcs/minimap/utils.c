/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:12:05 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/17 23:31:14 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

//	paints a pixel
void	my_mlx_pixel_put(t_interface *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// draws one line from x,y {160pix,100pix} (center of minimap) to endx,endy
void	draw_line(t_interface map, double endx, double endy, int color)
{
	double	startx;
	double	starty;
	double	deltax;
	double	deltay;
	double	pixels;

	startx = MAPW_HALF;
	starty = MAPH_HALF;
	deltax = endx - startx;
	deltay = endy - starty;
	pixels = 100;
	deltax /= pixels;
	deltay /= pixels;
	while (pixels-- > 0)
	{
		my_mlx_pixel_put(&map, startx, starty, color);
		startx += deltax;
		starty += deltay;
	}
}
