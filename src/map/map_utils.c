/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:20:41 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/05 14:38:24 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x > RES_X || y > RES_Y)
		return;
	dst = img->addr + (y * img->len + x
			* (img->bits / 8));
	*(unsigned int *)dst = color;
}

int	get_map_index(int *i, int *j, float ym, float xm)
{
	float	tmp_y;
	float	tmp_x;

	tmp_y = ((ym) - ((Y / 2) )) / Y;
	tmp_x = ((xm) - ((X / 2) )) / X;
	*i = tmp_y;
	*j = tmp_x;
	tmp_y = tmp_y - *i;
	tmp_x = tmp_x - *j;
	if (tmp_y > 0.499999)
		*i += 1;
	if (tmp_x > 0.499999)
		*j += 1;
	return (0);
	//printf("i : %d\n j : %d\n\n", *i, *j);
}

void	clear_img(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < RES_Y)
	{
		j = 0;
		while (j++ < RES_X)
			ft_put_pixel(info->imgu.img, i, j, 0x0);
		i++;
	}
}


// void	get_horiontal_line(t_info *info)
// {
// 	int	i;
// 	int	mx, my, mp, dof;
// 	float rx, ry, ra, xo, yo, a_tan;

// 	ra = info->mapi.a;
// 	i = 0;
// 	while (i < 1)
// 	{
// 		dof = 0;
// 		a_tan = -1/tan(ra);
// 		if (ra > PI)
// 		{
// 			ry = (((int)info->mapi.co_y >> 6) << 6) - 0.0001;
// 			rx = (info->mapi.co_y - ry) * a_tan + info->mapi.co_x;
// 			yo = -64;
// 			xo = -yo * a_tan;
// 		}
// 		if (ra < PI)
// 		{
// 			ry = (((int)info->mapi.co_y >> 6) << 6) + 64;
// 			rx = (info->mapi.co_y - ry) * a_tan + info->mapi.co_x;
// 			yo = 64;
// 			xo = -yo * a_tan;
// 		}
// 		if (ra == 0 || ra == PI)
// 		{
// 			rx = info->mapi.co_x;
// 			ry = info->mapi.co_y;
// 			dof = 8;
// 		}
// 		while (dof < 8)
// 		{
// 			mx = (int) (rx) >> 6;
// 			my = (int) (ry) >> 6;
// 			mp = my * X + mx;
// 			if (mp < X * Y && info->mapi.map[mp] == "1")
// 				dof = 8;
// 			else
// 			{
// 				rx += xo;
// 				ry += yo;
// 				dof += 1;
// 			}
// 		}
// 		ft_put_pixel(&info->img, rx, ry, 0Xd56ab3);
// 	}
// }

int	create_hit_box(t_info *info, float ym, float xm)
{
	int		i;
	int		j;

	get_map_index(&i, &j, ym, xm);
	if (info->mapi.map[i][j] == '1')
	{
		printf("\n\npixel haut gacuhe = wall\n");
		printf("i : %d\n j : %d\n\n", i, j);
		printf("avec coo : x : %f y : %f\n", ym, xm);
		return (0);
	}
		
	get_map_index(&i, &j, ym + P_SIZE, xm);
	if (info->mapi.map[i][j] == '1')
	{
		printf("pixelbas gauche = wall\n");
		return (0);
	}
	get_map_index(&i, &j, ym, xm + P_SIZE);
	if (info->mapi.map[i][j] == '1')
	{
		printf("pixel haut droit = wall\n");
		return (0);
	}
	get_map_index(&i, &j, ym + P_SIZE, xm + P_SIZE);
	if (info->mapi.map[i][j] == '1')
	{
		printf("pixel bas droite = wall = wall\n");
		return (0);
	}
	return (1);
}
