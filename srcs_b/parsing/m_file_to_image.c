#include "../../hdrs/cub3d_bonus.h"

int	m_file_to_image(char *util, t_map *map, void **path)
{
	int	width;
	int	height;

	if (!ft_strcmp(util + ft_strlen(util) - 4, ".xpm"))
	{
		*path = mlx_xpm_file_to_image(map->mlx.mlx, util, &width, &height);
		if (!*path)
			return (m_free_util(util) && m_error("Wrong path"));
	}
//	else if (!ft_strcmp(util + ft_strlen(util) - 4, ".png"))
//	{
//		*path = mlx_png_file_to_image(map->mlx.mlx, util, &width, &height);
//		if (!*path)
//			return (m_free_util(util) && m_error("Wrong path"));
//	}
	return (0);
}
