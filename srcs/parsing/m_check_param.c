/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_check_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:34:59 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/08 22:14:55 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

int	m_check_param(t_vars *vars, char **map)
{
	if (vars->floor_clr < 0 || vars->ceil_clr < 0 || !map || \
			vars->floor_clr == vars->ceil_clr)
		return (1);
	return (0);
}
