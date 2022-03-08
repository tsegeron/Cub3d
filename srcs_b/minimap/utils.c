/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:12:05 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/22 18:34:02 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

//	paints a pixel
void	my_mlx_pixel_put(t_interface *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// draws one line from x,y {110pix,110pix} (center of ray_cast) to endx,endy
void	draw_line(t_interface map, double endx, double endy, int color)
{
	double	start[2];
	double	delta[2];
	double	pixels;

	start[0] = map.size_x / 2;
	start[1] = map.size_y / 2;
	delta[0] = endx - start[0];
	delta[1] = endy - start[1];
	pixels = sqrt(delta[0] * delta[0] + delta[1] * delta[1]) / 2;
	delta[0] /= pixels;
	delta[1] /= pixels;
	while (pixels-- > 0)
	{
		my_mlx_pixel_put(&map, start[0], start[1], color);
		start[0] += delta[0];
		start[1] += delta[1];
	}
}
