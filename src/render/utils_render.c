/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 04:40:07 by nide-mel          #+#    #+#             */
/*   Updated: 2021/10/26 04:55:39 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	frames_enemy(t_enemy *enemy)
{
	enemy->frame++;
	if (enemy->frame == 90)
		enemy->frame = -1;
}

void	render_enemy(t_info *s_i, int x, int y)
{
	int	sprite;

	sprite = 0;
	frames_enemy(&s_i->enemy);
	if ((s_i->enemy.frame >= 15 && s_i->enemy.frame < 30)
		|| (s_i->enemy.frame >= 75 && s_i->enemy.frame < 90))
		sprite = 1;
	else if ((s_i->enemy.frame >= 30 && s_i->enemy.frame < 45)
		|| (s_i->enemy.frame >= 60 && s_i->enemy.frame < 75))
		sprite = 2;
	else if ((s_i->enemy.frame >= 45 && s_i->enemy.frame < 60))
		sprite = 3;
	put_img(s_i, &s_i->enemy.e_left[sprite], x, y);
}
