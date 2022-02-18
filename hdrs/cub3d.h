#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "libft.h"

# define MAPW 320
# define MAPW_HALF 160
# define MAPH 200
# define MAPH_HALF 100
# define WALL 0x00FF0000
# define VOID 0x00808080
# define FOV 0x0058C878
# define PI 3.14159265
# define PI2 1.57079632
# define GR 0.017452
# define FOV2 0.523599


typedef struct s_interface
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		size_x;
	int		size_y;
	int		posx;
	int		posy;
}	t_interface;

typedef struct s_hero
{
	double	posx;
	double	posy;
	double	dir;
	double	fov;
	int		health;
}	t_hero;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		win_size_x;
	int		win_size_y;
	int		mouse_x;
	int		mouse_y;
}	t_mlx;

typedef struct s_map
{
	char		**map;
	int			map_width;
	int			map_height;
	t_mlx		mlx;
	t_hero		pers;
	t_interface	minimap;
	t_interface	hpbar;
}	t_map;

/*	mseastar	*/
//int		m_pars(char **av, char ***map);
//int		m_check_map(char **map);
//char	**ft_map_create(t_list *map);
//int		m_pars_map(char *str, int fd);
//int		m_pars_param(char *str);
//int		m_perror_r(char *str);
//int		m_error(char *str);
/*	mseastar	*/

/*	gernesto	*/
int		close_win(t_map *map);
void	do_cam_rot(double *dir, int keycode);
int		g_do_keys(int keycode, t_map *map);
void	handle_mouse_pos(t_map *map);
void	my_mlx_pixel_put(t_interface *data, int x, int y, int color);
void	draw_line(t_interface map, double endx, double endy, int color);
double	ray_cast(t_map *map, double dir, int stat);
void	draw_minimap(t_map *map);
void	draw_interface(t_map *map);

/*	gernesto	*/

#endif
