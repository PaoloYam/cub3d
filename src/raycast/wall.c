/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:07:14 by pyammoun          #+#    #+#             */
/*   Updated: 2022/12/05 19:07:23 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"


// void	direction_checker(char *x, char *y, t_info *info)
// {
// 	//int	i;
// 	(void)info;
// 	(void)y;
// 	// ft_sub
// }

void	draw_wall(t_info *info)
{
	int y;
	int	yi;
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
			ft_put_pixel(&info->imgu, info->ray.num + x, y, 0x00FEDD00);
		//printf("%d\n", y);
		yi = y;
		while (y < (yi + info->ray.lH) && y < RES_Y)
		{
			//printf("x; %d et y: %d\n", x, y);printf("la : %f\n", info->ray.lH);
			if (info->ray.lstw == 'N')
				ft_put_pixel(&info->imgu, info->ray.num + x, y, 0x009DE7D7);
			else if (info->ray.lstw == 'E')
				ft_put_pixel(&info->imgu, info->ray.num+ x, y, 0x009D44D7);	
			else if (info->ray.lstw == 'W')
				ft_put_pixel(&info->imgu, info->ray.num+ x, y, 0x009DAAD7);	
			else if (info->ray.lstw == 'S')
				ft_put_pixel(&info->imgu, info->ray.num+ x, y, 0x009DE700);	
			y++;
		}
		while (y < RES_Y)
		{
			ft_put_pixel(&info->imgu, info->ray.num + x, y, 0x0074D1EA);
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
		if (info->ray.ray_ang < 1.5 * PI &&  info->ray.ray_ang > 0.5 * PI)
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
	//printf("calcul x: %f & y: %f\n", x, y);
	if (x > 0.5)
	{
		if (1 - x < 0.001)
		{
			//printf("1");
			find_wall(x, y, info, 1);
		}
	}
	else if (x < 0.5)
	{
		if ((-1 * (x - 1)) > 0.999)
		{	
			//printf("2\n");
			find_wall(x, y, info, 1);
		}
	}
	if (y > 0.5)	
	{
		if (1 - y < 0.001)
		{
			//printf("3\n");
			find_wall(x, y, info, 2);
		}
	}
	else if (y < 0.5)
	{
		if ((-1 * (y - 1)) > 0.999)
		{
			//printf("4\n");
			find_wall(x, y, info, 2);
		}
	}
}