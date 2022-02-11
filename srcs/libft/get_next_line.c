/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseastar <mseastar@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:34:53 by mseastar          #+#    #+#             */
/*   Updated: 2022/02/09 11:40:16 by mseastar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

char	*ft_put_in_str_r(const char *str, int *i)
{
	char	*str_r;

	if (!str[*i])
		return (NULL);
	while (str[*i] && str[*i] != '\n')
		(*i)++;
	str_r = (char *)malloc(sizeof(char) * (*i) + 2);
	if (!str_r)
		return (NULL);
	*i = 0;
	while (str[*i] && str[*i] != '\n')
	{
		str_r[*i] = str[*i];
		(*i)++;
	}
	str_r[(*i)] = '\0';
	if (str[*i] == '\n')
		*i += 1;
	return (str_r);
}

char	*ft_put_in_buf(int fd, char *str)
{
	char	*buffer;
	int		check_b;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	check_b = 1;
	while (check_b != 0 && !ft_strchr(str, '\n'))
	{
		check_b = read(fd, buffer, BUFFER_SIZE);
		if (check_b < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[check_b] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_substr_gnl(char *str, int i)
{
	char	*str_new;
	int		j;

	if (!str)
		return (NULL);
	j = 0;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	str_new = (char *) malloc(ft_strlen(&str[i]) + 1);
	while (str[i])
		str_new[j++] = str[i++];
	str_new[j] = '\0';
	free(str);
	return (str_new);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*str_r;
	int			i;

	if (fd < 0)
		return (NULL);
	str = ft_put_in_buf(fd, str);
	if (!str)
		return (NULL);
	i = 0;
	str_r = ft_put_in_str_r(str, &i);
	str = ft_substr_gnl(str, i);
	return (str_r);
}
