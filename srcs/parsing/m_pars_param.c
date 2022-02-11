#include "../../hdrs/cub3d.h"

static int	m_param(char *str, char **path)
{
	if (*path)
		free(*path);
	*path = ft_strdup(str + 3);
	if (!*path)
		return (m_perror_r("Malloc"));
	return (0);
}

static int	m_fc_param(char *str, char chr)
{
	char	**str_split;
	int		i;
	int		status;

	status = 0;
	str_split = ft_split(str + 2, ',');
	if (!str_split)
		return (m_perror_r("Malloc"));
	if (ft_len_array(str_split) > 3 || ft_strchr_count(str, ',') != 2)
		return (m_perror_r("Wrong argumenst for f / c\n"));
	i = -1;
	while (str_split[++i])
	{
		if (chr == 'f')
			f[i] = ft_atoi(str_split[i], &status);
		else
			cel[i] = ft_atoi(str_split[i], &status);
		if (status < 0)
			return (ft_clear_arrray(str_split));
	}
	ft_clear_arrray(str_split);
	return (0);
}

int	m_pars_param(char *str)
{
	int	res;

	if (!ft_strncmp(str, "NO ", 3))
		res = m_param(str, &path_no);
	else if (!ft_strncmp(str, "SO ", 3))
		res = m_param(str, &path_so);
	else if (!ft_strncmp(str, "WE ", 3))
		res = m_param(str, &path_we);
	else if (!ft_strncmp(str, "EA ", 3))
		res = m_param(str, &path_ea);
	else if (!ft_strncmp(str, "F ", 2))
		res = m_fc_param(str, 'f');
	else if (!ft_strncmp(str, "C ", 2))
		res = m_fc_param(str, 'c');
	else if (!str[0])
		return (0);
	else
		return (1);
	if (res)
		return (-1);
	return (0);
}
