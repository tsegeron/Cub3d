/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

int	m_close_fd(int fd)
{
	close(fd);
	return (1);
}

static int	m_read_gnl(int fd, t_list **lst_map, t_map *map)
{
	char	*str;
	int		status;

	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		status = m_pars_param(str, map);
		if (status < 0)
			return (m_close_fd(fd));
		else if (status)
			return (m_pars_map(str, fd, lst_map));
		free(str);
	}
	return (m_close_fd(fd) * 0);
}

static void	m_init_param(t_vars *vars)
{
	vars->path_no.img = NULL;
	vars->path_so.img = NULL;
	vars->path_we.img = NULL;
	vars->path_ea.img = NULL;
	vars->door.img = NULL;
	vars->enemy.img = NULL;
	vars->cure.img = NULL;
	vars->charge.img = NULL;
	vars->wand.img = NULL;
	vars->ceil_clr = -1;
	vars->floor_clr = -1;
}

int	m_pars(char **av, t_map *map)
{
	t_list	*lst_map;
	int		fd;

	lst_map = NULL;
	map->map = NULL;
	map->mlx.mlx = mlx_init();
	if (!map->mlx.mlx)
		return (EXIT_FAILURE);
	m_init_param(&map->vars);
	if (m_check_fname(av[1]))
		return (EXIT_FAILURE);
	fd = open(av[1], O_RDONLY, 0644);
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (m_perror_r("Fd") && m_close_fd(fd));
	if (m_read_gnl(fd, &lst_map, map))
		return (EXIT_FAILURE);
	(map->map) = m_map_create(lst_map, map);
	m_lstclear(&lst_map);
	if (!(map->map))
		return (EXIT_FAILURE);
	m_close_fd(fd);
	if (m_init_imgs(&map->vars, map->mlx.mlx))
		return (EXIT_FAILURE);
	return (m_check_param(&map->vars, map->map) || m_check_map(map));
}
