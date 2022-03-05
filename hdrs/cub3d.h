/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/24 19:05:50 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "libft.h"

# define BUFFER_SIZE 10
# define MOVE_SPEED 0.1
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
}	t_mlx;

typedef struct s_vars
{
	t_interface	path_no;
	t_interface	path_so;
	t_interface	path_we;
	t_interface	path_ea;
	int			floor_clr;
	int			ceil_clr;
}	t_vars;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_map
{
	t_vars		vars;
	char		**map;
	int			map_width;
	int			map_height;
	t_mlx		mlx;
	t_hero		pers;
	t_interface	back;
	t_keys		key;
}	t_map;

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

/*	mseastar	*/
char	**m_map_create(t_list *map, t_map *mapa);
void	m_rgb_to_dec(int *array, int *num);
int		m_atoi(const char *str, int *i);
int		m_check_fname(char *str);
int		m_check_map(t_map *map);
int		m_check_param(t_vars *vars, char **map);
int		m_pars(char **av, t_map *map);
int		m_pars_map(char *str, int fd, t_list **lst_map);
int		m_pars_param(char *str, t_map *map);
int		m_error(char *str);
int		m_perror_r(char *str);
int		m_close_fd(int fd);
int		m_lst_size(t_list **lst_a);
int		m_lstclear(t_list **list);
int		m_lstadd_back(t_list **lst, char *str);
int		m_free_util(char *str);
int		m_file_to_image(char *util, t_map *map, t_interface *path);
/*	mseastar	*/

/*	gernesto	*/
void	my_mlx_pixel_put(t_interface *data, int x, int y, int color);
int		close_win(t_map *map);
int		press_key(int keycode, t_map *map);
int		release_key(int keycode, t_keys *key);
void	check_buttons(t_map *map);
void	do_cam_rot(double *dir, int keycode);
double	cast_on_y(t_map *map, double posx, double posy, double dir);
double	cast_on_x(t_map *map, double posx, double posy, double dir);
int		shade_color(int color, double divide);
void	draw_walls(t_map *map);
/*	gernesto	*/

#endif
