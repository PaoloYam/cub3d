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

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->len + x
			* (img->bits / 8));
	*(unsigned int *)dst = color;
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

void	draw(t_info *info, int xm, int ym)
{
	int	m;
	int	i;

	m = -1;
	//printf("pos x: %d\n", info->mapi.pos_x);
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
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}
