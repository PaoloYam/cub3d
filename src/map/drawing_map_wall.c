/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:44:41 by pyammoun          #+#    #+#             */
/*   Updated: 2022/12/08 22:49:38 by pyammoun         ###   ########.fr       */
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
		info->side = side;
		return (0);
	}
	info->mapi.map[i][j] = '2';
	return (1);
}

void	wally(t_info *info)
{
	while (check_wall(info, info->ray.wy, info->ray.wx, 0))
	{
		if (check_wall(info, info->ray.wy - info->ray.nay / 50,
				info->ray.wx - info->ray.nax / 50, 0) == 0)
		{
			info->ray.wx -= info->ray.nax / 500;
			info->ray.wy -= info->ray.nay / 500;
		}
		else
		{
			info->ray.wx -= info->ray.nax / 50;
			info->ray.wy -= info->ray.nay / 50;
		}
	}
}

void	draw_direction(t_info *info)
{
	float	i;

	i = 0;
	info->ray.num = 0;
	while (info->ray.num < RES_X)
	{	
		i = info->ray.num / 1920.0 * (-0.96) + 0.48;
		info->ray.nax = cos(info->mapi.a - i) * SPEED;
		info->ray.ray_ang = info->mapi.a - i;
		if (info->ray.ray_ang > 2 * PI)
			info->ray.ray_ang -= 2 * PI;
		if (info->ray.ray_ang < 0)
			info->ray.ray_ang += 2 * PI;
		info->ray.nay = sin(info->mapi.a - i) * SPEED;
		info->ray.wx = info->mapi.co_x + (P_SIZE / 2);
		info->ray.wy = info->mapi.co_y + (P_SIZE / 2);
		wally(info);
		info->ray.dst = sqrt((info->mapi.co_x - info->ray.wx)
				* (info->mapi.co_x - info->ray.wx)
				+ (info->mapi.co_y - info->ray.wy)
				* (info->mapi.co_y - info->ray.wy));
		wall_face(info->ray.wx / X, info->ray.wy / Y, info);
		info->ray.num += 2;
	}
}
