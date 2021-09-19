/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:22:38 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/19 20:31:06 by nide-mel         ###   ########.fr       */
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
