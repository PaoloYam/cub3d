/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:20:41 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/24 15:33:13 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->len + x
			* (img->bits / 8));
	*(unsigned int *)dst = color;
}

void	get_map_index(t_info *info, int *i, int *j, int ym, int xm)
{
	float	tmp_y;
	float	tmp_x;

	tmp_y = ((info->mapi.co_y + ym) - ((Y / 2) - (P_SIZE / 2))) / Y;
	tmp_x = ((info->mapi.co_x + xm) - ((X / 2) - (P_SIZE / 2))) / X;
	*i = tmp_y;
	*j = tmp_x;
	tmp_y = tmp_y - *i;
	tmp_x = tmp_x - *j;
	if (tmp_y > 0.5)
		*i += 1;
	if (tmp_x > 0.5)
		*j += 1;
}
