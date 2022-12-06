/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:07:14 by pyammoun          #+#    #+#             */
/*   Updated: 2022/12/06 15:39:06 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	choose_texture(t_info *info, int x, int *y)
{
	if (info->ray.lstw == 'N')
		ft_put_pixel(&info->imgu, info->ray.num + x, *y, 0x009DE7D7);
	else if (info->ray.lstw == 'E')
		ft_put_pixel(&info->imgu, info->ray.num + x, *y, 0x009D44D7);
	else if (info->ray.lstw == 'W')
		ft_put_pixel(&info->imgu, info->ray.num + x, *y, 0x009DAAD7);
	else if (info->ray.lstw == 'S')
		ft_put_pixel(&info->imgu, info->ray.num + x, *y, 0x008723fd);
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
			choose_texture(info, x, &y);
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
