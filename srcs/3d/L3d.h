/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L2d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/24 19:05:50 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef L3D_H
# define L3D_H

typedef struct s_local
{
	double		dist;
	double		x;
	double		y;
	t_interface	wall_img;
	int			side;
}	t_wall_clr;

typedef struct s_local_vars
{
	int	startx;
	int	starty;
	int	endx;
	int	endy;
	int	y;
	int	savex;
	int	wall_clr;
	int	floor_clr;
	int	ceil_clr;
	int	rad;
	int	res;
}	t_local;

void	draw_ceil(t_local *q, t_interface *background, int color);
void	draw_floor(t_local *q, t_interface *background, int color);
void	get_wall_info(t_map *map, t_wall_clr *data, double dir);
void	get_ea_we_data(t_vars *vars, t_wall_clr *data, double dist, double dir);
void	get_no_so_data(t_vars *vars, t_wall_clr *data, double dist, double dir);
void	calc_tex_dims(t_wall_clr *data, double dir, double persx, double persy);
int		get_pixel(t_interface wall, double x, double y);
#endif
