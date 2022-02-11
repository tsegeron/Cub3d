/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:09:13 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 19:16:27 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

char	*ft_strdup(const char *str)
{
	char	*str_in;
	char	*str_r;

	if (!str)
		return (NULL);
	str_in = (char *) str;
	str_r = (char *) malloc(ft_strlen(str_in) + 1);
	if (!str_r)
		return (NULL);
	ft_strcpy(str_r, str);
	return (str_r);
}
