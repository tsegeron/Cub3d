#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "libft.h"

# define BUFFER_SIZE 10
# define MOVE_SPEED 0.1
# define MAPW 220
# define MAPW_HALF 110
# define MAPH 220
# define MAPH_HALF 110
# define FOV 0xEE546951
# define PI 3.14159265
# define PI2 1.57079632
# define GR 0.017452
# define FOV2 0.523599

/*	colors	*/
# define EMPTY 0xFF000000
# define BACKGR 0xCC000000
# define WALL 0x77000000
//# define DWALL 0x00F9F2C3
# define CEIL 0x0051A889
# define FLOOR 0x00426A37
# define VOID 0xAA000000
# define CDOOR 0x44560319
# define ODOOR 0x77013220
# define CURE 0x008DB600
# define BATTERY 0x0018BC9C
# define PLAYER 0x00155054
# define AIM 0x33FF0000
# define NO 0x00F9F2C3
# define SO 0x00568C74
# define WE 0x00683245
# define EA 0x007DB84D

typedef enum
{
	NOSCREEN,
	START,
	MENU,
	END
}	t_screenstat;


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
	int		charge;
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

typedef struct s_vars
{
	void	*path_no;
	void	*path_so;
	void	*path_we;
	void	*path_ea;
	int		flor_long;
	int		cel_long;
}	t_vars;

typedef struct s_map
{
	t_vars		vars;
	char		**map;
	int			map_width;
	int			map_height;
	int			screen_stat;
	t_mlx		mlx;
	t_hero		pers;
	t_interface	round_minmap;
	t_interface	battery_bar;
	t_interface	background;
	t_interface	health;
	t_interface	start_screen;
	t_interface	menu_screen;
	t_interface	end_screen;
}	t_map;

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

/*	mseastar	*/
int		m_atoi(const char *str, int *i);
int		m_check_fname(char *str);
int		m_check_map(t_map *map);
int		m_check_param(t_vars *vars, char **map);
char	**m_map_create(t_list *map, t_map *mapa);
int		m_pars(char **av, t_map *map);
int		m_pars_map(char *str, int fd, t_list **lst_map);
int		m_pars_param(char *str, t_map *map);
void	m_rgb_to_dec(int *array, int *num);
int		m_error(char *str);
int		m_perror_r(char *str);
int		m_close_fd(int fd);
int		m_lst_size(t_list **lst_a);
int		m_lstclear(t_list **list);
int		m_lstadd_back(t_list **lst, char *str);
/*	mseastar	*/

/*	gernesto	*/
int		close_win(t_map *map);
void	do_cam_rot(double *dir, int keycode);
int		g_do_keys(int keycode, t_map *map);
void	handle_mouse_pos(t_map *map);
int		handle_mouse_keys(int keycode, int mouse_x, int mouse_y, t_map *map);
void	my_mlx_pixel_put(t_interface *data, int x, int y, int color);
void	draw_line(t_interface map, double endx, double endy, int color);
double	cast_on_y(t_map *map, double posx, double posy, double dir);
double	cast_on_x(t_map *map, double posx, double posy, double dir);
double	ray_cast(t_map *map, double dir, int stat);
void	draw_minimap(t_map *map);
void	draw_interface(t_map *map);
void	draw_battery_bar(t_map *map);
void	draw_health_effect(t_map *map);
void	draw_background(t_map *map);	//	FOR TEST
void	draw_round_minimap(t_map *map);
void	draw_minimap_elements(t_map *map);
void	draw_start_screen(t_map *map);
void	draw_menu_screen(t_map *map);
void	draw_end_screen(t_map *map);

void	draw_walls(t_map *map);
void	draw_ceil_and_floor(t_map *map);
void	draw_lightning(t_map *map);
/*	gernesto	*/

#endif
