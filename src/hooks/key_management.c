/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:17:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/22 23:00:57 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	change_position(int keycode, t_info *info)
{
	printf("kezcode : %d\n", keycode);
	// if (keycode == 53)
	// 	end_game(game);
	info->key.x = 0;
	info->key.many = 0;
	info->key.y = 0;
	
	if (keycode == 0 || keycode == 123)
	{
		info->key.x = -10;
		info->key.many += 1;
	}
	if (keycode == 1 || keycode == 125)
	{
		info->key.y = 10;
		info->key.many += -1;
	}	
	if (keycode == 2 || keycode == 124)
	{
		info->key.x = 10;
		info->key.many += 1;
	}
	if (keycode == 13 || keycode == 126)
	{
		info->key.y = -10;
		info->key.many += -1;
	}
		
	if (info->key.x || info->key.y)
	{	
		if (!info->key.many)
		{
			printf("on est dans many\n");
			draw(info, info->key.x, info->key.y);
		}
			
		else
			draw(info, info->key.x, info->key.y);
	}
	return (0);
}