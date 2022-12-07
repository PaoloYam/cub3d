/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:00:53 by pyammoun          #+#    #+#             */
/*   Updated: 2022/12/07 17:45:53 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	draw_player(t_info *info, int xm, int ym)
{
	int		i;
	int		j;
	float	center_x;
	float	center_y;

	info->mapi.co_x += xm;
	info->mapi.co_y += ym;
	i = 0;
	while (i++ < P_SIZE)
	{
		j = 0;
		while (j++ < P_SIZE)
			ft_put_pixel(&info->img, MINIMAP / 2 * X + j,
				MINIMAP / 2 * Y + i, 0x00FF0000);
	}
	center_x = MINIMAP / 2 * X + (P_SIZE / 2);
	center_y = MINIMAP / 2 * X + (P_SIZE / 2);
	i = 0;
	while (i < 100)
	{
		ft_put_pixel(&info->img, center_x, center_y, 0x00FF0000);
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

void	set_up_image(t_info *info)
{	
	draw_direction(info);
	mlx_put_image_to_window(info->mlx, info->win, info->imgu.img, 0, 0);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
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
	y -= (MINIMAP / 2);
	x -= (MINIMAP / 2);
	while (++i < MINIMAP)
	{
		j = -1;
		if ((y + i) >= 0 && (y + i) < info->mapi.h)
		{
			while (++j < MINIMAP)
				if ((x + j) >= 0 && (x + j) <= info->mapi.w)
					draw_cube(info, i, j, i + y, j + x);
		}	
	}
	clear_img(info);
	draw_player(info, xm, ym);
	set_up_image(info);
}
