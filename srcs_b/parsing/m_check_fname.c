/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_check_fname.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

int	m_check_fname(char *str)
{
	int		i;
	char	*str_end;
	char	*str_correct;

	str_correct = ".cub";
	i = 3;
	str_end = str + ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (*str_end != str_correct[i])
			return (printf("Error filename format\n"));
		str_end--;
		i--;
	}
	return (0);
}
