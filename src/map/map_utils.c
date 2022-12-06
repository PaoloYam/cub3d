/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:20:41 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/05 20:11:31 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x > RES_X || y > RES_Y)
		return;
	dst = img->addr + (y * img->len + x
			* (img->bits / 8));
	*(unsigned int *)dst = color;
}

int	get_map_index(int *i, int *j, float ym, float xm)
{
	float	tmp_y;
	float	tmp_x;

	tmp_y = ((ym) - ((Y / 2) )) / Y;
	tmp_x = ((xm) - ((X / 2) )) / X;
	*i = tmp_y;
	*j = tmp_x;
	tmp_y = tmp_y - *i;
	tmp_x = tmp_x - *j;
	if (tmp_y > 0.499999)
		*i += 1;
	if (tmp_x > 0.499999)
		*j += 1;
	return (0);
	//printf("i : %d\n j : %d\n\n", *i, *j);
}

void	clear_img(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < RES_Y)
	{
		j = 0;
		while (j++ < RES_X)
			ft_put_pixel(info->imgu.img, i, j, 0x0);
		i++;
	}
}

int	create_hit_box(t_info *info, float ym, float xm, int key)
{
	int		i;
	int		j;
	(void) key;

	get_map_index(&i, &j, ym - HIT_BOX, xm - HIT_BOX);
	if (info->mapi.map[i][j] == '1')
	{
		printf("\n\npixel haut gacuhe = wall\n");
		printf("i : %d\n j : %d\n\n", i, j);
		printf("avec coo : x : %f y : %f\n", ym, xm);
		return (0);
	}
	// else if (key == 1)
	get_map_index(&i, &j, ym + P_SIZE + HIT_BOX, xm - HIT_BOX);
	if (info->mapi.map[i][j] == '1')
	{
		printf("delta x : %f\n", info->mapi.d_x);
		printf("delta y : %f\n", info->mapi.d_y);
		printf("pixelbas gauche = wall\n");
		return (0);
	}
	get_map_index(&i, &j, ym - HIT_BOX, xm + P_SIZE + HIT_BOX);
	if (info->mapi.map[i][j] == '1')
	{
		printf("pixel haut droit = wall\n");
		return (0);
	}
	get_map_index(&i, &j, ym + P_SIZE + HIT_BOX, xm + P_SIZE + HIT_BOX);
	if (info->mapi.map[i][j] == '1')
	{
		printf("pixel bas droite = wall = wall\n");
		return (0);
	}
	return (1);
}
