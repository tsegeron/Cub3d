/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_file_to_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

int	m_file_to_image(char *util, t_map *map, t_interface *path)
{
	if (!ft_strcmp(util + ft_strlen(util) - 4, ".xpm"))
	{
		path->img = mlx_xpm_file_to_image(map->mlx.mlx, util, \
		&path->size_x, &path->size_y);
		if (!path->img)
			return (m_free_util(util) && m_error("Wrong path"));
		path->addr = mlx_get_data_addr(path->img, &path->bits_per_pixel, \
		&path->line_length, &path->endian);
	}
	return (0);
}
