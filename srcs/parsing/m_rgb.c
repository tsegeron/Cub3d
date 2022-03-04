/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_rgb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:34:59 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/08 22:14:55 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

//int	m_rgb_to_16(int *array, char **result)
//{
//	int	i;
//
//	i = -1;
//	*result = NULL;
//	while (++i < 3)
//	{
//		*result = ft_strjoin(*result, ft_itoa_hex(array[i]));
//		if (!*result)
//			return (EXIT_FAILURE);
//	}
//	return (EXIT_SUCCESS);
//}

void	m_rgb_to_dec(int *array, int *num)
{
	*num = array[0] * 65536 + array[1] * 256 + array[2];
}
