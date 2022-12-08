/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:07:14 by pyammoun          #+#    #+#             */
/*   Updated: 2022/12/08 23:23:45 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	choose_texture(t_info *info, int x, int *y, int yi)
{
	int	color;
	int	marge;

	color = 0;
	marge = 0;
	if (info->ray.lH > 1080)
	marge = (info->ray.lH - 1080) / 2;
	if (info->ray.lstw == 'N')
		color = get_pixel_color(info, 0, floor(info->ray.prt
					* info->wall[0].width), ((float)(*y - yi + marge))
				/ info->ray.lH * info->wall[0].heigth);
	else if (info->ray.lstw == 'S')
		color = get_pixel_color(info, 1, floor(info->ray.prt
					* info->wall[1].width), ((float)(*y - yi + marge))
				/ info->ray.lH * info->wall[1].heigth);
	else if (info->ray.lstw == 'E')
		color = get_pixel_color(info, 2, floor(info->ray.prt
					* info->wall[2].width), ((float)(*y - yi + marge))
				/ info->ray.lH * info->wall[2].heigth);
	else if (info->ray.lstw == 'W')
		color = get_pixel_color(info, 3, floor(info->ray.prt
					* info->wall[3].width), ((float)(*y - yi + marge))
				/ info->ray.lH * info->wall[3].heigth);
	ft_put_pixel(&info->imgu, info->ray.num + x, *y, color);
	*y += 1;
}

void	draw_wall(t_info *info)
{
	int		y;
	int		yi;
	int		x;

	x = -1;
	info->ray.ca = info->mapi.a - info->ray.ray_ang;
	if (info->ray.ca < 0)
		info->ray.ca += 2 * PI;
	if (info->ray.ca > 2 * PI)
		info->ray.ca -= 2 * PI;
	info->ray.lH = RES_Y / info->ray.dst * 20 / (0.7 * cos(info->ray.ca));
	while (++x < 2)
	{
		y = -1;
		while (++y < (RES_Y - info->ray.lH) / 2)
			ft_put_pixel(&info->imgu, info->ray.num + x, y,
				info->texture.ceiling_int);
		yi = y;
		while (y < (yi + info->ray.lH) && y < RES_Y)
			choose_texture(info, x, &y, yi);
		y -= 1;
		while (++y < RES_Y)
			ft_put_pixel(&info->imgu, info->ray.num + x, y,
				info->texture.floor_int);
	}
}

void	find_wall2(float y, t_info *info)
{
	if (y < 0.001 || y > 0.999)
	{
		info->ray.lstw = info->ray.last_w;
		info->ray.prt = info->ray.last_prt;
	}
	else
	{
		info->ray.prt = y;
		if (info->ray.ray_ang < 1.5 * PI && info->ray.ray_ang > 0.5 * PI)
			info->ray.lstw = 'W';
		else
			info->ray.lstw = 'E';
	}
}

void	find_wall(float x, float y, t_info *info, int v)
{
	if (v == 1)
	{
		find_wall2(y, info);
	}
	else if (v == 2)
	{
		if (x < 0.001 || x > 0.999)
		{
			info->ray.lstw = info->ray.last_w;
			info->ray.prt = info->ray.last_prt;
		}
		else
		{
			info->ray.prt = x;
			if (info->ray.ray_ang < 2 * PI && info->ray.ray_ang > PI)
				info->ray.lstw = 'N';
			else
				info->ray.lstw = 'S';
		}
	}
	info->ray.last_w = info->ray.lstw;
	info->ray.last_prt = info->ray.prt;
	draw_wall(info);
}

void	wall_face(float x, float y, t_info *info)
{	
	x = x - (int)x;
	y = y - (int)y;
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
