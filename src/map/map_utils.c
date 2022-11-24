/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:20:41 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/24 21:18:22 by theophilebr      ###   ########.fr       */
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

void	get_map_index(int *i, int *j, float ym, float xm)
{
	float	tmp_y;
	float	tmp_x;

	tmp_y = ((ym) - ((Y / 2) - (P_SIZE / 2))) / Y;
	tmp_x = ((xm) - ((X / 2) - (P_SIZE / 2))) / X;
	*i = tmp_y;
	*j = tmp_x;
	tmp_y = tmp_y - *i;
	tmp_x = tmp_x - *j;
	if (tmp_y > 0.5)
		*i += 1;
	if (tmp_x > 0.5)
		*j += 1;
	printf("i : %d\n j : %d\n\n", *i, *j);
}

int	create_hit_box(t_info *info, float ym, float xm)
{
	float	center_x;
	float	center_y;
	int		i;

	center_x = info->mapi.co_x + (P_SIZE / 2);
	center_y = info->mapi.co_y + (P_SIZE / 2);
	i = 0;
	while (check_wall(info, center_y, center_x, 0))
	{
		ft_put_pixel(&info->img, center_x, center_y, 0Xd56ab3);
		center_x -= xm / 10;
		center_y -= ym / 10;
		i++;
	}
	return (1);
}