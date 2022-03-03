/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:12:09 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/22 18:34:02 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

static int	ft_check_start(const char *str, char const *set)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (i);
}

static int	ft_check_end(const char *str, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (str[i + 1] != '\0')
		i++;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;
	int		i;

	i = 0;
	if (s1)
	{
		start = ft_check_start(s1, set);
		end = ft_check_end(s1, set);
		if (end < 0)
			start = 1;
		trimmed = (char *) malloc ((end - start + 1) * sizeof(char) + 1);
		if (!trimmed)
			return (NULL);
		while (start <= end)
			trimmed[i++] = s1[start++];
		trimmed[i] = '\0';
		return (trimmed);
	}
	return (NULL);
}
