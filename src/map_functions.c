/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:03:46 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/20 08:08:14 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Allocate and add the file in array*/
char	**start_map(int fd, t_map **map)
{
	int		count;
	char	*line;
	char	**temp;

	count = 0;
	temp = malloc(sizeof(char *) + 1);
	if (!temp)
		exit_error();
	temp[count] = 0;
	while (get_next_line(fd, &line) == 1)
	{
		temp = realloc(temp, sizeof(char *) * (count + 2));
		temp[count++] = line;
		temp[count] = 0;
	}
	temp = realloc(temp, sizeof(char *) * (count + 2));
	temp[count++] = ft_substr(line, 0, ft_strlen(line));
	temp[count] = 0;
	(*map)->h = count;
	(*map)->w = ft_strlen(temp[0]);
	free(line);
	return (temp);
}

/*Create a map in struct*/
void	organize_map(t_map **map, char **temp)
{
	int	i;
	int	j;

	i = -1;
	(*map)->map = malloc(sizeof (int *) * (*map)->h);
	while (++i < (*map)->h)
		(*map)->map[i] = malloc(sizeof (int) * (*map)->w);
	i = -1;
	while (++i < (*map)->h)
	{
		j = -1;
		while (++j < (*map)->w)
			(*map)->map[i][j] = -1;
	}
	populate_wall_corner(map);
	free_temp(map, temp);
}
