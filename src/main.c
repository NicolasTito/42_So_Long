/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:57:57 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/20 08:05:50 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Start the game and validate everything, create and init struct*/
void	start_program(char *file_name)
{
	t_info		s_i;
	int			fd;
	char		**temp;

	init_map(&s_i.map);
	fd = open(file_name, O_RDONLY);
	temp = start_map(fd, &s_i.map);
	close(fd);
	if (check_map(file_name, &s_i.map, temp) == FALSE)
		exit_program(&s_i, temp);
	organize_map(&s_i.map, temp);
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
