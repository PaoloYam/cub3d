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
		
	i = l * 8;
	while (i < (l * 8 + Y))
	{
		j = c * 8;
		while (j < (c * 8 + X))
		{
			if (info->mapi->map[l][c] == '1')
				mlx_pixel_put(info->mlx, info->win,  j++, i, 0xFFFFFF);
			if (info->mapi->map[l][c] == '0')
				mlx_pixel_put(info->mlx, info->win,  j++, i, 0xCCCCCC);	
			if (info->mapi->map[l][c] == 'N')
				mlx_pixel_put(info->mlx, info->win,  j++, i, 0x222222);		
			++i;
		}
	}
}





void	draw(t_info *info)
{
	int	m;
	int	i;

	m = -1;
	while (++m < info->mapi->h)
	{
		i = -1;
		while (info->mapi->map[m][++i])	
		{
			draw_cube(info, m, i);
		}
	}
}