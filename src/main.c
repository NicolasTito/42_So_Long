/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:57:57 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/20 00:42:21 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Start the game and validate everything, create and init struct*/
void	start_program(char *file_name)
{
	t_info		s_i;
	int			fd;
	int			i;
	int			j;

	init_map(&s_i.map);
	fd = open(file_name, O_RDONLY);
	if (check_map(file_name, &s_i.map, fd) == FALSE)
		exit_program(&s_i);
	else
	{
		i = -1;
		while (++i < s_i.map->h)
		{
			j = 0;
			while (s_i.map->map[i][j])
			{
				ft_putchar_fd(s_i.map->map[i][j], 1);
				j++;
			}
			ft_putchar_fd('\n', 1);
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("ARGUMENTS ERROR 😐\n", 1);
		return (-1);
	}
	start_program(av[1]);
	return (0);
}
