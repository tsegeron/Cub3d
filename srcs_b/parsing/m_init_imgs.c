#include "../../hdrs/cub3d_bonus.h"

static int	m_open_addr(t_interface *path, char *str, void *mlx)
{
	path->img = mlx_xpm_file_to_image(mlx, str,
			&path->size_x, &(path)->size_y);
	if (!path->img)
		return (m_perror_r("Error: mlx"));
	path->addr = mlx_get_data_addr(path->img, \
	&path->bits_per_pixel, &path->line_length, &path->endian);
	return (EXIT_SUCCESS);
}

int	m_init_imgs(t_vars *vars, void *mlx)
{
	if (m_open_addr(&(vars->door), "textures/door.xpm", mlx) || \
		m_open_addr(&(vars->wand), "textures/wand.xpm", mlx) || \
        m_open_addr(&vars->light, "textures/light.xpm", mlx))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}