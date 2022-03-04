/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:34:59 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/08 22:14:55 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

static void	ft_skip(int *index, const char *str)
{
	while (str[*index] == ' ' || str[*index] == '\t' || \
	str[*index] == '\v' || str[*index] == '\f' || \
	str[*index] == '\r' || str[*index] == '\n')
		*index += 1;
}

static int	ft_check_sign(const char *str, int *index, int *i)
{
	if (str[*index] == '+')
		*index += 1;
	else if (str[*index] == '-')
	{
		if (str[*index + 1] < '0' || str[*index + 1] > '9')
			*i = -1;
		return (1);
	}
	else if (!str[*index])
		*i = -1;
	return (0);
}

int	m_atoi(const char *str, int *i)
{
	int					index;
	int					sign;
	unsigned long long	num;

	*i = 0;
	sign = 1;
	num = 0;
	index = 0;
	ft_skip(&index, str);
	if (ft_check_sign(str, &index, i))
		return (0);
	while (str[index] >= '0' && str[index] <= '9')
	{
		num = num * 10 + (str[index] - '0');
		index++;
	}
	if ((str[index] < '0' || str[index] > '9') && str[index])
		*i = -1;
	if ((num > 2147483647 && sign > 0) || (num > 2147483648 && sign < 0))
		*i = -1;
	if (num > 255)
		return (255);
	return ((int)num * sign);
}
