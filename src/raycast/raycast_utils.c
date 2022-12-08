/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:45:01 by pyammoun          #+#    #+#             */
/*   Updated: 2022/12/08 22:27:54 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	colorita(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	color_int(char **split, int v, t_info *info)
{		
	if (v == 1)
	{
		info->texture.ceiling_int = colorita(ft_atoi(split[0]),
				ft_atoi(split[1]), ft_atoi(split[2]));
	}
	if (v == 2)
	{
		info->texture.floor_int = colorita(ft_atoi(split[0]),
				ft_atoi(split[1]), ft_atoi(split[2]));
	}	
}

int	get_pixel_color(t_info *info, int i, int x, int y)
{
	unsigned int	color;

	color = 0;
	if ((0 <= x && x <= info->wall[i].width)
		&& (0 <= y && y <= info->wall[i].heigth))
		color = info->wall[i].addr[y * info->wall[i].len / 4 + x];
	return (color);
}
