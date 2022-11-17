/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:10:40 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/17 12:14:11 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_info	info;

	if (!map_maker(argv, &info))
		printf("nikomok\n");
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, 1960, 1080, "CUB3D");
	draw(&info);
	mlx_loop(info.mlx);
	return (0);
}
