#include "../../hdrs/cub3d_bonus.h"

int	m_clear_vilian_lst(t_vilian **vil)
{
	t_vilian	*tmp;

	while (vil && *vil)
	{
		tmp = (*vil)->next;
		free(*vil);
		*vil = tmp;
	}
	return (1);
}

static t_vilian	*m_new_vilian(int y, int x, int num_vil)
{
	t_vilian	*elem;
	int			util;

	elem = malloc(sizeof (t_vilian));
	if (!elem)
		return (NULL);
	elem->num_vil = num_vil;
	elem->x = (double)x + 0.5;
	elem->y = (double)y + 0.5;
	elem->status_action = 0;
	elem->health = 1;
	elem->next = NULL;
	util = rand() % 4;
	if (util == 0)
		elem->dir = 3.14 / 2 + GR;
	else if (util == 1)
		elem->dir = 3 * 3.14 / 2 + GR;
	else if (util == 2)
		elem->dir = 3.14 + GR;
	else
		elem->dir = GR;
	return (elem);
}

int	m_addback_vilian(t_vilian **vil, int y, int x)
{
	t_vilian	*vil_step;
	static int	num_vil = 1;

	if (!*vil)
	{
		*vil = m_new_vilian(y, x, num_vil);
		if (!*vil)
			return (m_clear_vilian_lst(vil));
	}
	else
	{
		vil_step = *vil;
		while (vil_step->next)
			vil_step = vil_step->next;
		vil_step->next = m_new_vilian(y, x, num_vil);
		if (!vil_step->next)
			return (m_clear_vilian_lst(vil));
	}
	num_vil++;
	return (0);
}
