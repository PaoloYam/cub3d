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
	(void)hit_box;
	// if (ym > 0)
	// 	ym += P_SIZE / 1.3;
	// if (xm > 0)
	// 	xm += P_SIZE / 1.3;
	// if (ym < 0)
	// 	ym += -(P_SIZE / 3);
	// if (xm < 0)
	// 	xm += -(P_SIZE / 3);
	// if (hit_box)
	// 	if (!create_hit_box(info, ym, xm))
	// 		return (0);
	get_map_index(&i, &j, ym, xm);
	if (info->mapi.map[i][j] == '1')
	{
		//printf("WALL : %d - %d\n", i, j);
		return (0);
	}
	return (1);
}

void	draw_player(t_info *info, int xm, int ym)
{
	int	i;
	int	j;

	info->mapi.co_x += xm;
	info->mapi.co_y += ym;
	i = 0;
	while (i++ < P_SIZE)
	{
		j = 0;
		while (j++ < P_SIZE)
			ft_put_pixel(&info->img, info->mapi.co_x + j, info->mapi.co_y + i, 0x00FF0000);
	}
}

void	draw_cube(t_info *info, int l, int c)
{
	int	i;
	int	j;

	i = l * Y;
	while (i < (l * Y + Y - 1))
	{
		j = c * X;
		while (j < (c * X + X - 1))
		{
			if (info->mapi.map[l][c] == '1')
				ft_put_pixel(&info->img, j, i, 0x222222);
			if (info->mapi.map[l][c] == '0')
				ft_put_pixel(&info->img, j, i, 0xCCCCCC);
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

	i = -1;
	while (i < 1)
	{	
		new_angle_x = cos(info->mapi.a - i) * SPEED;
		new_angle_y = sin(info->mapi.a - i) * SPEED;
		center_x = info->mapi.co_x + (P_SIZE / 2);
		center_y = info->mapi.co_y + (P_SIZE / 2);
		while (check_wall(info, center_y, center_x, 0))
		{
			ft_put_pixel(&info->img, center_x, center_y, 0Xd56ab3);
			center_x -= new_angle_x / 10;
			center_y -= new_angle_y / 10;
		}
		i += 0.005;
	}
}

void	draw(t_info *info, int xm, int ym)
{
	int	m;
	int	i;

	m = -1;
	//printf("pos x: %d\n", info->mapi.pos_x);
	// printf("delta x : %f\n", info->mapi.d_x);
	// printf("delta y : %f\n", info->mapi.d_y);

	while (++m < info->mapi.h)
	{
		i = 0;
		while (info->mapi.map[m][i])
		{
			draw_cube(info, m, i);
			i++;
		}
	}
	draw_player(info, xm, ym);
	draw_direction(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}
