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
	while (i < (l * Y + Y))
	{
		j = c * X; 
		while (j < (c * X + X))
		{
			if (info->mapi->map[l][c] == '1')
				mlx_pixel_put(info->mlx, info->win,  j, i, 0xFFFFFF);
			else if (info->mapi->map[l][c] == '0')
				mlx_pixel_put(info->mlx, info->win,  j, i, 0xCCCCCC);	
			else if (info->mapi->map[l][c] == 'N')
				mlx_pixel_put(info->mlx, info->win,  j, i, 0x222222);		
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
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 1960, 1080, "CUB3D");
	while (++m < info->mapi->h)
	{
		i = -1;
		while (info->mapi->map[m][++i])
			draw_cube(info, m, i);
	}
	mlx_loop(info->mlx);
}