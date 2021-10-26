/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:51:16 by nide-mel          #+#    #+#             */
/*   Updated: 2021/10/26 15:30:03 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_side(int key, t_info *s_i)
{
	if (key == KEY_W && s_i->player.side != KEY_W)
	{
		s_i->player.side = KEY_W;
	}
	if (key == KEY_A && s_i->player.side != KEY_A)
	{
		s_i->player.side = KEY_A;
	}
	if (key == KEY_S && s_i->player.side != KEY_S)
	{
		s_i->player.side = KEY_S;
	}
	if (key == KEY_D && s_i->player.side != KEY_D)
	{
		s_i->player.side = KEY_D;
	}
}

void	verify_enemy(int key, t_info *s_i)
{
	if ((s_i->map->map[s_i->player.y + 1][s_i->player.x] == ENE && key == KEY_S)
	|| (s_i->map->map[s_i->player.y - 1][s_i->player.x] == ENE && key == KEY_W)
	|| (s_i->map->map[s_i->player.y][s_i->player.x - 1] == ENE && key == KEY_A)
	|| (s_i->map->map[s_i->player.y][s_i->player.x + 1] == ENE && key == KEY_D))
		exit_game(s_i);
}
