/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:53:37 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/08 23:26:57 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	end_it(t_info *info)
{
	int	i;

	i = 0;
	if (info->init)
	{
		mlx_clear_window(info->mlx, info->win);
		mlx_destroy_image(info->mlx, info->img.img);
		mlx_destroy_image(info->mlx, info->imgu.img);
	}
	if (info->mapi.map != 0)
	{	
		while (i < info->mapi.h && i < info->map_alloc_size)
		{
			free(info->mapi.map[i]);
			i++;
		}
		free(info->mapi.map);
	}
	if ((info->texture.floor))
		free(info->texture.floor);
	if ((info->texture.ceiling))
		free(info->texture.ceiling);
	exit(1);
}

int	init_info(t_info *info)
{
	info->init = 0;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, RES_X,
			RES_Y, "CUB3D");
	info->img.img = mlx_new_image(info->mlx, MINIMAP * X,
			MINIMAP * Y);
	info->img.addr = mlx_get_data_addr(info->img.img, &info->img.bits,
			&info->img.len, &info->img.endian);
	info->imgu.img = mlx_new_image(info->mlx, RES_X, RES_Y);
	info->imgu.addr = mlx_get_data_addr(info->imgu.img, &info->imgu.bits,
			&info->imgu.len, &info->imgu.endian);
	info->wall = ft_calloc(sizeof(t_texture), 4);
	if (!info->wall)
		return (0);
	info->ray.last_prt = 10;
	info->ray.last_w = 'Z';
	info->init = 1;
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (!init_info(&info))
		end_it(&info);
	if (argc != 2)
		return (0);
	if (!load_info(&info, argv))
		end_it(&info);
	if (!map_maker(&info))
		end_it(&info);
	if (load_texture(&info))
		end_it(&info);
	init_player(&info);
	draw(&info, 0, 0);
	hooks(&info);
	mlx_loop(info.mlx);
	return (0);
}
