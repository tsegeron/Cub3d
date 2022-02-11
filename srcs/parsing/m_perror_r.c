#include "../../hdrs/cub3d.h"

int	m_perror_r(char *str)
{
	perror(str);
	return (1);
}

int	m_error(char *str)
{
	printf("%s\n", str);
	return (1);
}
