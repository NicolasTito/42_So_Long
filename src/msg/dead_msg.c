/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:15:55 by nide-mel          #+#    #+#             */
/*   Updated: 2021/10/28 06:40:50 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_msg(t_info *s_i, t_img *img, int x, int y)
{
	y = (s_i->map->h - y) / 2;
	mlx_put_image_to_window(s_i->mlx, s_i->win, img->img, x, y * IMG_H);
}

void	dead_msg(t_info *s_i)
{
	int	x;

	x = 0;
	x = (s_i->map->w - 5) / 2;
	if (s_i->map->w == 3)
		put_msg(s_i, &s_i->s_msg.dead_msg[0], 64, 5);
	else if (s_i->map->w == 4)
		put_msg(s_i, &s_i->s_msg.dead_msg[2], 2, 2);
	else
		put_msg(s_i, &s_i->s_msg.dead_msg[1], x * IMG_H, 1);
}
