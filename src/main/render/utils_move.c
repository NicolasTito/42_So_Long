/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:51:16 by nide-mel          #+#    #+#             */
/*   Updated: 2021/10/08 12:51:50 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_side(int key, t_info *s_i)
{
	if (key == KEY_W && s_i->player.side != KEY_W)
	{
		s_i->player.side = KEY_W;
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.back[0], s_i->player.x, s_i->player.y);
	}
	if (key == KEY_A && s_i->player.side != KEY_A)
	{
		s_i->player.side = KEY_A;
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.left[0], s_i->player.x, s_i->player.y);
	}
	if (key == KEY_S && s_i->player.side != KEY_S)
	{
		s_i->player.side = KEY_S;
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.front[0], s_i->player.x, s_i->player.y);
	}
	if (key == KEY_D && s_i->player.side != KEY_D)
	{
		s_i->player.side = KEY_D;
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.right[0], s_i->player.x, s_i->player.y);
	}
}
