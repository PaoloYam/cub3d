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





void	draw_cube(t_info *info, int l, int c)
{
	int	i;
	int j;
		
	i = l * Y;
	while (i < (l * Y + Y - 1))
	{
		j = c * X; 
		while (j < (c * X + X - 1))
		{
			if (info->mapi.map[l][c] == '1')
				mlx_pixel_put(info->mlx, info->win,  j, i, 0x515151);
			else if (info->mapi.map[l][c] == '0')
				mlx_pixel_put(info->mlx, info->win,  j, i, 0xCCCCCC);	
			else if (l == info->mapi.pos_y && c == info->mapi.pos_x)
			{
				mlx_pixel_put(info->mlx, info->win,  l * Y + 4, c * X + 4, 0x222222);	
				mlx_pixel_put(info->mlx, info->win,  l * Y + 4, c * X + 5, 0x222222);	
				mlx_pixel_put(info->mlx, info->win,  l * Y + 5, c * X + 4, 0x222222);
				mlx_pixel_put(info->mlx, info->win,  l * Y + 5, c * X + 5, 0x222222);
			}
			++j;
		}
		i++;
	}
}

void	draw(t_info *info)
{
	int	m;
	int	i;

	m = -1;	
	while (++m < info->mapi.h)
	{
		i = 0;
		while (info->mapi.map[m][i])
		{
			draw_cube(info, m, i);
			i++;
		}
	}
}