/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:17:08 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/22 18:34:02 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

static int	ft_get_intlen(unsigned int num)
{
	int	i;

	i = 1;
	while (num / 10 != 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

static char	*get_str(unsigned int num, int end)
{
	char	*res;
	int		i;

	i = end;
	res = (char *) malloc((end + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (end-- != 0)
	{
		res[end] = num % 10 + 48;
		num /= 10;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_itoa_uns(unsigned int n)
{
	char	*res;

	res = get_str(n, ft_get_intlen(n));
	return (res);
}
