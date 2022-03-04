/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:34:59 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/08 22:14:55 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

int	m_perror_r(char *str)
{
	perror(str);
	return (1);
}

int	m_error(char *str)
{
	printf("%s\n", str);
	return (1);
}
