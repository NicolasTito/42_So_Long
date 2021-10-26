/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 01:05:25 by nide-mel          #+#    #+#             */
/*   Updated: 2021/10/26 04:17:32 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	counter_frame(t_info *s_i)
{
	s_i->frames++;
	if (s_i->frames == 40)
		s_i->frames = -1;
}

int	game_render(t_info *s_i)
{
	mlx_clear_window(s_i->mlx, s_i->win);
	counter_frame(s_i);
	render_img(s_i);
	return (0);
}

void	render_pers(t_info *s_i, int x, int y)
{
	if (s_i->player.side == KEY_W)
		put_img(s_i, &s_i->player.back[0], x, y);
	if (s_i->player.side == KEY_A)
		put_img(s_i, &s_i->player.left[0], x, y);
	if (s_i->player.side == KEY_S)
		put_img(s_i, &s_i->player.front[0], x, y);
	if (s_i->player.side == KEY_D)
		put_img(s_i, &s_i->player.right[0], x, y);
}