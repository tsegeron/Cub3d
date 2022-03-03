#include "../../hdrs/cub3d_bonus.h"

static int	m_hero_pos(t_map *map, int i, int j, int *count_resp)
{
	map->pers.posx = j + 0.5;
	map->pers.posy = i + 0.5;
	map->pers.charge = 3;
	map->pers.health = 3;
	if (map->map[i][j] == 'N')
		map->pers.dir = 3.14 / 2 + GR;
	else if (map->map[i][j] == 'S')
		map->pers.dir = 3 * 3.14 / 2 + GR;
	else if (map->map[i][j] == 'W')
		map->pers.dir = 3.14 + GR;
	else if (map->map[i][j] == 'E')
		map->pers.dir = 3.14 * 2 + GR;
	if (*count_resp)
		return (EXIT_FAILURE);
	(*count_resp)++;
	return (EXIT_SUCCESS);
}

static int	m_check_char(t_map *map, int i, int j, int *count_space)
{
	if (map->map[i][j] != 'N' && map->map[i][j] != 'S' && \
		map->map[i][j] != 'W' && map->map[i][j] != 'E' && \
			map->map[i][j] != '0' && map->map[i][j] != 'C' && \
				map->map[i][j] != 'O' && map->map[i][j] != 'V' && \
					map->map[i][j] != 'B')
		return (m_error("Error"));
	if (i == 0 || j == 0 || i == ft_len_array(map->map) - 1 || \
		j == ft_strlen(map->map[i]) - 1)
		return (m_error("Error"));
	if (map->map[i][j - 1] == ' ' || map->map[i][j + 1] == ' ' || \
		ft_strlen(map->map[i - 1]) - 1 < j || map->map[i - 1][j] == ' ' || \
			ft_strlen(map->map[i + 1]) - 1 < j || map->map[i + 1][j] == ' ')
		return (m_error("Error"));
	if (map->map[i][j] == 'V')
	{
		if (m_addback_vilian(&map->vilian, i, j))
			return (m_error("Error"));
		map->map[i][j] = '0';
	}
	(*count_space)++;
	return (0);
}

static int	m_close_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((i == 0 && map[i][j] != '1') || (i == ft_len_array(map) - 1 \
				&& map[i][j] != '1') || (j == 0 && map[i][j] != '1') || \
					(j == ft_strlen(map[i]) - 1 && map[i][j] != '1'))
				map[i][j] = '#';
		}
	}
	return (EXIT_SUCCESS);
}

int	m_check_map(t_map *map)
{
	int	i;
	int	j;
	int	count_space;
	int	count_resp;

	count_space = 0;
	count_resp = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] != '1' && map->map[i][j] != ' ')
				if (m_check_char(map, i, j, &count_space))
					return (EXIT_FAILURE);
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' || \
				map->map[i][j] == 'W' || map->map[i][j] == 'E')
				if (m_hero_pos(map, i, j, &count_resp))
					return (EXIT_FAILURE);
		}
	}
	if (count_resp != 1 || !count_space)
		return (m_error("Error"));
	return (m_close_map(map->map));
}
