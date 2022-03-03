#include "../../hdrs/cub3d_bonus.h"

int	m_check_param(t_vars *vars, char **map)
{
	if (vars->flor_long < 0 || vars->cel_long < 0 || !map || \
			vars->flor_long == vars->cel_long)
		return (1);
	return (0);
}
