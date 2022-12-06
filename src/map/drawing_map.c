/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:00:53 by pyammoun          #+#    #+#             */
/*   Updated: 2022/11/16 16:55:04by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	check_wall(t_info *info, float ym, float xm, int hit_box)
{
	int		i;
	int		j;
	int		side;

	if (hit_box && !create_hit_box(info, ym, xm, hit_box))
		return (0);
	side = get_map_index(&i, &j, ym, xm);
	if (info->mapi.map[i][j] == '1')
	{
		//printf("WALL : %d & %d\n", i, j);
		info->side = side;
		return (0);
	}
	info->mapi.map[i][j] = '2';
	return (1);
}

void	draw_player(t_info *info, int xm, int ym)
{
	int	i;
	int	j;
	float	center_x;
	float	center_y;

	info->mapi.co_x += xm;
	info->mapi.co_y += ym;
	i = 0;
	while (i++ < P_SIZE)
	{
		j = 0;
		while (j++ < P_SIZE)
			ft_put_pixel(&info->img, MINIMAP / 2 * X + j, MINIMAP / 2 * Y + i, 0x00FF0000);
	}
	center_x = MINIMAP / 2 * X + (P_SIZE / 2);
	center_y = MINIMAP / 2 * X + (P_SIZE / 2);;
	i = 0;
	while (i < 100)
	{
		ft_put_pixel(&info->img, center_x, center_y,  0x00FF0000);
		center_x -= info->mapi.d_x / 50;
		center_y -= info->mapi.d_y / 50;
		i++;
	}
}

void	draw_cube(t_info *info, int l, int c, int t, int p)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = l * Y;
	// printf("y  index apres : %d\n", t);
	// printf("x index  apres : %d\n\n", p);
	get_map_index(&y, &x, info->mapi.co_y, info->mapi.co_x);
	while (i < (l * Y + Y))
	{
		j = c * X;
		while (j < (c * X + X))
		{
			if (info->mapi.map[t][p] == '1')
				ft_put_pixel(&info->img, j, i, 0xffffffff);
			if (info->mapi.map[t][p] == '0')
				ft_put_pixel(&info->img, j, i, 0xffffffff);
			if (info->mapi.map[t][p] == '2')
				ft_put_pixel(&info->img, j, i, 0xaabbbbbb);
			++j;
		}
		i++;
	}
}

void	draw_direction(t_info *info)
{
	float	center_x;
	float	center_y;
	float	i;
	float	new_angle_x;
	float	new_angle_y;

	i = 0;
	info->ray.num = 0;
	while (info->ray.num < RES_X)
	{	
		i = info->ray.num / 1920.0 * (-0.96) + 0.48;
		new_angle_x = cos(info->mapi.a - i) * SPEED;
		info->ray.ray_ang = info->mapi.a - i;
		if (info->ray.ray_ang > 2 * PI)
			info->ray.ray_ang -= 2 * PI;
		if (info->ray.ray_ang < 0)
			info->ray.ray_ang += 2 * PI;
		//printf("angle : %f\n", info->ray.ray_ang);
		new_angle_y = sin(info->mapi.a - i) * SPEED;
		center_x = info->mapi.co_x + (P_SIZE / 2);
		center_y = info->mapi.co_y + (P_SIZE / 2);
		while (check_wall(info, center_y, center_x, 0))
		{
			//if (info->ray.num == 960)
				//ft_put_pixel(&info->img, center_x, center_y, 0X0f986ab3);
			if (check_wall(info, center_y - new_angle_y / 50, center_x - new_angle_x / 50, 0) == 0) 
			{
				center_x -= new_angle_x / 500;
				center_y -= new_angle_y / 500;
			}
			else 
			{
				center_x -= new_angle_x / 50;
				center_y -= new_angle_y / 50;
			}
		}
		//printf("x: %f & y: %f\n", center_x / X, center_y / Y );
		info->ray.wx = center_x;
		info->ray.wy = center_y;
		info->ray.dst = sqrt((info->mapi.co_x - center_x) * (info->mapi.co_x - center_x) + (info->mapi.co_y - center_y) * (info->mapi.co_y - center_y));
		wall_face(center_x / X, center_y / Y, info);
		info->ray.num += 2;
		//printf("mapi: %f\n\n", info->mapi.a);
		// printf("ray : %d\n", info->ray.num);
		// printf("i : %f\n", i);
	}
}

void	draw(t_info *info, int xm, int ym)
{
	int	x;
	int	y;
	int	j;
	int	i;

	x = 0;
	y = 0;
	i = -1;
	get_map_index(&y, &x, info->mapi.co_y, info->mapi.co_x);
	// printf("y : %d\n", y);
	// printf("x : %d\n", x);

	y -= (MINIMAP / 2);
	x -= (MINIMAP / 2);
	// printf("y apres : %d\n", y);
	// printf("x apres : %d\n", x);
	//printf("mapi.h : %d\n", info->mapi.h);
	while (++i < MINIMAP)
	{
		j = -1;
		if ((y + i) >= 0 && (y + i) < info->mapi.h)
		{
			while (++j < MINIMAP)
			{
				if ((x + j) >= 0 && (x + j) <= info->mapi.w)
				{
					//printf("on draw le cube : %d   %d\n", y + i, x + j);
					draw_cube(info, i, j, i + y, j + x);
				}
			}
		}
			
	}
	clear_img(info);
	draw_player(info, xm, ym);
	draw_direction(info);
	mlx_put_image_to_window(info->mlx, info->win, info->imgu.img, 0, 0);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}
