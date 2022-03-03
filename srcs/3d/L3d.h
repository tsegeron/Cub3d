#ifndef L3D_H
#define L3D_H

typedef struct s_local
{
	double		dist;
	double		x;
	double		y;
	int			color;
	t_interface	wall_img;
//	int		wall_clr;
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
	int	dim_factor;
	int	rad;
	int	res;
}	t_local;

void	draw_ceil(t_local *q, t_interface *background, int color);
void	draw_floor(t_local *q, t_interface *background, int color);

#endif
