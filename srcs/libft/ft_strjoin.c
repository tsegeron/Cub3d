/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:12:34 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/26 05:05:50 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joint;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *) malloc (1);
		s1[0] = '\0';
	}
	joint = (char *) malloc ((ft_strlen(s1)
				+ ft_strlen(s2) + 1) * sizeof(char));
	if (!joint)
		return (NULL);
	while (s1[++i] != '\0')
		joint[i] = s1[i];
	while (s2[j] != '\0')
		joint[i++] = s2[j++];
	joint[i] = '\0';
	free (s1);
	return (joint);
}
