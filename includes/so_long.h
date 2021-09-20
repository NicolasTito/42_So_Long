/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 03:13:41 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/20 10:05:40 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TRUE 1
# define FALSE 0

# include "../libft/includes/libft.h"
# include "info_map.h"
# include "struct_sl.h"
# include <fcntl.h>

int		check_map(char *file_name, t_map **map, char **temp);
void	init_map(t_map **map);
char	**start_map(int fd, t_map **map);
void	exit_program(t_info *s_i, char **temp);
void	free_temp(t_map **map, char **temp);
void	organize_map(t_map **map, char **temp);
void	exit_error(void);
void	free_temp(t_map **map, char **temp);
void	init_wall(t_wall *s_w, int h, int w);
void	populate_wall_corner(t_map **map, char **temp);
void	populate_center_map(t_map **map, char **temp, t_wall *s_w);

#endif
