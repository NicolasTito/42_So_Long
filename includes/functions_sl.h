/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_sl.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:27:25 by nide-mel          #+#    #+#             */
/*   Updated: 2021/10/26 16:17:15 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_SL_H
# define FUNCTIONS_SL_H

# include "so_long.h"
# include "struct_sl.h"

int		check_map(char *file_name, t_map **map, char **temp);
void	init_map(t_map **map);
void	init_info(t_info *s_i);
void	init_images(t_info *s_i);
void	init_player(t_player *player, int x, int y);
void	exit_program(t_info *s_i, char **temp);
void	exit_error(void);
void	exit_game(t_info *s_i);
void	free_matrix(t_map **map, char **temp);
void	free_map(t_map **map);
char	**start_map(int fd, t_map **map);
void	organize_map(t_map **map, char **temp);
void	init_wall(t_wall *s_w, int h, int w);
void	populate_wall_corner(t_map **map, char **temp);
void	populate_center_map(t_map **map, char **temp, t_wall *s_w);
void	put_img(t_info *s_i, t_img *img, int x, int y);
void	render_img(t_info *s_i);
void	char_side(int key, t_info *s_i);
int		game_moves(int key, t_info *s_i);
int		destroy_window(t_info *s_i);
void	destroy_image(t_info *s_i);
int		game_render(t_info *s_i);
void	render_pers(t_info *s_i, int x, int y);
void	render_enemy(t_info *s_i, int x, int y);
void	verify_enemy(int key, t_info *s_i);
void	dead_msg(t_info *s_i);

#endif
