/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:10:40 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/06 14:54:34 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	init_info(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 1920,
			1080, "CUB3D");
	info->img.img = mlx_new_image(info->mlx, info->mapi.w * X,
			info->mapi.h * Y);
	info->img.addr = mlx_get_data_addr(info->img.img, &info->img.bits,
			&info->img.len, &info->img.endian);
	info->imgu.img = mlx_new_image(info->mlx, 1920, 1080);
	info->imgu.addr = mlx_get_data_addr(info->imgu.img, &info->imgu.bits,
			&info->imgu.len, &info->imgu.endian);
	info->wall = ft_calloc(sizeof(t_texture), 4);
	if (!info->wall)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		return (0);
	if (!load_info(&info, argv))
		return (0);
	if (!map_maker(&info))
		return (0);
	if (!init_info(&info))
		return (0);
	if (load_texture(&info))
		return (0);
	init_player(&info);
	draw(&info, 0, 0);
	hooks(&info);
	mlx_loop(info.mlx);
	return (0);
}
