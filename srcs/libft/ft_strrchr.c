/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseastar <mseastar@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:03:17 by mseastar          #+#    #+#             */
/*   Updated: 2021/10/11 11:44:37 by mseastar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

char	*ft_strrchr(char *str, char c)
{
	char	*s;

	s = NULL;
	while (*str)
	{
		if (*str == c)
			s = str;
		str++;
	}
	if (*str == c)
		s = str;
	return (s);
}
