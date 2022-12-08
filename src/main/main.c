/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:10:40 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/08 12:15:02by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	end_it(t_info *info)
{
	int	i;

	i = 0;
	mlx_clear_window(info->mlx, info->win);
	if (info->mapi.map != 0)
	{	
		while (i < info->mapi.h)
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
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 1920,
			1080, "CUB3D");
	info->img.img = mlx_new_image(info->mlx, MINIMAP * X,
			MINIMAP * Y);
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
		end_it(&info);
	if (!map_maker(&info))
		end_it(&info);
	if (!init_info(&info))
		end_it(&info);
	if (load_texture(&info))
		end_it(&info);
	init_player(&info);
	draw(&info, 0, 0);
	hooks(&info);
	mlx_loop(info.mlx);
	return (0);
}
