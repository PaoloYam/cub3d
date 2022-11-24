/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:17:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/24 16:26:41 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	change_position(int keycode, t_info *info)
{
	// if (keycode == 53)
	// 	end_game(game);
	printf("keycoe : %d\n", keycode);
	if ((keycode == 0 || keycode == 123) && check_wall(info, 0, -MOUVE))
		draw(info, -MOUVE, 0);
	if ((keycode == 1 || keycode == 125) && check_wall(info, MOUVE, 0))
		draw(info, 0, MOUVE);
	if ((keycode == 2 || keycode == 124) && check_wall(info, 0, MOUVE))
		draw(info, MOUVE, 0);
	if ((keycode == 13 || keycode == 126) && check_wall(info, -MOUVE, 0))
		draw(info, 0, -MOUVE);
	return (0);
}
