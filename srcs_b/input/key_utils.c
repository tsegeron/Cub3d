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

#include "../../hdrs/cub3d_bonus.h"

int check_ps(char **map)
{
	int y;
	int x;
	int count;

	count = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'P')
				count++;
	}
	if (!count)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	close_win(t_map *map)
{
	ft_clear_arrray(map->map);
	m_clear_vilian_lst(&map->vilian);
	exit(EXIT_SUCCESS);
}

int	press_key(int keycode, t_map *map)
{
	if (keycode == 53)
		close_win(map);
	if (keycode == 12)
	{
		if (map->screen_stat == NOSCREEN)
			map->screen_stat = MENU;
		else if (map->screen_stat == MENU)
			map->screen_stat = NOSCREEN;
	}
	if (keycode == 14 && map->screen_stat == NOSCREEN)
		do_open_door(map);
	if (keycode == 13 && map->screen_stat == NOSCREEN)
		map->key.w = true;
	if (keycode == 0 && map->screen_stat == NOSCREEN)
		map->key.a = true;
	if (keycode == 1 && map->screen_stat == NOSCREEN)
		map->key.s = true;
	if (keycode == 2 && map->screen_stat == NOSCREEN)
		map->key.d = true;
	if (keycode == 123 && map->screen_stat == NOSCREEN)
		map->key.left = true;
	if (keycode == 124 && map->screen_stat == NOSCREEN)
		map->key.right = true;
	return (0);
}

int	release_key(int keycode, t_keys *key)
{
	if (keycode == 13)
		key->w = false;
	if (keycode == 0)
		key->a = false;
	if (keycode == 1)
		key->s = false;
	if (keycode == 2)
		key->d = false;
	if (keycode == 123)
		key->left = false;
	if (keycode == 124)
		key->right = false;
	return (0);
}
