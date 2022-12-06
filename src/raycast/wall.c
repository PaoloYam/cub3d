/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:07:14 by pyammoun          #+#    #+#             */
/*   Updated: 2022/12/06 20:26:32 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	choose_texture(t_info *info, int x, int *y, int yi)
{
	int	color;

	color = 0;
	//printf("prct : %f\n", info->ray.prt);
	if (info->ray.lstw == 'N')
		color = get_pixel_color(info, 0, floor(info->ray.prt * info->wall[0].width), ((float)(*y - yi)) / info->ray.lH * info->wall[0].heigth);
	else if (info->ray.lstw == 'S')
		color = get_pixel_color(info, 1, floor(info->ray.prt * info->wall[1].width), ((float)(*y - yi)) / info->ray.lH * info->wall[1].heigth);
	else if (info->ray.lstw == 'E')
		color = get_pixel_color(info, 2, floor(info->ray.prt * info->wall[2].width), ((float)(*y - yi)) / info->ray.lH * info->wall[2].heigth);
	else if (info->ray.lstw == 'W')
		color = get_pixel_color(info, 3, floor(info->ray.prt * info->wall[3].width), ((float)(*y - yi)) / info->ray.lH * info->wall[3].heigth);
	ft_put_pixel(&info->imgu, info->ray.num + x, *y, color);
	*y += 1;
}

void	draw_wall(t_info *info)
{
	int		y;
	int		yi;
	float	ca;
	int		x;

	x = 0;
	ca = info->mapi.a - info->ray.ray_ang;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	info->ray.lH = RES_Y / info->ray.dst * 15 / (0.7 * cos(ca));
	//printf("oui %f\n", info->ray.lH);
	while (x < 2)
	{
		y = -1;
		while (++y < (RES_Y - info->ray.lH) / 2)
			ft_put_pixel(&info->imgu, info->ray.num + x, y, info->texture.ceiling_int);
		//printf("%d\n", y);
		yi = y;
		while (y < (yi + info->ray.lH) && y < RES_Y)
		{	
			choose_texture(info, x, &y, yi);
			//ft_put_pixel(&info->imgu, info->ray.num + x, y, 0x8798787);
			//y++;
		}
			
			
		while (y < RES_Y)
		{
			ft_put_pixel(&info->imgu, info->ray.num + x, y, info->texture.floor_int);
			y++;
		}
		x++;
	}
}

void	find_wall(float x, float y, t_info *info, int v)
{
	if (v == 1)
	{
		info->ray.prt = y;
		if (info->ray.ray_ang < 1.5 * PI && info->ray.ray_ang > 0.5 * PI)
			info->ray.lstw = 'W';
		else
			info->ray.lstw = 'E';
	}
	else if (v == 2)
	{
		info->ray.prt = x;
		if (info->ray.ray_ang < 2 * PI && info->ray.ray_ang > PI)
			info->ray.lstw = 'N';
		else
			info->ray.lstw = 'S';
	}
	//rintf("distance: %d\n", info->ray.dst);
	//printf("Face: %c\n", info->ray.lstw);
	//printf("pourcentage: %f\n", info->ray.prt);*/
	draw_wall(info);
}

void	wall_face(float x, float y, t_info *info)
{
	int		xi;
	int		yi;

	xi = x;
	yi = y;
	x = x - xi;
	y = y - yi;
	if (x > 0.5)
	{
		if (1 - x < 0.001)
			find_wall(x, y, info, 1);
	}
	else if (x < 0.5)
	{
		if ((-1 * (x - 1)) > 0.999)
			find_wall(x, y, info, 1);
	}
	if (y > 0.5)
	{
		if (1 - y < 0.001)
			find_wall(x, y, info, 2);
	}
	else if (y < 0.5)
	{
		if ((-1 * (y - 1)) > 0.999)
			find_wall(x, y, info, 2);
	}
}
