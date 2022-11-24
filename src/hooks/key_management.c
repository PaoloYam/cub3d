/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:17:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/24 16:07:16 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

// int	check_wall(t_info *info)
// {
// 	// int	i;
// 	// int	j;

// 	// i = (info->mapi.co_y - ((Y / 2) - (P_SIZE / 2)) / Y);
// 	// j = (info->mapi.co_x - ((X / 2) - (P_SIZE / 2)));
// 	// if (info->mapi.map[i][j] == '1')
// 	// 	return (0);
// 	// //printf("coo : %f %f\n", (info->mapi.co_x - ((X / 2))) / X, (info->mapi.co_y - ((Y / 2) - (P_SIZE / 2))) / Y);
// 	// return (0);
// }

int	change_position(int keycode, t_info *info)
{
	// if (keycode == 53)
	// 	end_game(game);
	//check_wall(info);
	if (keycode == 0)
		draw(info, -MOUVE, 0);
	if (keycode == 1 || keycode == 125)
		draw(info, 0, MOUVE);
	if (keycode == 2)
		draw(info, MOUVE, 0);
	if (keycode == 13 || keycode == 126)
		draw(info, 0, -MOUVE);
	return (0);
}

int	move_camera(int keycode, t_info *info)
{
	
	if (keycode == 123)
	{
		info->mapi.a -= 0.1;	
		if (info->mapi.a < 0)
			info->mapi.a += 2 * PI;
		info->mapi.d_x = cos(info->mapi.a) * 5;
		info->mapi.d_y = cos(info->mapi.a) * 5;
		printf("%f\n", info->mapi.a);
	}
	if (keycode == 124)
	{
		info->mapi.a += 0.1;	
		if (info->mapi.a > 2 * PI)
			info->mapi.a -= 2 * PI;
		info->mapi.d_x = cos(info->mapi.a) * 5;
		info->mapi.d_y = cos(info->mapi.a) * 5;		
		printf("%f\n", info->mapi.a);
	}
	return (0);
}