#include "../../hdrs/cub3d.h"

int	m_check_fname(char *str)
{
	int		i;
	char	*str_end;
	char	*str_correct;

	str_correct = ".cub";
	i = 3;
	str_end = str + ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (*str_end != str_correct[i])
			return (printf("Error filename format\n"));
		str_end--;
		i--;
	}
	return (0);
}
