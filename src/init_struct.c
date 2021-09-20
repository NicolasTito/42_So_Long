/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:22:38 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/20 08:34:18 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Start a struct with information to the map*/
void	init_map(t_map **map)
{
	*map = malloc(sizeof(t_map) + 1);
	(*map)->h = 1;
	(*map)->w = 0;
	(*map)->info.c = 0;
	(*map)->info.exit = 0;
	(*map)->info.p = 0;
	(*map)->info.en = 0;
}

void	init_wall(t_wall *s_w, int h, int w)
{
	s_w->door = (w / 2) + 1;
	s_w->h_w = h - 2;
	s_w->w_w = w - 2;
	s_w->torch_w = 1;
	if (s_w->h_w > 3)
		s_w->torch_h = s_w->door - 1;
	else if (s_w->h_w == 1)
		s_w->torch_h = 0;
	else
		s_w->torch_h = 1;
}
