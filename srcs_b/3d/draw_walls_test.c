#include "../../hdrs/cub3d.h"
#include "./L3d.h"

static int	get_pixel(t_interface wall, double x, double y)
{
	int		*dst;
	int		color;

	dst = (void *)wall.addr + ((int )y * wall.line_length + (int )x * (wall.bits_per_pixel / 8));
	color = *(int *)dst;
	return (color);
}

static void	get_wall_info(t_map *map, t_wall_clr *data, double dir)
{
	double	dist_on_y;
	double	dist_on_x;

	dist_on_y = cast_on_y(map, map->pers.posx, map->pers.posy, dir);
	dist_on_x = cast_on_x(map, map->pers.posx, map->pers.posy, dir);
	if (dist_on_y > dist_on_x)
	{
		if ((dir < 1.5 * PI && dir > PI2) || (dir < 3.5 * PI && dir > 2.5 * PI))
			data->wall_img = map->vars.path_we;
		else
			data->wall_img = map->vars.path_ea;
		data->dist = dist_on_x;
	}
	else
	{
		if ((dir < PI && dir > 0) || (dir < 3 * PI && dir > 2 * PI))
			data->wall_img = map->vars.path_no;
		else
			data->wall_img = map->vars.path_so;
		data->dist = dist_on_y;
	}

	data->y = fabs(sin(dir) * data->dist);
	data->x = fabs(cos(dir) * data->dist);
	if (dir < PI && dir > 0)
		data->y = -data->y;
	if (dir > PI2 && dir < PI2 * 3)
		data->x = -data->x;
	data->x += map->pers.posx;
	data->y += map->pers.posy;
	data->x -= floor(data->x);
	data->y -= floor(data->y);
}

static void	draw_line_w(t_map *map, int lineh, t_wall_clr wall, int x)
{
	t_local	q;
	int		pix_start;
	int		pix_step;

	q.rad = 3000;
	q.starty = 400 - lineh;
	q.endy = 400 + lineh;
	q.savex = x * 2;
	q.endx = (x + 1) * 2;
	q.y = -1;
	if (q.starty < 0)
		q.starty = 0;
	if (q.endy > 800)
		q.endy = 800;
	draw_ceil(&q, &map->background, map->vars.ceil_clr);

	pix_start = (int )(q.starty / 12.5);
	pix_step = (int )(64 / lineh * 2);
	while (q.starty < q.endy)
	{
		q.startx = q.savex;
		q.wall_clr = get_pixel(wall.wall_img, wall.x * 64, pix_start);
		while (q.startx < q.endx)
			my_mlx_pixel_put(&map->background, q.startx++, q.starty, q.wall_clr);
		pix_start += pix_step;
		q.starty++;
	}

	draw_floor(&q, &map->background, map->vars.floor_clr);

}

void	draw_walls_test(t_map *map)
{
	t_wall_clr	data;
	double		dir_start;
	double		dir_end;
	double		delta_dir;
	int			lineh;
	int			x;

	dir_end = map->pers.dir + FOV2;
	if (dir_end > PI * 2)
		dir_end -= PI * 2;
	dir_start = dir_end - 2 * FOV2;


	x = 659;
	while (dir_end > dir_start && x > -1)
	{
		delta_dir = map->pers.dir - dir_start;
		if (delta_dir < 0)
			delta_dir += 2 * PI;
		else if (delta_dir > 2 * PI)
			delta_dir -= 2 * PI;

		get_wall_info(map, &data, dir_start);
		data.dist *= cos(delta_dir);

		lineh = 800 / data.dist;
		if (lineh > 800)
			lineh = 800;
		lineh /= 2;

		draw_line_w(map, lineh, data, x);
		dir_start += 0.00158666;
		x--;
	}
}
