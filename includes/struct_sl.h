/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_sl.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 05:30:47 by nide-mel          #+#    #+#             */
/*   Updated: 2021/10/29 22:40:45 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SL_H
# define STRUCT_SL_H

# include "so_long.h"
# include "../minilibx_mms_20200219/mlx.h"
# include "functions_sl.h"

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			wid;
	int			heig;
}				t_img;

typedef struct s_msg
{
	t_img		dead_msg[3];
	t_img		win_msg[3];
}				t_msg;

typedef struct s_info_map
{
	int			c;
	int			exit;
	int			p;
	int			en;
}				t_info_map;

typedef struct s_player
{
	int			y;
	int			x;
	int			lives;
	int			side;
	t_img		front[2];
	t_img		back[2];
	t_img		right[2];
	t_img		left[2];
}				t_player;

typedef struct s_enemy
{
	int			width;
	int			height;
	int			frame;
	t_img		e_right[4];
	t_img		e_left[4];
}				t_enemy;

typedef struct s_wall
{
	int			door;
	int			h_w;
	int			w_w;
	int			torch_h;
	int			torch_w;
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
	void		*mlx;
	void		*win;
	int			moves;
	int			total_collect;
	int			frames;
	int			msg;
	t_msg		s_msg;
	t_map		*map;
	t_player	player;
	t_enemy		enemy;
	t_img		collect;
	t_img		exit;
	t_img		floor;
	t_img		hole;
	t_img		door;
	t_img		wc_lt;
	t_img		wc_rt;
	t_img		wc_lb;
	t_img		wc_rb;
	t_img		wall_top;
	t_img		wall_bot;
	t_img		wall_right;
	t_img		wall_left;
	t_img		t_top[3];
	t_img		t_right[3];
	t_img		t_left[3];
	t_img		t_bot[3];
}				t_info;

#endif