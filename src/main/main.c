/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:10:40 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/15 18:24:48 by tbrulhar         ###   ########.fr       */
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
	// if (!map_maker(argv, &info))
	// 	printf("nikomok\n");
	// final_map(info.mapi);
	// while (i++ < 5)
	// 	printf("%s\n", info.mapi->map[i]);
	return (0);
}
