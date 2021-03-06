/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 03:07:14 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/21 19:47:15 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	populate_top_wall(t_wall *s_w, t_map **map, int i)
{
	if ((s_w->door % 2) == 0)
	{
		if ((i % 2) == 0)
			(*map)->map[0][i] = WTT;
		else
			(*map)->map[0][i] = WT;
	}
	else if (((*map)->w % 2) == 1)
	{
		if ((i % 2) == 0)
			(*map)->map[0][i] = WT;
		else
			(*map)->map[0][i] = WTT;
	}
	else
	{
		if ((i % 2) == 0)
			(*map)->map[0][i] = WT;
		else
			(*map)->map[0][i] = WTT;
	}
}

static void	populate_bot_wall(t_map **map, int i)
{
	if ((i % 2) == 0)
		(*map)->map[(*map)->h - 1][i] = WB;
	else
		(*map)->map[(*map)->h - 1][i] = WBT;
}

static void	populate_tb_wall(t_wall *s_w, t_map **map)
{
	int	i;

	i = 0;
	while (++i <= s_w->w_w)
	{
		if ((*map)->map[0][i] == -1)
		{
			if (s_w->torch_h != 0)
				populate_top_wall(s_w, map, i);
		}
		populate_bot_wall(map, i);
	}
}

static void	populate_lr_wall(t_wall *s_w, t_map **map)
{
	int	i;

	i = 0;
	while (++i <= s_w->h_w)
	{
		if ((i % 2) == 0)
		{
			(*map)->map[i][0] = WL;
			(*map)->map[i][(*map)->w - 1] = WR;
		}
		else
		{
			(*map)->map[i][0] = WLT;
			(*map)->map[i][(*map)->w - 1] = WRT;
		}
	}
}

void	populate_wall_corner(t_map **map, char **temp)
{
	t_wall	s_w;

	init_wall(&s_w, (*map)->h, (*map)->w);
	(*map)->map[0][0] = WC1;
	(*map)->map[0][(*map)->w - 1] = WC2;
	(*map)->map[(*map)->h - 1][0] = WC3;
	(*map)->map[(*map)->h - 1][(*map)->w - 1] = WC4;
	(*map)->map[0][s_w.door - 1] = DOOR;
	populate_tb_wall(&s_w, map);
	populate_lr_wall(&s_w, map);
	populate_center_map(map, temp, &s_w);
}
