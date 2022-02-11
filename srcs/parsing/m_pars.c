#include "../../hdrs/cub3d.h"

int	m_close_fd(int fd)
{
	close(fd);
	return (1);
}

static int	m_read_gnl(int fd)
{
	char	*str;
	int		status;

	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		status = m_pars_param(str);
		if (status < 0)
			return (m_close_fd(fd));
		else if (status)
			return (m_pars_map(str, fd));
		free(str);
	}
	m_close_fd(fd);
	return (0);
}

static int	m_check_param(char ***map)
{
	if (!path_no || !path_so || !path_we || !path_ea || \
		!**map || f[0] < 0 || cel[0] < 0)
		return (1);
	return (0);
}

static void	m_init_param(char ***map)
{
	path_no = NULL;
	path_so = NULL;
	path_we = NULL;
	path_ea = NULL;
	*map = NULL;
	f[0] = -1;
	cel[0] = -1;
}

int	m_pars(char **av, char ***map)
{
	int		fd;

	lst_map = NULL;
	m_init_param(map);
	if (m_check_fname(av[1]))
		return (EXIT_FAILURE);
	fd = open(av[1], O_RDONLY, 0644);
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (m_perror_r("Fd"));
	if (m_read_gnl(fd))
		return (EXIT_FAILURE);
	*map = ft_map_create(lst_map);
	ft_lstclear(&lst_map);
	if (!*map)
		return (EXIT_FAILURE);
	return (m_check_param(map));
}
