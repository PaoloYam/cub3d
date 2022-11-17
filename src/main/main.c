/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:10:40 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/17 15:45:55 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	main(int argc, char **argv)
{
	(void)argc;
	t_info	info;
	int	i;

	i = 0;
	if (!load_info(&info, argv))
		printf("nikomoke\n");
	if (!map_maker(argv, &info))
		printf("nikomok\n");
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, 1960, 1080, "CUB3D");
	draw(&info);
	mlx_loop(info.mlx);
	return (0);
}
