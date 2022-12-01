/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:07:14 by pyammoun          #+#    #+#             */
/*   Updated: 2022/12/01 16:40:30 by pyammoun         ###   ########.fr       */
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
	info->ray.lH = info->mapi.h * Y / info->ray.dst;
		
}



void	find_wall(float x, float y, t_info *info, int v)
{
	 if (v == 1)
	 {
		info->ray.prt = y;
		if (info->mapi.co_x < info->ray.wx)
			info->ray.lstw = 'W';
		else if (info->mapi.co_x > info->ray.wx)
			info->ray.lstw = 'E'; 
	}
	else if (v == 2)
	{
		info->ray.prt = x;
		if (info->mapi.co_y < info->ray.wy)
			info->ray.lstw = 'N';
		else if (info->mapi.co_y > info->ray.wy)
			info->ray.lstw = 'S'; 
	}
	/*printf("distance: %d\n", info->ray.dst);
	printf("Face: %c\n", info->ray.lstw);
	printf("pourcentage: %f\n", info->ray.prt);*/
	
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