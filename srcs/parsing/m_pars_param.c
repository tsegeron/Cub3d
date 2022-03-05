/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pars_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:34:59 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/08 22:14:55 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

int	m_free_util(char *str)
{
	free(str);
	return (EXIT_FAILURE);
}

static int	m_param(char *str, t_interface *path, t_map *map)
{
	char	*util;

	if (path->img)
		free(path->img);
	util = ft_strtrim(str + 3, " ");
	if (!util)
		return (m_perror_r("Malloc"));
	if (ft_strlen(util) <= 4)
		return (m_free_util(util) + m_error("Wrong path"));
	if (m_file_to_image(util, map, path))
		return (m_perror_r("Mlx"));
	return (0);
}

int	m_pull_array(char **str_split, int *result)
{
	int	i;
	int	status;
	int	array[3];

	i = -1;
	while (str_split[++i])
	{
		array[i] = m_atoi(str_split[i], &status);
		if (status < 0)
			return (EXIT_FAILURE);
	}
	m_rgb_to_dec(array, result);
	return (0);
}

static int	m_fc_param(char *str, char chr, t_vars *vars)
{
	char	**str_split;

	str_split = ft_split(str + 2, ',');
	if (!str_split)
		return (m_perror_r("Malloc"));
	if (ft_len_array(str_split) != 3 || ft_strchr_count(str, ',') != 2)
		return (m_perror_r("Wrong argumenst for f / c\n"));
	if (chr == 'f')
		if (m_pull_array(str_split, &vars->floor_clr))
			return (ft_clear_arrray(str_split));
	if (chr == 'c')
		if (m_pull_array(str_split, &vars->ceil_clr))
			return (ft_clear_arrray(str_split));
	return (ft_clear_arrray(str_split) * 0);
}

int	m_pars_param(char *str, t_map *map)
{
	int	res;

	if (!ft_strncmp(str, "NO ", 3))
		res = m_param(str, &map->vars.path_no, map);
	else if (!ft_strncmp(str, "SO ", 3))
		res = m_param(str, &map->vars.path_so, map);
	else if (!ft_strncmp(str, "WE ", 3))
		res = m_param(str, &map->vars.path_we, map);
	else if (!ft_strncmp(str, "EA ", 3))
		res = m_param(str, &map->vars.path_ea, map);
	else if (!ft_strncmp(str, "F ", 2))
		res = m_fc_param(str, 'f', &map->vars);
	else if (!ft_strncmp(str, "C ", 2))
		res = m_fc_param(str, 'c', &map->vars);
	else if (!str[0])
		return (0);
	else
		return (1);
	if (res)
		return (-1);
	return (0);
}
