/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_sl.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 05:30:47 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/20 06:04:13 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SL_H
# define STRUCT_SL_H

# include "so_long.h"

typedef struct s_info_map
{
	int	c;
	int	exit;
	int	p;
	int	en;
}				t_info_map;

typedef struct s_wall
{
	int	door;
	int	h_w;
	int	w_w;
	int	torch_h;
	int	torch_w;
}				t_wall;

typedef struct s_map
{
	int			w;
	int			h;
	int			**map;
	t_info_map	info;
}				t_map;

typedef struct s_info
{
	t_map		*map;
}				t_info;

#endif