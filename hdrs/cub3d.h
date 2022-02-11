#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "libft.h"

typedef struct s_minimap
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		minimap_size_x;
	int		minimap_size_y;
	int		posx;
	int		posy;
	//
}	t_minimap;

typedef struct s_hero
{
	double	posx;
	double	posy;
	double	dir;
	double	fov;
	//
}	t_hero;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		win_size_x;
	int		win_size_y;
}	t_mlx;

typedef struct s_map
{
	char		**map;
	int			map_width;
	int			map_height;
	t_mlx		mlx;
	t_hero		pers;
	t_minimap	minimap;
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
void	draw_minimap(t_map *map);
int		g_do_keys(int keycode, t_map *map);
/*	gernesto	*/

#endif
