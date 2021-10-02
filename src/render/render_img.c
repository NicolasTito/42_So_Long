/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:16:25 by nide-mel          #+#    #+#             */
/*   Updated: 2021/10/02 10:10:25 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_info *s_i, t_img *img, int x, int y)
{
	mlx_put_image_to_window(s_i->mlx, s_i->win, img->img, x * IMG_H, y * IMG_W);
}

static void	render_wall(t_info *s_i, int x, int y)
{
	if (s_i->map->map[y][x] == WT)
		put_img(s_i, &s_i->wall_top, x, y);
	else if (s_i->map->map[y][x] == WB)
		put_img(s_i, &s_i->wall_bot, x, y);
	else if (s_i->map->map[y][x] == WL)
		put_img(s_i, &s_i->wall_left, x, y);
	else if (s_i->map->map[y][x] == WR)
		put_img(s_i, &s_i->wall_right, x, y);
	else if (s_i->map->map[y][x] == WC1)
		put_img(s_i, &s_i->wc_lt, x, y);
	else if (s_i->map->map[y][x] == WC2)
		put_img(s_i, &s_i->wc_rt, x, y);
	else if (s_i->map->map[y][x] == WC3)
		put_img(s_i, &s_i->wc_lb, x, y);
	else if (s_i->map->map[y][x] == WC4)
		put_img(s_i, &s_i->wc_rb, x, y);
	else if (s_i->map->map[y][x] == HOLE)
		put_img(s_i, &s_i->hole, x, y);
	else if (s_i->map->map[y][x] == DOOR)
		put_img(s_i, &s_i->door, x, y);
}

static void	render_torch(t_info *s_i, int x, int y)
{
	if (s_i->map->map[y][x] == WTT)
		put_img(s_i, &s_i->t_top[0], x, y);
	else if (s_i->map->map[y][x] == WBT)
		put_img(s_i, &s_i->t_bot[0], x, y);
	else if (s_i->map->map[y][x] == WLT)
		put_img(s_i, &s_i->t_left[0], x, y);
	else if (s_i->map->map[y][x] == WRT)
		put_img(s_i, &s_i->t_right[0], x, y);
}

static void	render_collect(t_info *s_i, int x, int y)
{
	if (s_i->map->map[y][x] == FLOOR)
		put_img(s_i, &s_i->floor, x, y);
	else if (s_i->map->map[y][x] == EXIT)
	{
		put_img(s_i, &s_i->floor, x, y);
		put_img(s_i, &s_i->exit, x, y);
	}
	else if (s_i->map->map[y][x] == COLEC)
	{
		put_img(s_i, &s_i->floor, x, y);
		put_img(s_i, &s_i->collect, x, y);
	}
	else if (s_i->map->map[y][x] == PERS)
	{
		put_img(s_i, &s_i->floor, x, y);
		put_img(s_i, &s_i->player.back[0], x, y);
		init_player (&s_i->player, x, y);
	}
	else if (s_i->map->map[y][x] == ENE)
	{
		put_img(s_i, &s_i->floor, x, y);
		put_img(s_i, &s_i->enemy.e_left[0], x, y);
	}
}

void	render_img(t_info *s_i)
{
	int		i;
	int		j;

	i = -1;
	while (++i < s_i->map->w)
	{
		j = -1;
		while (++j < s_i->map->h)
		{
			render_wall(s_i, i, j);
			render_torch(s_i, i, j);
			render_torch(s_i, i, j);
			render_collect(s_i, i, j);
		}
	}
}
