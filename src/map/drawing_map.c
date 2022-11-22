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

void	ft_put_pixel(t_info *info, int x, int y, int color)
{
	char	*dst;

	dst = info->img.addr + (y * info->img.len + x
			* (info->img.bits / 8));
	*(unsigned int *)dst = color;
}

void	draw_cube(t_info *info, int l, int c, int xm, int ym)
{
	int	i;
	int	j;
	static int x = 0;
	static int y = 0;

	i = l * Y;
	while (i < (l * Y + Y - 1))
	{
		j = c * X;
		while (j < (c * X + X - 1))
		{
			if (info->mapi.map[l][c] == '1')
				ft_put_pixel(info, j, i, 0x222222);
			if (info->mapi.map[l][c] == '0')
				ft_put_pixel(info, j, i, 0xCCCCCC);
			++j;
		}
		i++;
	}
	if (l == info->mapi.pos_y && c == info->mapi.pos_x)
	{	
		x += xm;
		y += ym;
		printf("slaut\n");
		ft_put_pixel(info, (c * X) + (X / 2 + x), (l * Y) + (Y / 2 + y), 0x00FF0000);
		ft_put_pixel(info, (c * X) + (X / 2 + x) + 1, (l * Y) + (Y / 2 + y), 0x00FF0000);
		ft_put_pixel(info, (c * X) + (X / 2 + x), (l * Y) + (Y / 2 + y) + 1, 0x00FF0000);
		ft_put_pixel(info,(c * X) + (X / 2 + x) + 1, (l * Y) + (Y / 2 + y) + 1, 0x00FF0000);
		printf("x : %d\n", (c * X) + (X / 2 + x));
		printf("y : %d\n", (l * Y) + (Y / 2 + y));
		
	}
}

void	draw(t_info *info, int xm, int ym)
{
	int	m;
	int	i;

	m = -1;
	printf("pos x: %d\n", info->mapi.pos_x);
	while (++m < info->mapi.h)
	{
		i = 0;
		while (info->mapi.map[m][i])
		{
			draw_cube(info, m, i, xm, ym);
			i++;
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}
