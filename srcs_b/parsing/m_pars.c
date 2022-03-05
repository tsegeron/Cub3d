#include "../../hdrs/cub3d_bonus.h"

int	m_close_fd(int fd)
{
	close(fd);
	return (1);
}

static int	m_read_gnl(int fd, t_list **lst_map, t_map *map)
{
	char	*str;
	int		status;

	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		status = m_pars_param(str, map);
		if (status < 0)
			return (m_close_fd(fd));
		else if (status)
			return (m_pars_map(str, fd, lst_map));
		free(str);
	}
	return (m_close_fd(fd) * 0);
}

static int	m_init_imgs(t_vars *vars, void *mlx)
{
	vars->door.img = mlx_xpm_file_to_image(mlx, "./textures/door.xpm", \
	&vars->door.size_x, &vars->door.size_y);
	vars->door.addr = mlx_get_data_addr(vars->door.img, \
	&vars->door.bits_per_pixel, &vars->door.line_length, &vars->door.endian);
//	vars->enemy.img = mlx_xpm_file_to_image(mlx, "textures/enemy.xpm", \
//	&vars->enemy.size_x, &vars->enemy.size_y);
//	vars->enemy.addr = mlx_get_data_addr(vars->enemy.img, \
//	&vars->enemy.bits_per_pixel, &vars->enemy.line_length, \
//	&vars->enemy.endian);
//	vars->cure.img = mlx_xpm_file_to_image(mlx, "textures/cure.xpm", \
//	&vars->cure.size_x, &vars->cure.size_y);
//	vars->cure.addr = mlx_get_data_addr(vars->cure.img, \
//	&vars->cure.bits_per_pixel, &vars->cure.line_length, &vars->cure.endian);
//	vars->charge.img = mlx_xpm_file_to_image(mlx, "textures/charge.xpm", \
//	&vars->charge.size_x, &vars->charge.size_y);
//	vars->charge.addr = mlx_get_data_addr(vars->charge.img, \
//	&vars->charge.bits_per_pixel, &vars->charge.line_length, \
//	&vars->charge.endian);
//	if (!vars->charge.img || !vars->enemy.img || !vars->door.img || \
//		!vars->cure.img)
	if (!vars->door.img)
		exit(m_perror_r("Error: mlx_xpm_file_to_image"));
	return (EXIT_SUCCESS);
}

static void	m_init_param(t_vars *vars)
{
	vars->path_no.img = NULL;
	vars->path_so.img = NULL;
	vars->path_we.img = NULL;
	vars->path_ea.img = NULL;
	vars->ceil_clr = -1;
	vars->floor_clr = -1;
}

int	m_pars(char **av, t_map *map)
{
	t_list	*lst_map;
	int		fd;

	lst_map = NULL;
	map->map = NULL;
	map->mlx.mlx = mlx_init();
	if (!map->mlx.mlx)
		return (EXIT_FAILURE);
	m_init_param(&map->vars);
	if (m_check_fname(av[1]))
		return (EXIT_FAILURE);
	fd = open(av[1], O_RDONLY, 0644);
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (m_perror_r("Fd") && m_close_fd(fd));
	if (m_read_gnl(fd, &lst_map, map))
		return (EXIT_FAILURE);
	(map->map) = m_map_create(lst_map, map);
	m_lstclear(&lst_map);
	if (!(map->map))
		return (EXIT_FAILURE);
	m_close_fd(fd);
	m_init_imgs(&map->vars, map->mlx.mlx);
	return (m_check_param(&map->vars, map->map) || m_check_map(map));
}
