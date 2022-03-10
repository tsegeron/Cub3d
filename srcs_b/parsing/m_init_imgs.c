/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_init_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:23:55 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/17 15:23:59 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	open_but_imgs(t_imgs *path, char *str, void *mlx)
{
	path->img = mlx_xpm_file_to_image(mlx, str, &path->width, &path->height);
	if (!path->img)
		return (m_perror_r("Error: mlx"));
	return (EXIT_SUCCESS);
}

int	m_init_imgs(t_vars *vars, void *mlx)
{
	if (m_open_addr(&(vars->door), "textures/door.xpm", mlx) || \
		m_open_addr(&(vars->wand), "textures/wand.xpm", mlx))
		return (EXIT_FAILURE);
	if (open_but_imgs(&vars->but_imgs[0], "textures/continue.xpm", mlx) || \
		open_but_imgs(&vars->but_imgs[1], "textures/exit.xpm", mlx) || \
		open_but_imgs(&vars->but_imgs[2], "textures/start_screen.xpm", mlx) || \
		open_but_imgs(&vars->but_imgs[3], "textures/start_screen.xpm", mlx))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
