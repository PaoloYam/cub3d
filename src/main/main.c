/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:10:40 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/24 20:44:04 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		return (0);
	if (!load_info(&info, argv))
		return (0);
	if (!map_maker(&info))
		return (0);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.mapi.w * X,
			info.mapi.h * Y, "CUB3D");
	info.img.img = mlx_new_image(info.mlx, info.mapi.w * X,
			info.mapi.h * Y);
	info.img.addr = mlx_get_data_addr(info.img.img, &info.img.bits,
			&info.img.len, &info.img.endian);
	init_player(&info);
	draw(&info, 0, 0);
	hooks(&info);
	mlx_loop(info.mlx);
	return (0);
}
