/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:45:01 by pyammoun          #+#    #+#             */
/*   Updated: 2022/12/06 20:17:21 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	get_pixel_color(t_info *info, int i, int x, int y)
{
	unsigned int	color;

	color = 0;
	// printf("x : %d\n", x);
	// printf("y : %d\n", y);
	// printf("wall width : %d\n", info->wall[i].width);
	// printf("wall height : %d\n", info->wall[i].heigth);

	if ((0 <= x && x <= info->wall[i].width)
		&& (0 <= y && y <= info->wall[i].heigth))
		color = info->wall[i].addr[y * info->wall[i].len / 4 + x];
	return (color);
}
