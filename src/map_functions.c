/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:03:46 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/19 22:30:01 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Allocate and add the file in array*/
void	start_map(int fd, t_map **map)
{
	int		count;
	char	*line;

	count = 0;
	(*map)->map = malloc(sizeof(char *) + 1);
	(*map)->map[count] = 0;
	while (get_next_line(fd, &line) == 0)
	{
		realloc((*map)->map, sizeof(char *) * (count + 2));
		(*map)->map[count++] = line;
		(*map)->map[count] = 0;
	}
		realloc((*map)->map, sizeof(char *) * (count + 2));
		(*map)->map[count++] = line;
		(*map)->map[count] = 0;
	(*map)->h = count + 1;
	(*map)->w = ft_strlen((*map)->map[0]);
}
