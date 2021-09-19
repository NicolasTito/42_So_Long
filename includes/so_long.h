#ifndef SO_LONG_H
# define SO_LONG_H
# define TRUE 1
# define FALSE 0

# include "../libft/includes/libft.h"
# include <fcntl.h>

typedef struct s_info_map
{
	int	c;
	int	exit;
	int	p;
	int	en;
}				t_info_map;
typedef struct s_map
{
	int			w;
	int			h;
	char		**map;
	t_info_map	info;
}				t_map;

typedef struct s_info
{
	t_map		*map;
}				t_info;

int		check_map(char *file_name, t_map **map);
void	init_map(t_map **map);
void	start_map(int fd, t_map **map);
void	exit_program(t_info *s_i);

#endif
