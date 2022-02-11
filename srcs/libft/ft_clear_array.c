#include "../../hdrs/cub3d.h"

int	ft_clear_arrray(char **array)
{
	int	i;

	if (array)
	{
		i = -1;
		while (array[++i])
			free(array[i]);
		free(array);
	}
	return (1);
}
