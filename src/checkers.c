/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 05:21:12 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/19 19:16:45 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Validate name map*/
static int	check_name(char *map, char *ber)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		if (map[i] == '.')
		{
			j = 0;
			while (map[i] == ber[j] && (map[i] || ber[j]))
			{
				i++;
				j++;
			}
			if (map[i] == 0 && ber[j] == 0)
				return (TRUE);
		}
	}
	return (FALSE);
}

/*Validate map and create array with informations*/
int	check_map(char *map)
{
	int		fd;
	t_map	s_m;

	if (check_name(*map, ".ber") == FALSE)
	{
		ft_putstr_fd("MAP NAME ERROR 😐", 1);
		return (FALSE);
	}
	fd = open(map, O_RDONLY);

}
