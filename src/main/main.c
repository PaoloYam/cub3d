/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:10:40 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/17 16:39:27 by tbrulhar         ###   ########.fr       */
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
	info.win = mlx_new_window(info.mlx, 1960, 1080, "CUB3D");
	draw(&info);
	mlx_loop(info.mlx);
	return (0);
}
