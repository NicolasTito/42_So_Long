/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 05:21:12 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/20 00:41:33 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	verify_rest_map(t_map **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (*map)->h)
	{
		j = -1;
		while ((*map)->map[i][++j])
		{
			if ((*map)->map[i][j] == 'C')
				(*map)->info.c++;
			else if ((*map)->map[i][j] == 'E')
				(*map)->info.exit = 1;
			else if ((*map)->map[i][j] == 'P')
				(*map)->info.p++;
			else if ((*map)->map[i][j] == 'N')
				(*map)->info.en = 1;
			else if ((*map)->map[i][j] != '1' && (*map)->map[i][j] != '0')
				return (FALSE);
		}
	}
	return (TRUE);
}

static int	verify_wall(t_map **map)
{
	int	i;

	i = -1;
	while (++i < (*map)->w)
	{
		if ((*map)->map[0][i] != '1')
			return (FALSE);
		if ((*map)->map[(*map)->h - 1][i] != '1')
			return (FALSE);
	}
	i = -1;
	while (++i < (*map)->h)
	{
		if ((*map)->map[i][0] != '1')
			return (FALSE);
		if ((*map)->map[i][(*map)->w - 1] != '1')
			return (FALSE);
	}
	return (TRUE);
}

static int	verify_map(t_map **map)
{
	int	i;

	i = 0;
	while (++i < (*map)->h)
	{
		if (ft_strlen((*map)->map[i]) != (*map)->w)
			return (FALSE);
	}
	return (TRUE);
}

/*Validate name map*/
static int	check_name(char *file_name, char *ber)
{
	int	i;
	int	j;

	i = -1;
	while (file_name[++i])
	{
		if (file_name[i] == '.')
		{
			j = 0;
			while (file_name[i] == ber[j] && (file_name[i] || ber[j]))
			{
				i++;
				j++;
			}
			if (file_name[i] == 0 && ber[j] == 0)
				return (TRUE);
		}
	}
	return (FALSE);
}

/*Validate map and create array with informations*/
int	check_map(char *file_name, t_map **map, int fd)
{
	if (check_name(file_name, ".ber") == FALSE)
	{
		ft_putstr_fd("MAP NAME ERROR 😐\n", 1);
		return (FALSE);
	}
	start_map(fd, map);
	close(fd);
	if (verify_map(map) == FALSE || verify_rest_map(map) == FALSE)
	{
		ft_putstr_fd("MAP ERROR 😐\n", 1);
		return (FALSE);
	}
	else if (verify_wall(map) == FALSE)
	{
		ft_putstr_fd("WALL ERROR 😐\n", 1);
		return (FALSE);
	}
	else if ((*map)->info.c < 1 || (*map)->info.p != 1 || (*map)->info.exit < 1)
	{
		ft_putstr_fd("NOT ALL ELEMENTS OF THE MAP CAN BE FOUND 😐\n", 1);
		return (FALSE);
	}
	return (TRUE);
}
