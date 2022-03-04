#include "../../hdrs/cub3d_bonus.h"

int	m_check_param(t_vars *vars, char **map)
{
	if (vars->floor_clr < 0 || vars->ceil_clr < 0 || !map || \
			vars->floor_clr == vars->ceil_clr)
		return (1);
	return (0);
}
