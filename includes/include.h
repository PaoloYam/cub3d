/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:32:54 by pyammoun          #+#    #+#             */
/*   Updated: 2022/11/24 21:09:46 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define SIZE 20
# define X	60
# define Y	60
# define P_SIZE (X / 3)
# define PX	1
# define PI 3.1415926535
# define MOUVE 2

typedef struct s_map	t_map;
struct s_map {
	char	**map;
	float		co_y;
	float		co_x;
	float		d_x;
	float		d_y;
	float		a;
	int		pos_x;
	int		pos_y;
	char	P;
	int 	w;
	int		h;
};

typedef struct s_texture	t_texture;
struct s_texture {
	char	*n_wall;
	char	*s_wall;
	char	*w_wall;
	char	*e_wall;
	char	*floor;
	char	*ceiling;
};

typedef	struct s_img	t_img;
struct	s_img {
	void	*img;
	char	*addr;
	int		bits;
	int		len;
	int		endian;
};

typedef struct s_info	t_info;
struct s_info {
	t_map		mapi;	
	void		*mlx;
	void		*win;
	t_img		img;
	t_texture	texture;
	char		**info;
};

/*	MAP */

void	draw(t_info *info, int xm, int ym);
void	final_map(t_map *mapi);
int		map_maker(t_info *info);
int		line_number(char *argv, t_info *info);
void	init_player(t_info *info);
void	ft_put_pixel(t_img *img, int x, int y, int color);
int		check_wall(t_info *info, float ym, float xm, int hit_box);
void	get_map_index(int *i, int *j, float ym, float xm);
int		create_hit_box(t_info *info, float ym, float xm);

/* TEXTURE */

int		load_info(t_info *info, char **argv);
void	initialize_texture(t_info *info);
void	free_dub_tab(char **str, int n);
int		check_info(t_info *info);
int		all_num(char *str);
int		all_info(t_info *info);
void	load_map(int i, int line, int fd, t_info *info);
int		free_texture(t_info *info, int line);

/* HOOKS */

int		change_position(int keycode, t_info *info);
void	hooks(t_info *info);
//int		move_camera(int keycode, t_info *info);
#endif
