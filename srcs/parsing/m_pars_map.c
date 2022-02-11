#include "../../hdrs/cub3d.h"

int	m_pars_map(char *str, int fd)
{
	while (1)
	{
		if (ft_lstadd_back(&lst_map, str))
		{
			ft_lstclear(&lst_map);
			free(str);
			return (m_close_fd(fd));
		}
		str = get_next_line(fd);
		if (!str)
			break ;
	}
	close(fd);
	return (0);
}
