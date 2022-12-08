/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:08:56 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/08 21:57:08 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	hooks(t_info *info)
{
	mlx_hook(info->win, 2, 1L << 1, change_position, info);
	mlx_hook(info->win, 17, 0, end_it, info);
}

void	init_player(t_info *info)
{
	if (info->mapi.P == 'N')
		info->mapi.a = PI / 2;
	else if (info->mapi.P == 'W')
		info->mapi.a = 2 * PI;
	else if (info->mapi.P == 'E')
		info->mapi.a = PI;
	else if (info->mapi.P == 'S')
		info->mapi.a = 3 * PI / 2;
	info->mapi.d_x = cos(info->mapi.a * 5);
	info->mapi.d_y = sin(info->mapi.a * 5);
}
