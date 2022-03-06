/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_check_param.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

int	m_check_param(t_vars *vars, char **map)
{
	if (vars->floor_clr < 0 || vars->ceil_clr < 0 || !map || \
			vars->floor_clr == vars->ceil_clr)
		return (1);
	return (0);
}
