/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 05:21:12 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/19 20:03:30 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
int	check_map(char *file_name, t_map **map)
{
	int		fd;

	if (check_name(*file_name, ".ber") == FALSE)
	{
		ft_putstr_fd("MAP NAME ERROR 😐", 1);
		return (FALSE);
	}
	fd = open(map, O_RDONLY);
}
