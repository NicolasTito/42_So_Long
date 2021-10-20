/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:57:57 by nide-mel          #+#    #+#             */
/*   Updated: 2021/10/20 12:58:09 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_info *s_i)
{
	int	width;
	int	height;

	width = s_i->map->w * IMG_W;
	height = s_i->map->h * IMG_H;
	s_i->mlx = mlx_init();
	s_i->win = mlx_new_window(s_i->mlx, width, height, "SO LONG");
	init_images(s_i);
	mlx_hook(s_i->win, 17, 0, destroy_window, s_i);
	mlx_key_hook(s_i->win, game_moves, s_i);
	mlx_loop_hook(s_i->win, game_render, s_i);
	mlx_loop(s_i->mlx);
}

/*Start the game and validate everything, create and init struct*/
void	start_program(char *file_name)
{
	t_info		s_i;
	int			fd;
	char		**temp;

	init_info(&s_i);
	init_map(&s_i.map);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("MAP NOT EXIST", 1);
		return ;
	}
	temp = start_map(fd, &s_i.map);
	close(fd);
	if (check_map(file_name, &s_i.map, temp) == FALSE)
		exit_program(&s_i, temp);
	organize_map(&s_i.map, temp);
	init_game(&s_i);
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
