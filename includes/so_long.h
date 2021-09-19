#ifndef SO_LONG_H
# define SO_LONG_H
# define TRUE 1
# define FALSE 0

# include "../libft/includes/libft.h"
# include <fcntl.h>

typedef struct s_map
{
	int			w;
	int			h;
	int			**map
}				t_map;

int	check_map(char *map);

#endif
