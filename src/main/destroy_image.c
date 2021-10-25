/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:01:44 by nide-mel          #+#    #+#             */
/*   Updated: 2021/10/25 23:27:04 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destoy_image_4(t_info *s_i)
{
	mlx_destroy_image(s_i->mlx, s_i->floor.img);
	mlx_destroy_image(s_i->mlx, s_i->hole.img);
	mlx_destroy_image(s_i->mlx, s_i->door.img);
	mlx_destroy_image(s_i->mlx, s_i->exit.img);
	mlx_destroy_image(s_i->mlx, s_i->collect.img);
	mlx_destroy_image(s_i->mlx, s_i->wall_bot.img);
	mlx_destroy_image(s_i->mlx, s_i->wall_top.img);
	mlx_destroy_image(s_i->mlx, s_i->wall_right.img);
	mlx_destroy_image(s_i->mlx, s_i->wall_left.img);
	mlx_destroy_image(s_i->mlx, s_i->wc_lb.img);
	mlx_destroy_image(s_i->mlx, s_i->wc_lt.img);
	mlx_destroy_image(s_i->mlx, s_i->wc_rt.img);
	mlx_destroy_image(s_i->mlx, s_i->wc_rb.img);
	mlx_destroy_window(s_i->mlx, s_i->win);
}

static void	destroy_image_3(t_info *s_i)
{
	mlx_destroy_image(s_i->mlx, s_i->t_bot[0].img);
	mlx_destroy_image(s_i->mlx, s_i->t_bot[1].img);
	mlx_destroy_image(s_i->mlx, s_i->t_bot[2].img);
	mlx_destroy_image(s_i->mlx, s_i->t_top[0].img);
	mlx_destroy_image(s_i->mlx, s_i->t_top[1].img);
	mlx_destroy_image(s_i->mlx, s_i->t_top[2].img);
	mlx_destroy_image(s_i->mlx, s_i->t_left[0].img);
	mlx_destroy_image(s_i->mlx, s_i->t_left[1].img);
	mlx_destroy_image(s_i->mlx, s_i->t_left[2].img);
	mlx_destroy_image(s_i->mlx, s_i->t_right[0].img);
	mlx_destroy_image(s_i->mlx, s_i->t_right[1].img);
	mlx_destroy_image(s_i->mlx, s_i->t_right[2].img);
	destoy_image_4(s_i);
}

static void	destroy_image_2(t_info *s_i)
{
	mlx_destroy_image(s_i->mlx, s_i->enemy.e_left[0].img);
	mlx_destroy_image(s_i->mlx, s_i->enemy.e_left[1].img);
	mlx_destroy_image(s_i->mlx, s_i->enemy.e_left[2].img);
	mlx_destroy_image(s_i->mlx, s_i->enemy.e_left[3].img);
	mlx_destroy_image(s_i->mlx, s_i->enemy.e_right[0].img);
	mlx_destroy_image(s_i->mlx, s_i->enemy.e_right[1].img);
	mlx_destroy_image(s_i->mlx, s_i->enemy.e_right[2].img);
	mlx_destroy_image(s_i->mlx, s_i->enemy.e_right[3].img);
	destroy_image_3(s_i);
}

void	destroy_image(t_info *s_i)
{
	mlx_destroy_image(s_i->mlx, s_i->player.back[0].img);
	mlx_destroy_image(s_i->mlx, s_i->player.back[1].img);
	mlx_destroy_image(s_i->mlx, s_i->player.front[0].img);
	mlx_destroy_image(s_i->mlx, s_i->player.front[1].img);
	mlx_destroy_image(s_i->mlx, s_i->player.right[0].img);
	mlx_destroy_image(s_i->mlx, s_i->player.right[1].img);
	mlx_destroy_image(s_i->mlx, s_i->player.left[0].img);
	mlx_destroy_image(s_i->mlx, s_i->player.left[1].img);
	destroy_image_2(s_i);
}