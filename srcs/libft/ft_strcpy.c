/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:09:07 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 19:16:27 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

size_t	ft_strcpy(char *str_out, const char *str_in)
{
	char	*str1;
	size_t	i;
	size_t	j;

	str1 = (char *)str_in;
	j = ft_strlen(str1);
	i = -1;
	while (str_in[++i])
		str_out[i] = str_in[i];
	str_out[i] = '\0';
	return (j);
}
