/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:17:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/24 14:24:55 by tbrulhar         ###   ########.fr       */
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
	if (keycode == 0 || keycode == 123)
		draw(info, -MOUVE, 0);
	if (keycode == 1 || keycode == 125)
		draw(info, 0, MOUVE);
	if (keycode == 2 || keycode == 124)
		draw(info, MOUVE, 0);
	if (keycode == 13 || keycode == 126)
		draw(info, 0, -MOUVE);
	return (0);
}
