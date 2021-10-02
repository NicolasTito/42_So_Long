/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:33:43 by nide-mel          #+#    #+#             */
/*   Updated: 2021/10/02 10:36:19 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_info *s_i)
{
	s_i->moves++;
	exit(0);
}

void	exit_program(t_info *s_i, char **temp)
{
	free_matrix(&s_i->map, temp);
	exit(1);
}

void	free_matrix(t_map **map, char **temp)
{
	int	i;

	i = -1;
	while (++i < (*map)->h)
		free(temp[i]);
	free(temp);
}

void	free_map(t_map **map, int **temp)
{
	int	i;

	i = -1;
	while (++i < (*map)->h)
		free(temp[i]);
	free(temp);
}

void	exit_error(void)
{
	ft_putstr_fd("UNEXPECTED ERROR\n", 1);
	exit(1);
}
