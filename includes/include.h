/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:32:54 by pyammoun          #+#    #+#             */
/*   Updated: 2022/12/07 18:25:14 by pyammoun         ###   ########.fr       */
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
# define X	20
# define Y	20
# define RES_X 1920
# define RES_Y 1080
# define P_SIZE (X / 3)
# define PX	1
# define PI 3.1415926535
# define SPEED 7
# define HIT_BOX 2
#define	MINIMAP 10

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

typedef struct s_ray	t_ray;
struct s_ray {
	char	lstw;
	float	dst;
	float	prt;
	float	lH;
	float	wx;
	float	wy;
	float	nax;
	float	nay;
	float	ca;
	int		num;
	float	ray_ang;
};


typedef struct s_texture	t_texture;
struct s_texture {
	char	*n_wall;
	char	*s_wall;
	char	*w_wall;
	char	*e_wall;
	char	*floor; //a free a la fin
	char	*ceiling;//a free a la fin
	int		ceiling_int;
	int		floor_int;
};

typedef struct s_wall	t_wall; //a free a la fin * nbr de texture
struct s_wall {
	void	*wall; //wall[i++] = nord -> sud -> est -> west
	int		bits;
	int		len;
	int		endian;
	int		width;
	int		heigth;
	int		*addr;
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
	int			side;	
	void		*mlx;
	void		*win;
	void		*mlxu;
	void		*winu;
	t_img		img;
	t_img		imgu;
	t_texture	texture;
	t_ray		ray;
	t_wall		*wall;
	char		**info;
};


/* RAYCAST */
void	wall_face(float x, float y, t_info *info);
int 	get_pixel_color(t_info *info, int i, int x, int y);

/*	MAP */

void	draw(t_info *info, int xm, int ym);
void	final_map(t_map *mapi);
int		map_maker(t_info *info);
int		line_number(char *argv, t_info *info);
void	init_player(t_info *info);
void	ft_put_pixel(t_img *img, int x, int y, int color);
int		check_wall(t_info *info, float ym, float xm, int hit_box);
int		get_map_index(int *i, int *j, float ym, float xm);
int		create_hit_box(t_info *info, float ym, float xm, int key);
void	clear_img(t_info *info);
void	draw_direction(t_info *info);
int		control_map5(t_map *mapi);
int		control_map4(t_map *mapi);
int		control_map3(t_map *mapi);

/* TEXTURE */

int		load_info(t_info *info, char **argv);
void	initialize_texture(t_info *info);
void	free_dub_tab(char **str, int n);
int		check_info(t_info *info);
int		all_num(char *str);
int		all_info(t_info *info);
void	load_map(int i, int line, int fd, t_info *info);
int		free_texture(t_info *info, int line);
int		integer_color(char *str);
int		load_texture(t_info *info);

/* HOOKS */

int		change_position(int keycode, t_info *info);
void	hooks(t_info *info);
//int		move_camera(int keycode, t_info *info);
#endif
