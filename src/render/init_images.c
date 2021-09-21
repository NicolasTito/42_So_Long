/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:08:27 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/21 21:57:01 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	xmp_to_image(t_info *s_i, t_img *img, char *path)
{
	img->addr = mlx_xpm_file_to_image(s_i->mlx, path, &img->wid, &img->heig);
	if (!img->addr)
	{
		free_matrix(s_i->map, s_i->map->map);
		exit_error();
	}
}

static void	init_images_char(t_info *s_i)
{
	xmp_to_image(s_i, &s_i->player.front[0], CHAR_FRONT1);
	xmp_to_image(s_i, &s_i->player.front[1], CHAR_FRONT2);
	xmp_to_image(s_i, &s_i->player.back[0], CHAR_BACK1);
	xmp_to_image(s_i, &s_i->player.back[1], CHAR_BACK2);
	xmp_to_image(s_i, &s_i->player.left[0], CHAR_LEFT1);
	xmp_to_image(s_i, &s_i->player.left[1], CHAR_LEFT2);
	xmp_to_image(s_i, &s_i->player.right[0], CHAR_RIGHT1);
	xmp_to_image(s_i, &s_i->player.right[1], CHAR_RIGHT2);
}

static void	init_images_enemy(t_info *s_i)
{
	xmp_to_image(s_i, &s_i->enemy.e_left[0], ENEMY_LEFT_1);
	xmp_to_image(s_i, &s_i->enemy.e_left[1], ENEMY_LEFT_2);
	xmp_to_image(s_i, &s_i->enemy.e_left[2], ENEMY_LEFT_3);
	xmp_to_image(s_i, &s_i->enemy.e_left[3], ENEMY_LEFT_4);
	xmp_to_image(s_i, &s_i->enemy.e_right[0], ENEMY_RIGHT_1);
	xmp_to_image(s_i, &s_i->enemy.e_right[1], ENEMY_RIGHT_2);
	xmp_to_image(s_i, &s_i->enemy.e_right[2], ENEMY_RIGHT_3);
	xmp_to_image(s_i, &s_i->enemy.e_right[3], ENEMY_RIGHT_4);
}

static void	init_images_torch(t_info*s_i)
{
	xmp_to_image(s_i, &s_i->t_bot[0], WTB1);
	xmp_to_image(s_i, &s_i->t_bot[1], WTB2);
	xmp_to_image(s_i, &s_i->t_bot[2], WTB3);
	xmp_to_image(s_i, &s_i->t_top[0], WTT1);
	xmp_to_image(s_i, &s_i->t_top[1], WTT2);
	xmp_to_image(s_i, &s_i->t_top[2], WTT3);
	xmp_to_image(s_i, &s_i->t_left[0], WTL1);
	xmp_to_image(s_i, &s_i->t_left[1], WTL2);
	xmp_to_image(s_i, &s_i->t_left[2], WTL3);
	xmp_to_image(s_i, &s_i->t_right[0], WTR1);
	xmp_to_image(s_i, &s_i->t_right[1], WTR2);
	xmp_to_image(s_i, &s_i->t_right[2], WTR3);
}

void	init_images(t_info *s_i)
{
	init_images_char(s_i);
	init_images_enemy(s_i);
	init_images_torch(s_i);
	xmp_to_image(s_i, &s_i->floor, IMG_FLOOR);
	xmp_to_image(s_i, &s_i->hole, IMG_HOLE);
	xmp_to_image(s_i, &s_i->door, IMG_DOOR);
	xmp_to_image(s_i, &s_i->exit, IMG_EXIT);
	xmp_to_image(s_i, &s_i->collect, IMG_COLLECT);
	xmp_to_image(s_i, &s_i->wall_top, WALL_TOP);
	xmp_to_image(s_i, &s_i->wall_bot, WALL_BOT);
	xmp_to_image(s_i, &s_i->wall_right, WALL_RIGHT);
	xmp_to_image(s_i, &s_i->wall_left, WALL_LEFT);
	xmp_to_image(s_i, &s_i->wc_lt, WALL_C1);
	xmp_to_image(s_i, &s_i->wc_rt, WALL_C2);
	xmp_to_image(s_i, &s_i->wc_rb, WALL_C3);
	xmp_to_image(s_i, &s_i->wc_lt, WALL_C4);
}
