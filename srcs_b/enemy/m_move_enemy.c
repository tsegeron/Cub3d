/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_move_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

void	m_move_lite(t_vilian *vil, char **map)
{
	int		posx;
	int		posy;
	double	difx;
	double	dify;
	int		status;

	difx = (MOVE_SPEED) * cos(vil->dir);
	dify = -(MOVE_SPEED) * sin(vil->dir);
	posx = (int)(vil->x + difx + MOVE_SPEED * difx / fabs(difx));
	posy = (int)(vil->y + dify + MOVE_SPEED * dify / fabs(dify));
	status = 0;
	if (map[(int)vil->y][posx] != '1'
		&& map[(int)vil->y][posx] != 'C' && (difx >= 0.05 || difx <= -0.05))
	{
		vil->x += difx;
		status = 1;
	}
	if (map[posy][(int)vil->x] != '1'
		&& map[posy][(int)vil->x] != 'C' && (dify >= 0.05 || dify <= -0.05))
	{
		vil->y += dify;
		status = 1;
	}
	if (!status)
		m_change_vil_dir(vil);
}

void	m_move_angry(t_vilian *vil, t_map *map)
{
	int		posx;
	int		posy;
	double	difx;
	double	dify;

	difx = (MOVE_SPEED) * cos(vil->dir);
	dify = -(MOVE_SPEED) * sin(vil->dir);
	posx = (int)(vil->x + difx + MOVE_SPEED * difx / fabs(difx));
	posy = (int)(vil->y + dify + MOVE_SPEED * dify / fabs(dify));
	if (map->map[posy][posx] != '1' && \
		map->map[posy][posx] != 'C')
	{
		vil->y += dify;
		vil->x += difx;
	}
}
