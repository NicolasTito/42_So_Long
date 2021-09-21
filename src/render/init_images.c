/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:08:27 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/21 20:56:21 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xmp_to_image(t_info *s_i, t_img *img, char *path)
{
	img->addr = mlx_xpm_file_to_image(s_i->mlx, path, &img->wid, &img->heig);
	if (!img->addr)
	{
		free_matrix(s_i->map, s_i->map->map);
		exit_error();
	}
}

void	init_images(t_info *s_i)
{

}