/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:16:25 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/23 17:04:24 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_info *s_i, t_img *img, int x, int y)
{
	mlx_put_image_to_window(s_i->mlx, s_i->win, img->img, x * IMG_H, y * IMG_W);
}

static void	render_wall(t_info *s_i, int x, int y)
{
	if (s_i->map->map[x][y] == WT)
		put_img(s_i, &s_i->wall_top, x, y);
	else if (s_i->map->map[x][y] == WB)
		put_img(s_i, &s_i->wall_bot, x, y);
	else if (s_i->map->map[x][y] == WL)
		put_img(s_i, &s_i->wall_left, x, y);
	else if (s_i->map->map[x][y] == WR)
		put_img(s_i, &s_i->wall_right, x, y);
	else if (s_i->map->map[x][y] == WC1)
		put_img(s_i, &s_i->wc_lt, x, y);
	else if (s_i->map->map[x][y] == WC2)
		put_img(s_i, &s_i->wc_rt, x, y);
	else if (s_i->map->map[x][y] == WC3)
		put_img(s_i, &s_i->wc_lb, x, y);
	else if (s_i->map->map[x][y] == WC4)
		put_img(s_i, &s_i->wc_rb, x, y);
	else if (s_i->map->map[x][y] == HOLE)
		put_img(s_i, &s_i->hole, x, y);
	else if (s_i->map->map[x][y] == DOOR)
		put_img(s_i, &s_i->door, x, y);
}

static void	render_torch(t_info *s_i, int x, int y)
{
	if (s_i->map->map[x][y] == WTT)
		put_img(s_i, &s_i->t_top[0], x, y);
	else if (s_i->map->map[x][y] == WBT)
		put_img(s_i, &s_i->t_bot[0], x, y);
	else if (s_i->map->map[x][y] == WLT)
		put_img(s_i, &s_i->t_left[0], x, y);
	else if (s_i->map->map[x][y] == WRT)
		put_img(s_i, &s_i->t_right[0], x, y);
}

static void	render_collect(t_info *s_i, int x, int y)
{
	if (s_i->map->map[x][y] == FLOOR)
		put_img(s_i, &s_i->floor, x, y);
	else if (s_i->map->map[x][y] == EXIT)
		put_img(s_i, &s_i->exit, x, y);
	else if (s_i->map->map[x][y] == COLEC)
	{
		put_img(s_i, &s_i->floor, x, y);
		put_img(s_i, &s_i->collect, x, y);
	}
	else if (s_i->map->map[x][y] == PERS)
	{
		put_img(s_i, &s_i->floor, x, y);
		put_img(s_i, &s_i->player.back[0], x, y);
	}
	else if (s_i->map->map[x][y] == ENE)
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
	while (++i < s_i->map->h)
	{
		j = -1;
		while (++j < s_i->map->w)
		{
			render_wall(s_i, i, j);
			render_torch(s_i, i, j);
			render_torch(s_i, i, j);
			render_collect(s_i, i, j);
		}
	}
}
