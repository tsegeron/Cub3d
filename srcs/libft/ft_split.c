/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:00:10 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 19:55:37 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

static int	ft_counter_words(const char *str, char c)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	while (str[index])
	{
		while (str[index] == c)
			index++;
		if (str[index] != c && str[index] != '\0')
			count++;
		while (str[index] != c && str[index] != '\0')
			index++;
	}
	return (count);
}

static int	ft_len_str(const char *str, int index, char c)
{
	int	len;

	len = 0;
	while (str[index] == c)
		index++;
	while (str[index] != c && str[index++] != '\0')
		len++;
	return (len);
}

static char	**ft_mem_str(int counter_words, const char *str, char c)
{
	char	**ptr;
	char	*string;
	int		index_char;
	int		index_str;
	int		len;

	index_char = 0;
	index_str = 0;
	ptr = (char **)malloc(sizeof(char *) * (counter_words + 1));
	if (!ptr)
		return (NULL);
	ptr[counter_words] = NULL;
	if (counter_words == 0)
		return (ptr);
	while (index_str < counter_words)
	{
		while (str[index_char] == c)
			index_char++;
		len = ft_len_str(str, index_char, c);
		string = ft_substr(str, index_char, len);
		ptr[index_str++] = ft_strdup(string);
		free(string);
		index_char += len;
	}
	return (ptr);
}

static	char	**ft_free_ptr(int counter_words, char **ptr)
{
	int	count;

	count = 0;
	while (count < counter_words - 1)
		free(ptr[count++]);
	free(ptr);
	return (NULL);
}

char	**ft_split(const char *str, char c)
{
	char	**ptr;
	int		counter_words;
	int		count;

	if (!str)
		return (NULL);
	count = 0;
	counter_words = ft_counter_words(str, c);
	ptr = ft_mem_str(counter_words, str, c);
	if (!ptr)
		return (NULL);
	while (count < counter_words - 1)
	{
		if (ptr[count] == NULL)
			break ;
		count++;
	}
	if (count < counter_words - 1)
		return (ft_free_ptr(counter_words, ptr));
	return (ptr);
}
