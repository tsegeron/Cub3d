/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_file_to_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:34:59 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/08 22:14:55 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

int	m_file_to_image(char *util, t_map *map, t_interface *path)
{
	if (!ft_strcmp(util + ft_strlen(util) - 4, ".xpm"))
	{
		path->img = mlx_xpm_file_to_image(map->mlx.mlx, util,
				&path->size_x, &path->size_y);
		if (!path->img)
			return (m_free_util(util) && m_error("Wrong path"));
		path->addr = mlx_get_data_addr(path->img, &path->bits_per_pixel,
				&path->line_length, &path->endian);
	}
	free(util);
	return (0);
}
