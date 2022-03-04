/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:34:59 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/08 22:14:55 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

static void	m_clear_itf(t_interface *path)
{
	if (path->addr)
		free(path->addr);
	if (path->img)
		free(path->img);
}

int	close_win(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
		free(map->map[i]);
	free(map->map);
	m_clear_itf(&map->vars.path_no);
	m_clear_itf(&map->vars.path_so);
	m_clear_itf(&map->vars.path_we);
	m_clear_itf(&map->vars.path_ea);
	m_clear_itf(&map->back);
	if (map->mlx.mlx)
		free(map->mlx.mlx);
	if (map->mlx.win)
		free(map->mlx.win);
	exit(EXIT_SUCCESS);
}

int	press_key(int keycode, t_map *map)
{
	if (keycode == 53)
		close_win(map);
	if (keycode == 13)
		map->key.w = 1;
	if (keycode == 0)
		map->key.a = 1;
	if (keycode == 1)
		map->key.s = 1;
	if (keycode == 2)
		map->key.d = 1;
	if (keycode == 123)
		map->key.left = 1;
	if (keycode == 124)
		map->key.right = 1;
	return (0);
}

int	release_key(int keycode, t_keys *key)
{
	if (keycode == 13)
		key->w = 0;
	if (keycode == 0)
		key->a = 0;
	if (keycode == 1)
		key->s = 0;
	if (keycode == 2)
		key->d = 0;
	if (keycode == 123)
		key->left = 0;
	if (keycode == 124)
		key->right = 0;
	return (0);
}
