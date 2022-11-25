/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:17:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/25 16:16:57 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	change_position(int keycode, t_info *info)
{
	 if (keycode == 53)
	 	return (0);
	//printf("key : %d\n", keycode);
	if (keycode == 0 && check_wall(info, -info->mapi.d_y + info->mapi.co_y, info->mapi.d_x+ info->mapi.co_x, 1))
		draw(info, -info->mapi.d_y, info->mapi.d_x);
	if (keycode == 1 && check_wall(info, info->mapi.d_y + info->mapi.co_y, info->mapi.d_x+ info->mapi.co_x, 1))
		draw(info, info->mapi.d_x, info->mapi.d_y);
	if (keycode == 2 && check_wall(info, info->mapi.d_x + info->mapi.co_y, -info->mapi.d_x+ info->mapi.co_x + 0.1, 1))
		draw(info, info->mapi.d_y, -info->mapi.d_x);
	if (keycode == 13 && check_wall(info, -info->mapi.d_y + info->mapi.co_y, -info->mapi.d_x + info->mapi.co_x, 1))
		draw(info, -info->mapi.d_x, -info->mapi.d_y);
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
	return (0);
}
