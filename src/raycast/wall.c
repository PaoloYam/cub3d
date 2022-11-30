/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:07:14 by pyammoun          #+#    #+#             */
/*   Updated: 2022/11/30 15:16:46 by pyammoun         ###   ########.fr       */
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


void	find_wall(float x, float y, t_info *info, int v)
{
	 if (v == 1)
	 {
		info->mapi.prt = y;
		if (info->mapi.co_x < info->mapi.wx)
			info->mapi.lstw = 'W';
		else if (info->mapi.co_x > info->mapi.wx)
			info->mapi.lstw = 'E'; 
	}
	else if (v == 2)
	{
		info->mapi.prt = x;
		if (info->mapi.co_y < info->mapi.wy)
			info->mapi.lstw = 'N';
		else if (info->mapi.co_y > info->mapi.wy)
			info->mapi.lstw = 'S'; 
	}
	printf("la: %c\n", info->mapi.lstw);
}


void	wall_face(float x, float y, t_info *info)
{
	int		xi;
	int		yi;
	
	xi = x;
	yi = y;
	x = x - xi;
	y = y - yi;
	printf("calcul x: %f & y: %f\n", x, y);
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