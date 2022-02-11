/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:32:13 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/08 15:04:36 by mseastar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

size_t	ft_strchr_count(const char *str, char chr)
{
	size_t	i;
	size_t	count;

	count = 0;
	if (str)
	{
		i = -1;
		while (str[++i])
			if (str[i] == chr)
				count++;
	}
	return (count);
}
