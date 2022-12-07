/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:45:01 by pyammoun          #+#    #+#             */
/*   Updated: 2022/12/07 16:30:53 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	get_pixel_color(t_info *info, int i, int x, int y)
{
	unsigned int	color;

	color = 0;
	if ((0 <= x && x <= info->wall[i].width)
		&& (0 <= y && y <= info->wall[i].heigth))
		color = info->wall[i].addr[y * info->wall[i].len / 4 + x];
	return (color);
}
