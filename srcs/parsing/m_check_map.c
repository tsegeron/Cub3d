#include "../../hdrs/cub3d.h"

int	m_check_map(char **map)
{
	int i;
	int j;
	int count_resp;
	int count_space;

	count_resp = 0;
	count_space = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (i == 0 || j == 0 || i == ft_len_array(map) - 1 || j == ft_strlen(map[i]) - 1)
					return (m_error("Error"));
				if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
					return (m_error("Error"));
				count_space++;
			}
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
				count_resp++;

		}
	}
	if (count_resp != 1 || !count_space)
		return (m_error("Error"));
	return (0);
}