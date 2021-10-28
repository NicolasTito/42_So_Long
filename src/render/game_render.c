/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 01:05:25 by nide-mel          #+#    #+#             */
/*   Updated: 2021/10/28 06:34:17 by nide-mel         ###   ########.fr       */
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
	if (s_i->msg == MSG_DEAD)
		dead_msg(s_i);
	return (0);
}
