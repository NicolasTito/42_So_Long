/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:50:26 by nide-mel          #+#    #+#             */
/*   Updated: 2021/10/08 12:52:50 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_move(t_info *s_i)
{
	s_i->moves++;
	ft_putnbr_fd(s_i->moves, 1);
	ft_putchar_fd('\n', 1);
}

static void	colect_exit(int key, t_info *s_i)
{
	if (((key == KEY_A && s_i->map->map[s_i->player.y][s_i->player.x - 1] == 4)
		|| (key == KEY_S
			&& s_i->map->map[s_i->player.y + 1][s_i->player.x] == 4)
		|| (key == KEY_D
			&& s_i->map->map[s_i->player.y][s_i->player.x + 1] == 4)
		|| (key == KEY_W
			&& s_i->map->map[s_i->player.y - 1][s_i->player.x] == 4))
		&& s_i->map->info.c == 0)
		exit_game(s_i);
}

static void	char_move_l_r(int key, t_info *s_i)
{
	if (s_i->map->map[s_i->player.y][s_i->player.x - 1] < 3 && key == KEY_A)
	{
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.left[1], s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.left[0], s_i->player.x - 1, s_i->player.y);
		s_i->player.x--;
		print_move(s_i);
	}
	if (s_i->map->map[s_i->player.y][s_i->player.x + 1] < 3 && key == KEY_D)
	{
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.right[1], s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.right[0], s_i->player.x + 1, s_i->player.y);
		s_i->player.x++;
		print_move(s_i);
	}
	colect_exit(key, s_i);
}

static void	char_move(int key, t_info *s_i)
{
	if (s_i->map->map[s_i->player.y - 1][s_i->player.x] < 3 && key == KEY_W)
	{
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.back[1], s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.back[0], s_i->player.x, s_i->player.y - 1);
		s_i->player.y--;
		print_move(s_i);
	}
	if (s_i->map->map[s_i->player.y + 1][s_i->player.x] < 3 && key == KEY_S)
	{
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.front[1], s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->floor, s_i->player.x, s_i->player.y);
		put_img(s_i, &s_i->player.front[0], s_i->player.x, s_i->player.y + 1);
		s_i->player.y++;
		print_move(s_i);
	}
	char_move_l_r(key, s_i);
}

int	game_moves(int key, t_info *s_i)
{
	if (key == KEY_ESC)
		exit_game(s_i);
	else if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
	{
		char_side(key, s_i);
		char_move(key, s_i);
		if (s_i->map->map[s_i->player.y][s_i->player.x] == COLEC)
		{
			s_i->map->info.c--;
			s_i->map->map[s_i->player.y][s_i->player.x] = FLOOR;
		}
	}
	return (0);
}
