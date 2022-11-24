/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:17:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/24 19:50:22 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	change_position(int keycode, t_info *info)
{
	 if (keycode == 53)
	 	return (0);
	//printf("key : %d\n", keycode);
	if (keycode == 0 && check_wall(info, -info->mapi.d_y * MOUVE + info->mapi.co_y, info->mapi.d_x * MOUVE + info->mapi.co_x))
		draw(info, -info->mapi.d_y * MOUVE, info->mapi.d_x * MOUVE);
	if (keycode == 1 && check_wall(info, info->mapi.d_x * MOUVE+ info->mapi.co_x, info->mapi.d_y * MOUVE + info->mapi.co_y))
		draw(info, info->mapi.d_x * MOUVE, info->mapi.d_y * MOUVE);
	if (keycode == 2 && check_wall(info, info->mapi.d_y * MOUVE + info->mapi.co_y, -info->mapi.d_x * MOUVE + info->mapi.co_x))
		draw(info, info->mapi.d_y * MOUVE, -info->mapi.d_x * MOUVE);
	if (keycode == 13 && check_wall(info, -info->mapi.d_x * MOUVE + info->mapi.co_x, -info->mapi.d_y * MOUVE + info->mapi.co_y))
		draw(info, -info->mapi.d_x * MOUVE, -info->mapi.d_y * MOUVE);
	if (keycode == 123)
	{
		info->mapi.a -= 0.1;
		if (info->mapi.a < 0)
			info->mapi.a += 2 * PI;
		info->mapi.d_x = cos(info->mapi.a) * 5;
		info->mapi.d_y = sin(info->mapi.a) * 5;
		draw(info, 0, 0);
	}
	if (keycode == 124)
	{
		info->mapi.a += 0.1;
		if (info->mapi.a > 2 * PI)
			info->mapi.a -= 2 * PI;
		info->mapi.d_x = cos(info->mapi.a) * 5;
		info->mapi.d_y = sin(info->mapi.a) * 5;
		draw(info, 0, 0);
	}
	return (0);
}