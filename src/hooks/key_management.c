/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:17:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/22 19:55:30 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	change_position(int keycode, t_info *info)
{
	printf("kezcode : %d\n", keycode);
	// if (keycode == 53)
	// 	end_game(game);
	if (keycode == 0)
	{
		draw(info, -5, 0);
	}
	if (keycode == 1)
	{
		draw(info, 0, 5);
	}
	if (keycode == 2)
	{
		draw(info, 5, 0);
	}
	if (keycode == 13)
	{
		printf("on appuie\n");
		draw(info, 0, -5);
	}
	return (0);
}