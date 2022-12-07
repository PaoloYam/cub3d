/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:17:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/07 18:37:33 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	change_camera(int keycode, t_info *info)
{
	if (keycode == 123)
	{
		info->mapi.a -= 0.1;
		if (info->mapi.a < 0)
			info->mapi.a += 2 * PI;
		info->mapi.d_x = cos(info->mapi.a) * SPEED;
		info->mapi.d_y = sin(info->mapi.a) * SPEED;
		draw(info, 0, 0);
	}
	if (keycode == 124)
	{
		info->mapi.a += 0.1;
		if (info->mapi.a > 2 * PI)
			info->mapi.a -= 2 * PI;
		info->mapi.d_x = cos(info->mapi.a) * SPEED;
		info->mapi.d_y = sin(info->mapi.a) * SPEED;
		draw(info, 0, 0);
	}
}

int	change_position(int keycode, t_info *info)
{
	if (keycode == 53)
		return (0);
	if (keycode == 0 && check_wall(info, -info->mapi.d_y + info->mapi.co_y,
			info->mapi.d_x + info->mapi.co_x, 1))
		draw(info, -info->mapi.d_y, info->mapi.d_x);
	if (keycode == 1 && check_wall(info, info->mapi.d_y + info->mapi.co_y,
			info->mapi.d_x + info->mapi.co_x, 2))
		draw(info, info->mapi.d_x, info->mapi.d_y);
	if (keycode == 2 && check_wall(info, info->mapi.d_y + info->mapi.co_y,
			-info->mapi.d_x + info->mapi.co_x, 3))
		draw(info, info->mapi.d_y, -info->mapi.d_x);
	if (keycode == 13 && check_wall(info, -info->mapi.d_y + info->mapi.co_y,
			-info->mapi.d_x + info->mapi.co_x, 4))
		draw(info, -info->mapi.d_x, -info->mapi.d_y);
	change_camera(keycode, info);
	return (0);
}
