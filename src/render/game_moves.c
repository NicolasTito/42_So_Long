/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:50:26 by nide-mel          #+#    #+#             */
/*   Updated: 2021/10/02 10:39:07 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	char_side(int key, t_info *s_i)
{
	if (key == KEY_W && s_i->player.side != KEY_W)
	{
		s_i->player.side = KEY_W;
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.back[0], s_i->player.x, s_i->player.y);
		printf("W\n");
	}
	if (key == KEY_A && s_i->player.side != KEY_A)
	{
		s_i->player.side = KEY_A;
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.left[0], s_i->player.x, s_i->player.y);
		printf("A\n");
	}
	if (key == KEY_S && s_i->player.side != KEY_S)
	{
		s_i->player.side = KEY_S;
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.front[0], s_i->player.x, s_i->player.y);
		printf("S\n");
	}
	if (key == KEY_D && s_i->player.side != KEY_D)
	{
		s_i->player.side = KEY_D;
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.right[0], s_i->player.x, s_i->player.y);
		printf("D\n");
	}
}

int	game_moves(int key, t_info *s_i)
{
	if (key == KEY_ESC)
		exit_game(s_i);
	else if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
	{
		printf("TESTE\n");
		char_side(key, s_i);
	}
	return(0);
}
